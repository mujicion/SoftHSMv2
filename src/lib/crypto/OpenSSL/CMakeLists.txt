project(softhsm_crypto_openssl)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
                 ${PROJECT_SOURCE_DIR}/../../common
                 ${PROJECT_SOURCE_DIR}/../../data_mgr
                 ${PROJECT_SOURCE_DIR}/../../pkcs11
                 ${PROJECT_SOURCE_DIR}/..
                 ${CRYPTO_INCLUDES}
                )

set(SOURCES OSSLAES.cpp
            OSSLCMAC.cpp
            OSSLComp.cpp
            OSSLCryptoFactory.cpp
            OSSLDES.cpp
            OSSLDH.cpp
            OSSLDHKeyPair.cpp
            OSSLDHPrivateKey.cpp
            OSSLDHPublicKey.cpp
            OSSLDSA.cpp
            OSSLDSAKeyPair.cpp
            OSSLDSAPrivateKey.cpp
            OSSLDSAPublicKey.cpp
            OSSLECDH.cpp
            OSSLECDSA.cpp
            OSSLECKeyPair.cpp
            OSSLECPrivateKey.cpp
            OSSLECPublicKey.cpp
            OSSLEDDSA.cpp
            OSSLEDKeyPair.cpp
            OSSLEDPrivateKey.cpp
            OSSLEDPublicKey.cpp
            OSSLEVPCMacAlgorithm.cpp
            OSSLEVPHashAlgorithm.cpp
            OSSLEVPMacAlgorithm.cpp
            OSSLEVPSymmetricAlgorithm.cpp
            OSSLGOST.cpp
            OSSLGOSTKeyPair.cpp
            OSSLGOSTPrivateKey.cpp
            OSSLGOSTPublicKey.cpp
            OSSLGOSTR3411.cpp
            OSSLHMAC.cpp
            OSSLMD5.cpp
            OSSLRNG.cpp
            OSSLRSA.cpp
            OSSLRSAKeyPair.cpp
            OSSLRSAPrivateKey.cpp
            OSSLRSAPublicKey.cpp
            OSSLSHA1.cpp
            OSSLSHA224.cpp
            OSSLSHA256.cpp
            OSSLSHA384.cpp
            OSSLSHA512.cpp
            OSSLUtil.cpp
            )


if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../win32)
ENDIF()

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})

# Versions before CMake 3.12 cannot use target_link_libraries on object
# libraries, a workaround exists in src/lib/CMakeLists.txt.
if(NOT CMAKE_VERSION VERSION_LESS "3.12")
        target_link_libraries(${PROJECT_NAME} ${CRYPTO_LIBS})
endif()
