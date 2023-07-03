ifneq ($(PROCURSUS),1)
$(error Use the main Makefile)
endif

SUBPROJECTS     += plutil
PLUTIL_VERSION  := 0.2.2
DEB_PLUTIL_V    ?= $(PLUTIL_VERSION)+2

plutil: private CC += $(LDFLAGS) $(if $(findstring roothide,$(MEMO_TARGET)),-lroothide)

plutil-setup: setup
	$(call DOWNLOAD_FILES,$(BUILD_SOURCE),https://github.com/Diatrus/plutil/releases/download/v$(PLUTIL_VERSION)/plutil-$(PLUTIL_VERSION).tar.xz)
	$(call EXTRACT_TAR,plutil-$(PLUTIL_VERSION).tar.xz,plutil-$(PLUTIL_VERSION),plutil)
ifneq (,$(findstring roothide,$(MEMO_TARGET)))
	$(call DO_PATCH,roothide.plutil,plutil,-p1)
endif

ifneq ($(wildcard $(BUILD_WORK)/plutil/.build_complete),)
plutil:
	@echo "Using previously built plutil."
else
plutil: plutil-setup
	+$(MAKE) -C $(BUILD_WORK)/plutil install \
		CC="$(CC)" \
		DESTDIR="$(BUILD_STAGE)/plutil/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)"
	$(call AFTER_BUILD,,,,novroot)
endif

plutil-package: plutil-stage
	# plutil.mk Package Structure
	rm -rf $(BUILD_DIST)/plutil

	# plutil.mk Prep plutil
	cp -a $(BUILD_STAGE)/plutil $(BUILD_DIST)/plutil

	# plutil.mk Sign
	$(call SIGN,plutil,general.xml)

	# plutil.mk Make .debs
	$(call PACK,plutil,DEB_PLUTIL_V)

	# plutil.mk Build cleanup
	rm -rf $(BUILD_DIST)/plutil

.PHONY: plutil plutil-package
