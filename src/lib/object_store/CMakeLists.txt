project(softhsm_objectstore)

set(INCLUDE_DIRS    ${PROJECT_SOURCE_DIR}
                    ${PROJECT_SOURCE_DIR}/OS
                    ${PROJECT_SOURCE_DIR}/../common
                    ${PROJECT_SOURCE_DIR}/../crypto
                    ${PROJECT_SOURCE_DIR}/../data_mgr
                    ${PROJECT_SOURCE_DIR}/../pkcs11
                    ${SQLITE3_INCLUDES}
                    )

set(SOURCES FindOperation.cpp
            ObjectStore.cpp
            ObjectStoreToken.cpp
            SessionObject.cpp
            SessionObjectStore.cpp
            UUID.cpp
            )

add_subdirectory(OS)
list(APPEND INCLUDE_DIRS    ${PROJECT_SOURCE_DIR}/OS)

if(WITH_OBJECTSTORE_BACKEND_DB)
    add_subdirectory(DB)
    list(APPEND INCLUDE_DIRS    ${PROJECT_SOURCE_DIR}/DB)
endif(WITH_OBJECTSTORE_BACKEND_DB)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    list(APPEND INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/../win32)
endif()

include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} OBJECT ${SOURCES})
target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILE_OPTIONS})

# Versions before CMake 3.12 cannot use target_link_libraries on object
# libraries, a workaround exists in src/lib/CMakeLists.txt.
if(NOT CMAKE_VERSION VERSION_LESS "3.12")
        target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBS})
endif()

if(BUILD_TESTS)
    add_subdirectory(test)
endif(BUILD_TESTS)
