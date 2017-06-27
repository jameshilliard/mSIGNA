noinst_LIBRARIES = libcoinq.a

OBJS = \
    src/CoinQ_coinparams.cpp \
    src/CoinQ_script.cpp \
    src/CoinQ_peer_io.cpp \
    src/CoinQ_netsync.cpp \
    src/CoinQ_blocks.cpp \
    src/CoinQ_txs.cpp \
    src/CoinQ_keys.cpp \
    src/CoinQ_filter.cpp \
    src/BlockchainDownload.cpp

libcoinq_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOIN_INCLUDES) $(CRYPTO_CFLAGS) $(SSL_CFLAGS) -I../stdutils/src -I../logger/src -I../Signals/src -I../CoinCore/src

libcoinq_a_SOURCES = $(OBJS)