ifneq ($(PROCURSUS),1)
$(error Use the main Makefile)
endif

SUBPROJECTS      += usbutils
USBUTILS_VERSION := 014
DEB_USBUTILS_V   ?= $(USBUTILS_VERSION)

usbutils-setup: setup
	$(call DOWNLOAD_FILES,$(BUILD_SOURCE),https://www.kernel.org/pub/linux/utils/usb/usbutils/usbutils-$(USBUTILS_VERSION).tar.xz)
	$(call EXTRACT_TAR,usbutils-$(USBUTILS_VERSION).tar.xz,usbutils-$(USBUTILS_VERSION),usbutils)
	$(call DO_PATCH,usbutils,usbutils,-p1)

ifneq ($(wildcard $(BUILD_WORK)/usbutils/.build_complete),)
usbutils:
	@echo "Using previously built usbutils."
else
usbutils: usbutils-setup libusb
	cd $(BUILD_WORK)/usbutils && autoreconf -fi
	cd $(BUILD_WORK)/usbutils && ./configure \
		$(DEFAULT_CONFIGURE_FLAGS)
	+$(MAKE) -C $(BUILD_WORK)/usbutils install \
		DESTDIR="$(BUILD_STAGE)/usbutils"
	rm -f $(BUILD_STAGE)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share/usb.ids{,.gz}
	$(call DOWNLOAD_FILES,$(BUILD_STAGE)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share,http://www.linux-usb.org/usb.ids{$(comma).gz})
	$(call AFTER_BUILD)
endif

usbutils-package: DEB_USBIDS_V=$(shell grep Version: $(BUILD_STAGE)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share/usb.ids | cut -d' ' -f3 )
usbutils-package: usbutils-stage
	# usbutils.mk Package Structure
	rm -rf $(BUILD_DIST)/usb{utils,.ids}
	mkdir -p $(BUILD_DIST)/usb.ids/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share \
		$(BUILD_DIST)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share

	# usbutils.mk Prep usb.ids
	cp -a $(BUILD_STAGE)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share/usb.ids{,.gz} $(BUILD_DIST)/usb.ids/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share

	# usbutils.mk Prep usbutils
	cp -a $(BUILD_STAGE)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/bin $(BUILD_DIST)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)
	cp -a $(BUILD_STAGE)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share/man $(BUILD_DIST)/usbutils/$(MEMO_PREFIX)$(MEMO_SUB_PREFIX)/share

	# usbutils.mk Sign
	$(call SIGN,usbutils,usb.xml)

	# usbutils.mk Make .debs
	$(call PACK,usb.ids,DEB_USBIDS_V)
	$(call PACK,usbutils,DEB_USBUTILS_V)

	# usbutils.mk Build cleanup
	rm -rf $(BUILD_DIST)/usb{utils,.ids}

.PHONY: usbutils usbutils-package
