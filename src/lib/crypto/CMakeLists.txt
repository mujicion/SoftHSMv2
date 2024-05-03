project(softhsm_crypto)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
                 ${PROJECT_SOURCE_DIR}/../common
                 ${PROJECT_SOURCE_DIR}/../data_mgr
                 ${PROJECT_SOURCE_DIR}/../pkcs11
                 ${CRYPTO_INCLUDES}
                 )

set(SOURCES AESKey.cpp
            AsymmetricAlgorithm.cpp
            AsymmetricKeyPair.cpp
            CryptoFactory.cpp
            DerUtil.cpp
            DESKey.cpp
            DHParameters.cpp
            DHPrivateKey.cpp
            DHPublicKey.cpp
            DSAParameters.cpp
            DSAPrivateKey.cpp
            DSAPublicKey.cpp
            ECParameters.cpp
            ECPrivateKey.cpp
            ECPublicKey.cpp
            EDPrivateKey.cpp
            EDPublicKey.cpp
            GOSTPrivateKey.cpp
            GOSTPublicKey.cpp
            HashAlgorithm.cpp
            MacAlgorithm.cpp
            RSAParameters.cpp
            RSAPrivateKey.cpp
            RSAPublicKey.cpp
            SymmetricAlgorithm.cpp
            SymmetricKey.cpp
            )

if(WITH_MIZARU)
    add_subdirectory(mizaru)
	list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../../lib/crypto/mizaru)
endif(WITH_MIZARU)

if(WITH_OPENSSL)
    add_subdirectory(OpenSSL)
	list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../../lib/crypto/OpenSSL)
endif(WITH_OPENSSL)

if(WITH_BOTAN)
    add_subdirectory(Botan)
	list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../../lib/crypto/Botan)
endif(WITH_BOTAN)

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

if(BUILD_TESTS)
    add_subdirectory(test)
endif(BUILD_TESTS)
