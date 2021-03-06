#
# Broadcom web pages
#
# Copyright (C) 2011, Broadcom Corporation. All Rights Reserved.
# 
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
# SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
# OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
# CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
# $Id: Makefile 334430 2012-05-22 08:21:57Z $
#

all: pages.mk

ifneq ($(WIND_HOST_TYPE),x86-win32)
ifdef BCM_NETBSD
# NetBSD
CONFIG_NAT=y
else
# Linux
$(SRCBASE)/router/.config:
	cp $(SRCBASE)/router/config/defconfig $@

include $(SRCBASE)/router/.config
endif
else
# VxWorks compiled on Windows host
CONFIG_WPS=y
endif

PAGES := blur_new.jpg logo_new.gif repeat_edge_new.gif overlib.js style.css
PAGES += index.asp basic.gif
PAGES += lan.asp lan.gif
ifeq ($(CONFIG_NAT),y)
PAGES += wan.asp wan.gif
endif
PAGES += status.asp status.gif
ifeq ($(CONFIG_NAT),y)
PAGES += filter.asp filter.gif
PAGES += forward.asp forward.gif
endif
ifneq ($(CONFIG_SAMBA)$(CONFIG_CIFS)$(CONFIG_DLNA_DMS)$(CONFIG_DLNA_DMR),)
PAGES += storage.asp storage.gif
endif
PAGES += ssid.asp ssid.gif
PAGES += radio.asp radio.gif
PAGES += security.asp security.gif
ifeq ($(CONFIG_WPS),y)
PAGES += wps.asp wps.gif
endif
PAGES += firmware.asp firmware.gif
ifneq ($(NO_BCMINTERNAL), 1)
PAGES += internal.asp internal.gif
endif
ifeq ($(CONFIG_BCMQOS),y)
PAGES += qos.asp qos.gif
endif

ifeq ($(CONFIG_WAPI_IAS),y)
PAGES += as.asp as.gif
endif

ifeq ($(CONFIG_WFI),y)
PAGES += cancelinvite.asp
endif

ifeq ($(CONFIG_PLC),y)
PAGES += plc.asp plc.gif
endif


ifeq ($(CONFIG_MEDIA_IPTV),y)
PAGES += media.asp media.gif
endif



ifneq ($(WIND_HOST_TYPE),x86-win32)
ifdef BCM_NETBSD
pages.mk:
	echo PAGES := $(PAGES) > $@
else
# Linux
pages.mk: $(SRCBASE)/router/.config
	echo "PAGES := $(PAGES)" > $@
endif
else
# VxWorks
pages.mk:
	echo PAGES := $(PAGES) > $@
endif

install:
	install -d $(INSTALLDIR)/www
	install -m 644 $(PAGES) $(INSTALLDIR)/www

clean:
	rm -f pages.mk
