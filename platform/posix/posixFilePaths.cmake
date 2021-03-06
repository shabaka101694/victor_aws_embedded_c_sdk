# This file is to add source files and include directories
# into variables so that it can be reused from different repositories
# in their Cmake based build system by including this file.
#
# Files specific to the repository such as test runner, platform tests
# are not added to the variables.

# mbedtls over atec device utility source files.
set( MBED_ATEC_SOURCES
     ${CMAKE_CURRENT_LIST_DIR}/transport/src/atec_mbedtls_posix.c )

# Sockets utility source files.
set( SOCKETS_SOURCES
     ${CMAKE_CURRENT_LIST_DIR}/transport/src/sockets_posix.c )

# Plaintext transport source files.
set( PLAINTEXT_TRANSPORT_SOURCES
     ${CMAKE_CURRENT_LIST_DIR}/transport/src/plaintext_posix.c )

# OpenSSL transport source files.
set( OPENSSL_TRANSPORT_SOURCES
     ${CMAKE_CURRENT_LIST_DIR}/transport/src/openssl_posix.c )

# Transport Public Include directories.
set( COMMON_TRANSPORT_INCLUDE_PUBLIC_DIRS
     ${CMAKE_CURRENT_LIST_DIR}/transport/include
     ${PLATFORM_DIR}/include )

# Retry utility source files.
set( RETRY_SOURCES
     ${CMAKE_CURRENT_LIST_DIR}/retry_utils_posix.c )

# Retry Public Include directories.
set( RETRY_INCLUDE_PUBLIC_DIRS
     ${PLATFORM_DIR}/include )
