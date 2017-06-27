# Copyright (c) 2013-2016 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

bin_PROGRAMS = msigna-qt
EXTRA_LIBRARIES = libmsignaqt.a

QT_FORMS_UI = \
  acceptlicensedialog.ui \
  requestpaymentdialog.ui

QT_MOC_CPP = \
  settings.cpp \
  filesystem.cpp \
  versioninfo.cpp \
  copyrightinfo.cpp \
  stylesheets.cpp \
  aboutdialog.cpp \
  coinparams.cpp \
  docdir.cpp \
  entropysource.cpp \
  main.cpp \
  currencyunitdialog.cpp \
  networkselectiondialog.cpp \
  splashscreen.cpp \
  acceptlicensedialog.cpp \
  mainwindow.cpp \
  commandserver.cpp \
  paymentrequest.cpp \
  numberformats.cpp \
  currencyvalidator.cpp \
  hexvalidator.cpp \
  accountmodel.cpp \
  accountview.cpp \
  keychainmodel.cpp \
  keychainview.cpp \
  entropydialog.cpp \
  quicknewaccountdialog.cpp \
  newaccountdialog.cpp \
  newkeychaindialog.cpp \
  txsearchdialog.cpp \
  rawtxdialog.cpp \
  createtxdialog.cpp \
  unspenttxoutmodel.cpp \
  unspenttxoutview.cpp \
  txmodel.cpp \
  txview.cpp \
  accounthistorydialog.cpp \
  txactions.cpp \
  scriptmodel.cpp \
  scriptview.cpp \
  scriptdialog.cpp \
  signaturemodel.cpp \
  signatureview.cpp \
  signaturedialog.cpp \
  signatureactions.cpp \
  requestpaymentdialog.cpp \
  networksettingsdialog.cpp \
  wordlistvalidator.cpp \
  keychainbackupwizard.cpp \
  keychainbackupdialog.cpp \
  viewbip32dialog.cpp \
  importbip32dialog.cpp \
  viewbip39dialog.cpp \
  importbip39dialog.cpp \
  passphrasedialog.cpp \
  setpassphrasedialog.cpp

QT_QRC = ../images/mSIGNA.qrc

BITCOIN_QT_H = \
  settings.h \
  filesystem.h \
  versioninfo.h \
  copyrightinfo.h \
  stylesheets.h \
  aboutdialog.h \
  coinparams.h \
  docdir.h \
  severitylogger.h \
  entropysource.h \
  currencyunitdialog.h \
  networkselectiondialog.h \
  splashscreen.h \
  acceptlicensedialog.h \
  mainwindow.h \
  commandserver.h \
  paymentrequest.h \
  numberformats.h \
  currencyvalidator.h \
  hexvalidator.h \
  accountmodel.h \
  accountview.h \
  keychainmodel.h \
  keychainview.h \
  entropydialog.h \
  quicknewaccountdialog.h \
  newaccountdialog.h \
  newkeychaindialog.h \
  txsearchdialog.h \
  rawtxdialog.h \
  createtxdialog.h \
  unspenttxoutmodel.h \
  unspenttxoutview.h \
  txmodel.h \
  txview.h \
  accounthistorydialog.h \
  txactions.h \
  scriptmodel.h \
  scriptview.h \
  scriptdialog.h \
  signaturemodel.h \
  signatureview.h \
  signaturedialog.h \
  signatureactions.h \
  requestpaymentdialog.h \
  networksettingsdialog.h \
  wordlistvalidator.h \
  keychainbackupwizard.h \
  keychainbackupdialog.h \
  viewbip32dialog.h \
  importbip32dialog.h \
  viewbip39dialog.h \
  importbip39dialog.h \
  passphrasedialog.h \
  setpassphrasedialog.h


BITCOIN_QT_CPP = $(BITCOIN_QT_BASE_CPP)
if TARGET_WINDOWS
BITCOIN_QT_CPP += $(BITCOIN_QT_WINDOWS_CPP)
endif
if ENABLE_WALLET
BITCOIN_QT_CPP += $(BITCOIN_QT_WALLET_CPP)
endif

