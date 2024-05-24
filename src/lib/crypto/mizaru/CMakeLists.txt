project(hsm_crypto_mizaru)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
                 ${PROJECT_SOURCE_DIR}/..
                 ${PROJECT_SOURCE_DIR}/../../common
                 ${PROJECT_SOURCE_DIR}/../../data_mgr
                 ${PROJECT_SOURCE_DIR}/../../pkcs11
                 ${CRYPTO_INCLUDES}
                 ${PROJECT_SOURCE_DIR}/../OpenSSL
                )

set(SOURCES mizaruStub.cpp
            MizaruCryptoFactory.cpp
            MizaruRNG.cpp
            MizaruSymmetricAlgorithm.cpp
            MizaruAES.cpp
            MizaruDES.cpp
            MizaruRSA.cpp
            MizaruRSAKeyPair.cpp
            MizaruRSAPrivateKey.cpp
            MizaruRSAPublicKey.cpp
            MizaruSHA256.cpp
            MizaruECDSA.cpp
            MizaruCMAC.cpp
            MizaruHMAC.cpp
            # ../OpenSSL/OSSLComp.cpp
            # ../OpenSSL/OSSLUtil.cpp
            # ../OpenSSL/OSSLEVPHashAlgorithm.cpp
            )

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})
