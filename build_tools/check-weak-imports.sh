#!/bin/bash
# check-weak-imports.sh -- list two-level weak undefined imports and their
# provider libraries found in build products, for human review.
#
# Background: availability-gated symbols (e.g. strchrnul from a newer SDK) get
# compiled as `weak external _sym (from libSystem)`. When the symbol is absent on
# the target device they bind to NULL, and an UNGUARDED call jumps to pc=0 and
# crashes on first use.
#
# Important limitation (do NOT treat as a hard gate): the same shape can be
# LEGITIMATE -- e.g. referencing a symbol added/removed in another OS version but
# calling it behind an if(@available)/if(&sym) guard. The guard lives in the code,
# not in the symbol table, so this script CANNOT distinguish a real (unguarded)
# bug from a guarded legitimate use. Use it as a triage tool: review the
# candidates and, if a symbol is a confirmed-legit (guarded) weak import, add it
# to ALLOW_LIST below.
#
# Automatically ignored: -undefined dynamic_lookup / -flat_namespace symbols
# (they appear as `external ... (dynamically looked up)`, not this problem).
#
# Usage:     build_tools/check-weak-imports.sh [dir ...]   (default: build_stage)
# Examples:  build_tools/check-weak-imports.sh build_stage/iphoneos-arm64-roothide/1900/dash
#            build_tools/check-weak-imports.sh build_stage/<target>/<cfver>/{bash,dpkg,...}
# Exit code: 0 = nothing to review, non-zero = candidates need human review
set -u
ROOTS=("$@"); [ "${#ROOTS[@]}" -eq 0 ] && ROOTS=("build_stage")
printf '🔎  weak-import check — scanning %d dir(s)\n' "${#ROOTS[@]}"

# Allowlist of always-legitimate weak imports, one anchored full-symbol regex per
# line. Add a confirmed-legit (guarded) symbol here to stop it being reported.
ALLOW_LIST=(
	'__swift_FORCE_LOAD_.*'         # Swift runtime autolink
	'__availability_version_check'  # clang availability runtime helper
)
ALLOW=$(IFS='|'; printf '%s' "${ALLOW_LIST[*]}")

fail=0; nbad=0; nscan=0
for ROOT in "${ROOTS[@]}"; do
	label=$(basename "$ROOT")
	while IFS= read -r -d '' f; do
		case "$(file -b "$f" 2>/dev/null)" in *Mach-O*) ;; *) continue;; esac
		nscan=$((nscan + 1))
		# Only: undefined + weak external + two-level "(from <lib>)", excluding dynamic_lookup
		syms=$(nm -m "$f" 2>/dev/null \
			| awk '/undefined/ && /weak external/ && /\(from / && !/dynamically looked up/ {
				match($0, /\(from [^)]*\)/)
				provider = substr($0, RSTART, RLENGTH)
				for (i=1;i<=NF;i++) if ($i ~ /^_/) print $i " " provider
			}' \
			| sort -u | grep -vE "^(${ALLOW})[[:space:]]")
		[ -z "$syms" ] && continue
		echo "⚠️  $label/${f#"$ROOT"/}"
		echo "$syms" | sed 's/^/        ↳ /'
		nbad=$((nbad + 1)); fail=1
	done < <(find "$ROOT" -type f -print0 2>/dev/null)
done

echo "────────────────────────────────────────────────────"
if [ "$fail" -eq 0 ]; then
	echo "✅  weak-import check — OK (scanned $nscan Mach-O, nothing to review)"
else
	echo "⚠️  weak-import check — $nbad of $nscan Mach-O have two-level weak imports"
	echo "    Confirm each call site is guarded; add confirmed-legit symbols to"
	echo "    ALLOW_LIST in this script. Unguarded ones are real bugs (pc=0 at runtime)."
fi
exit $fail
