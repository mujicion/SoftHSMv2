project(softhsm_crypto_botan)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
                 ${PROJECT_SOURCE_DIR}/../common
                 ${PROJECT_SOURCE_DIR}/../data_mgr
                 ${PROJECT_SOURCE_DIR}/../pkcs11
                 ${CRYPTO_INCLUDES}
)

set(SOURCES BotanAES.cpp
            BotanCryptoFactory.cpp
            BotanDES.cpp
            BotanDH.cpp
            BotanDHKeyPair.cpp
            BotanDHPrivateKey.cpp
            BotanDHPublicKey.cpp
            BotanDSA.cpp
            BotanDSAKeyPair.cpp
            BotanDSAPrivateKey.cpp
            BotanDSAPublicKey.cpp
            BotanECDH.cpp
            BotanECDHKeyPair.cpp
            BotanECDHPrivateKey.cpp
            BotanECDHPublicKey.cpp
            BotanECDSA.cpp
            BotanECDSAKeyPair.cpp
            BotanECDSAPrivateKey.cpp
            BotanECDSAPublicKey.cpp
            BotanEDDSA.cpp
            BotanEDKeyPair.cpp
            BotanEDPrivateKey.cpp
            BotanEDPublicKey.cpp
            BotanGOST.cpp
            BotanGOSTKeyPair.cpp
            BotanGOSTPrivateKey.cpp
            BotanGOSTPublicKey.cpp
            BotanGOSTR3411.cpp
            BotanHashAlgorithm.cpp
            BotanMacAlgorithm.cpp
            BotanMAC.cpp
            BotanMD5.cpp
            BotanRNG.cpp
            BotanRSA.cpp
            BotanRSAKeyPair.cpp
            BotanRSAPrivateKey.cpp
            BotanRSAPublicKey.cpp
            BotanSHA1.cpp
            BotanSHA224.cpp
            BotanSHA256.cpp
            BotanSHA384.cpp
            BotanSHA512.cpp
            BotanSymmetricAlgorithm.cpp
            BotanUtil.cpp
            )

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../win32)
ENDIF()

# mute botan specific warnings
# https://github.com/randombit/botan/issues/486
list(APPEND COMPILE_OPTIONS "/wd4250;/wd4251;/wd4275;/wd4127;/wd4273") 

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})

# Versions before CMake 3.12 cannot use target_link_libraries on object
# libraries, a workaround exists in src/lib/CMakeLists.txt.
if(NOT CMAKE_VERSION VERSION_LESS "3.12")
        target_link_libraries(${PROJECT_NAME} ${CRYPTO_LIBS})
endif()
