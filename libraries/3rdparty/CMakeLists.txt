if(${BUILD_TESTS})
    add_library(cmock STATIC
        "${ROOT_DIR}/libraries/3rdparty/CMock/src/cmock.c"
    )

    set_target_properties(cmock PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        POSITION_INDEPENDENT_CODE ON
        COMPILE_FLAGS "-Og"
    )

    add_library(unity STATIC
        "${3RDPARTY_DIR}/CMock/vendor/unity/src/unity.c"
        "${3RDPARTY_DIR}/CMock/vendor/unity/extras/fixture/src/unity_fixture.c"
        "${3RDPARTY_DIR}/CMock/vendor/unity/extras/memory/src/unity_memory.c"
    )
    set_target_properties(unity PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        POSITION_INDEPENDENT_CODE ON
    )

    target_include_directories(cmock PUBLIC
        ${ROOT_DIR}/libraries/3rdparty/CMock/src
        ${ROOT_DIR}/libraries/3rdparty/CMock/vendor/unity/src/
        ${ROOT_DIR}/libraries/3rdparty/CMock/examples
    )

    target_link_libraries(cmock unity)
endif()
# Global Build Settings for building cryptoauthlib 
set(ENABLE_TESTING OFF CACHE INTERNAL "")
include_directories(cryptoauthlib/lib 
                    build/cryptoauthlib/lib 
                    cryptoauthlib/third_party/mbedtls/include 
                    cryptoauthlib/lib/mbedtls)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DMBEDTLS_CONFIG_FILE=\\\"mbedtls_config.h\\\"")

set(LIBS pthread)

set(ATCA_BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(ATCA_MBEDTLS ON CACHE INTERNAL "")
set(ATCA_HAL_I2C ON CACHE INTERNAL "")

# Add cryptoauthlib
add_subdirectory(cryptoauthlib/lib)
