noinst_LIBRARIES = libcoincore.a

OBJS = \
        src/IPv6.cpp \
        src/CoinNodeData.cpp \
        src/CoinKey.cpp \
        src/hdkeys.cpp \
        src/bip39.cpp \
        src/BloomFilter.cpp \
        src/MerkleTree.cpp \
        src/secp256k1_openssl.cpp \
        src/aes.cpp

noinst_HEADERS = \
        src/Base58Check.h \
        src/BigInt.h \
        src/encodings.h \
        src/hash.h \
        src/hashblock.h \
        src/jsonResult.h \
        src/numericdata.h \
        src/random.h \
        src/typedefs.h \
        src/uint256.h

SCRYPT_OBJS = \
	src/scrypt/scrypt.cpp

HASH9_OBJS = \
	src/hashfunc/blake.c \
	src/hashfunc/bmw.c \
	src/hashfunc/groestl.c \
	src/hashfunc/jh.c \
	src/hashfunc/keccak.c \
	src/hashfunc/skein.c

libcoincore_a_CPPFLAGS = $(AM_CPPFLAGS) $(BITCOIN_INCLUDES) $(CRYPTO_CFLAGS) $(SSL_CFLAGS) -I../stdutils/src

libcoincore_a_SOURCES = $(OBJS) $(SCRYPT_OBJS) $(HASH9_OBJS)
