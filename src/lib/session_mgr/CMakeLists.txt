project(softhsm_sessionmgr)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
                 ${PROJECT_SOURCE_DIR}/../common
                 ${PROJECT_SOURCE_DIR}/../crypto
                 ${PROJECT_SOURCE_DIR}/../data_mgr
                 ${PROJECT_SOURCE_DIR}/../object_store
                 ${PROJECT_SOURCE_DIR}/../object_store/OS
                 ${PROJECT_SOURCE_DIR}/../pkcs11
                 ${PROJECT_SOURCE_DIR}/../slot_mgr
                 )

set(SOURCES SessionManager.cpp
            Session.cpp
            )

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../win32)
endif()

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})

if(BUILD_TESTS)
    add_subdirectory(test)
endif(BUILD_TESTS)
