ifneq ($(PROCURSUS),1)
$(error Use the main Makefile)
endif

SUBPROJECTS   += zziplib
ZZIPLIB_VERSION := 0.13.78
DEB_ZZIPLIB_V   ?= $(ZZIPLIB_VERSION)

zziplib-setup: setup
	$(call GITHUB_ARCHIVE,gdraheim,zziplib,$(ZZIPLIB_VERSION),refs/tags/v$(ZZIPLIB_VERSION))
	$(call EXTRACT_TAR,zziplib-$(ZZIPLIB_VERSION).tar.gz,zziplib-$(ZZIPLIB_VERSION),zziplib)
	mkdir -p $(BUILD_WORK)/zziplib/build

ifneq ($(wildcard $(BUILD_WORK)/zziplib/.build_complete),)
zziplib:
	@echo "Using previously built zziplib."
else
zziplib: zziplib-setup
	cd $(BUILD_WORK)/zziplib/build && cmake \
		$(DEFAULT_CMAKE_FLAGS) -DZZIPTEST=OFF \
		..
	+$(MAKE) -C $(BUILD_WORK)/zziplib/build
	+$(MAKE) -C $(BUILD_WORK)/zziplib/build install \
		DESTDIR="$(BUILD_STAGE)/zziplib"
	$(call AFTER_BUILD,copy)
endif

zziplib-package: zziplib-stage
	# zziplib.mk Package Structure
	rm -rf $(BUILD_DIST)/zziplib

	# zziplib.mk Prep zziplib
	cp -a $(BUILD_STAGE)/zziplib $(BUILD_DIST)

	# zziplib.mk Sign
	$(call SIGN,zziplib,general.xml)

	# zziplib.mk Make .debs
	$(call PACK,zziplib,DEB_ZZIPLIB_V)

	# zziplib.mk Build cleanup
	rm -rf $(BUILD_DIST)/zziplib

.PHONY: zziplib zziplib-package
