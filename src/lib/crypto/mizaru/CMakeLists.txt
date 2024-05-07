project(hsm_crypto_mizaru)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
                 ${PROJECT_SOURCE_DIR}/../../common
                 ${PROJECT_SOURCE_DIR}/../../data_mgr
                 ${PROJECT_SOURCE_DIR}/../../pkcs11
                 ${PROJECT_SOURCE_DIR}/..
                 ${CRYPTO_INCLUDES}
                )

set(SOURCES mizaruStub.cpp
            MizaruCryptoFactory.cpp
            MizaruRNG.cpp
            )

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})
