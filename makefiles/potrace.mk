ifneq ($(PROCURSUS),1)
$(error Use the main Makefile)
endif

SUBPROJECTS   += potrace
POTRACE_VERSION := 1.16
DEB_POTRACE_V   ?= $(POTRACE_VERSION)

potrace-setup: setup
	$(call DOWNLOAD_FILES,$(BUILD_SOURCE),https://potrace.sourceforge.net/download/$(POTRACE_VERSION)/potrace-$(POTRACE_VERSION).tar.gz)
	$(call EXTRACT_TAR,potrace-$(POTRACE_VERSION).tar.gz,potrace-$(POTRACE_VERSION),potrace)

ifneq ($(wildcard $(BUILD_WORK)/potrace/.build_complete),)
potrace:
	@echo "Using previously built potrace."
else
potrace: potrace-setup
	cd $(BUILD_WORK)/potrace && ./configure -C \
	CFLAGS="$(patsubst -flto=thin,,$(CFLAGS))" \
	LDFLAGS="$(patsubst -flto=thin,,$(LDFLAGS))" \
		$(DEFAULT_CONFIGURE_FLAGS) --with-libpotrace
	+$(MAKE) -C $(BUILD_WORK)/potrace
	+$(MAKE) -C $(BUILD_WORK)/potrace install \
		DESTDIR=$(BUILD_STAGE)/potrace
	$(call AFTER_BUILD,copy)
endif

potrace-package: potrace-stage
	# potrace.mk Package Structure
	rm -rf $(BUILD_DIST)/potrace

	# potrace.mk Prep potrace
	cp -a $(BUILD_STAGE)/potrace $(BUILD_DIST)

	# potrace.mk Sign
	$(call SIGN,potrace,general.xml)

	# potrace.mk Make .debs
	$(call PACK,potrace,DEB_POTRACE_V)

	# potrace.mk Build cleanup
	rm -rf $(BUILD_DIST)/potrace

.PHONY: potrace potrace-package
