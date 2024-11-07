ifneq ($(PROCURSUS),1)
$(error Use the main Makefile)
endif

SUBPROJECTS   += libmpfi
LIBMPFI_VERSION := 1.5.3
DEB_LIBMPFI_V   ?= $(LIBMPFI_VERSION)

ifneq ($(wildcard $(BUILD_WORK)/libmpfi/.CRLFtoLF_done),)
libmpfi-setup: setup
	@echo "libmpfi already converted to LF. "
else
libmpfi-setup: setup
	$(call GIT_CLONE,https://gitlab.inria.fr/mpfi/mpfi.git,master,libmpfi)
	find $(BUILD_WORK)/libmpfi \( ! -regex '.*/\..*' \) -type f -exec dos2unix -f {} \;
	touch $(BUILD_WORK)/libmpfi/.CRLFtoLF_done
endif

ifneq ($(wildcard $(BUILD_WORK)/libmpfi/.build_complete),)
libmpfi:
	@echo "Using previously built libmpfi."
else
libmpfi: libmpfi-setup libgmp10 mpfr4
	cd $(BUILD_WORK)/libmpfi && ./autogen.sh && ./configure -C \
		$(DEFAULT_CONFIGURE_FLAGS)
	+$(MAKE) -C $(BUILD_WORK)/libmpfi
	+$(MAKE) -C $(BUILD_WORK)/libmpfi install \
		DESTDIR=$(BUILD_STAGE)/libmpfi
	$(call AFTER_BUILD,copy)
endif

libmpfi-package: libmpfi-stage
	# libmpfi.mk Package Structure
	rm -rf $(BUILD_DIST)/libmpfi-dev

	# libmpfi.mk Prep libmpfi-dev
	cp -a $(BUILD_STAGE)/libmpfi $(BUILD_DIST)
	mv $(BUILD_DIST)/libmpfi $(BUILD_DIST)/libmpfi-dev

	# libmpfi.mk Sign
	$(call SIGN,libmpfi-dev,general.xml)

	# libmpfi.mk Make .debs
	$(call PACK,libmpfi-dev,DEB_LIBMPFI_V)

	# libmpfi.mk Build cleanup
	rm -rf $(BUILD_DIST)/libmpfi-dev

.PHONY: libmpfi libmpfi-package
