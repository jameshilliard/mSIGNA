# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

ACLOCAL_AMFLAGS = -I build-aux/m4
SUBDIRS = deps/logger deps/Signals deps/stdutils deps/sysutils deps/CoinCore deps/CoinQ deps/CoinDB src
.PHONY: deploy FORCE

GZIP_ENV="-9n"
export PYTHONPATH

BITCOIND_BIN=$(top_builddir)/src/$(BITCOIN_DAEMON_NAME)$(EXEEXT)
BITCOIN_WIN_INSTALLER=$(PACKAGE)-$(PACKAGE_VERSION)-win$(WINDOWS_BITS)-setup$(EXEEXT)

empty :=
space := $(empty) $(empty)

$(BITCOIND_BIN): FORCE
	$(MAKE) -C src $(@F)

baseline.info:
	$(LCOV) -c -i -d $(abs_builddir)/src -o $@

baseline_filtered.info: baseline.info
	$(abs_builddir)/contrib/filter-lcov.py $(LCOV_FILTER_PATTERN) $< $@
	$(LCOV) -a $@ $(LCOV_OPTS) -o $@

cov: test_bitcoin.coverage/.dirstamp total.coverage/.dirstamp

dist_noinst_SCRIPTS = autogen.sh