BITCOIN_RC = ../images/mSIGNA.rc

libmsignaqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOIN_INCLUDES) $(BITCOIN_QT_INCLUDES) \
  $(QT_INCLUDES) $(QT_DBUS_INCLUDES) $(QR_CFLAGS)
libmsignaqt_a_CXXFLAGS = $(AM_CXXFLAGS) $(QT_PIE_FLAGS)

libmsignaqt_a_SOURCES = $(BITCOIN_QT_CPP) $(BITCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libmsignaqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) \
  $(QT_QRC_CPP)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

# Most files will depend on the forms and moc files as includes. Generate them
# before anything else.
$(QT_MOC): $(QT_FORMS_H)
$(libmsignaqt_a_OBJECTS) $(msigna_qt_OBJECTS) : | $(QT_MOC)

# msigna-qt binary #
msigna_qt_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOIN_INCLUDES) $(BITCOIN_QT_INCLUDES) \
  $(QT_INCLUDES) $(QR_CFLAGS)
msigna_qt_CXXFLAGS = $(AM_CXXFLAGS) $(QT_PIE_FLAGS)

msigna_qt_SOURCES = main.cpp
if TARGET_DARWIN
  msigna_qt_SOURCES += $(BITCOIN_MM)
endif
if TARGET_WINDOWS
  msigna_qt_SOURCES += $(BITCOIN_RC)
endif
msigna_qt_LDADD = libmsignaqt.a $(LIBBITCOIN_SERVER)
if ENABLE_WALLET
msigna_qt_LDADD += $(LIBBITCOIN_WALLET)
endif
msigna_qt_LDADD += $(LIBBITCOIN_CLI) $(LIBBITCOIN_COMMON) $(LIBBITCOIN_UTIL) $(LIBBITCOIN_CONSENSUS) $(LIBBITCOIN_CRYPTO) $(LIBUNIVALUE) $(LIBLEVELDB) $(LIBLEVELDB_SSE42) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(LIBSECP256K1) \
  $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS)
msigna_qt_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(QT_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)
msigna_qt_LIBTOOLFLAGS = --tag CXX

CLEAN_QT = $(nodist_libmsignaqt_a_SOURCES) $(QT_FORMS_H) qt/*.gcda qt/*.gcno

CLEANFILES = $(CLEAN_QT)

msigna_qt_clean: FORCE
	rm -f $(CLEAN_QT) $(libmsignaqt_a_OBJECTS) $(msigna_qt_OBJECTS) qt/msigna-qt$(EXEEXT) $(LIBBITCOINQT)

msigna_qt : msigna-qt$(EXEEXT)

ui_%.h: %.ui
	@test -f $(UIC)
	@$(MKDIR_P) $(@D)
	$(AM_V_GEN) QT_SELECT=$(QT_SELECT) $(UIC) -o $@ $< || (echo "Error creating $@"; false)

%.moc: %.cpp
	$(AM_V_GEN) QT_SELECT=$(QT_SELECT) $(MOC) $(DEFAULT_INCLUDES) $(QT_INCLUDES) $(MOC_DEFS) $< | \
	  $(SED) -e '/^\*\*.*Created:/d' -e '/^\*\*.*by:/d' > $@

moc_%.cpp: %.h
	$(AM_V_GEN) QT_SELECT=$(QT_SELECT) $(MOC) $(DEFAULT_INCLUDES) $(QT_INCLUDES) $(MOC_DEFS) $< | \
	  $(SED) -e '/^\*\*.*Created:/d' -e '/^\*\*.*by:/d' > $@

%.qm: %.ts
	@test -f $(LRELEASE)
	@$(MKDIR_P) $(@D)
	$(AM_V_GEN) QT_SELECT=$(QT_SELECT) $(LRELEASE) -silent $< -qm $@
