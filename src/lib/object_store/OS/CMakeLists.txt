project(softhsm_objectstore_os)

set(INCLUDE_DIRS    ${PROJECT_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/..
                    ${PROJECT_SOURCE_DIR}/../../common
                    ${PROJECT_SOURCE_DIR}/../../pkcs11
                    ${PROJECT_SOURCE_DIR}/../../data_mgr
                    )

set(SOURCES Directory.cpp
            File.cpp
            Generation.cpp
            ObjectFile.cpp
            OSAttribute.cpp
            OSToken.cpp
            )

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})
