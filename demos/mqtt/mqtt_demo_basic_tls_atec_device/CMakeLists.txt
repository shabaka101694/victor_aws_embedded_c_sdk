set( DEMO_NAME "mqtt_demo_basic_tls_atec_device" )

# Include MQTT library's source and header path variables.
include( ${CMAKE_SOURCE_DIR}/libraries/standard/coreMQTT/mqttFilePaths.cmake )
include_directories(${CMAKE_SOURCE_DIR}/libraries/3rdparty/cryptoauthlib/lib 
                      ${CMAKE_SOURCE_DIR}/libraries/3rdparty/cryptoauthlib/lib/mbedtls/include 
                     ${CMAKE_SOURCE_DIR}/libraries/3rdparty/cryptoauthlib/third_party/mbedtls/include
                      ${CMAKE_SOURCE_DIR}/build/libraries/3rdparty/cryptoauthlib/lib
                     ${CMAKE_SOURCE_DIR}/platform/posix/transport/include
                      ${CMAKE_SOURCE_DIR}/libraries/3rdparty/cryptoauthlib/lib/mbedtls)

# Demo target.
add_executable(
    ${DEMO_NAME}
        "${DEMO_NAME}.c"
        tngtls_cert_def_1_signer.c
        tngtls_cert_def_3_device.c
        ${MQTT_SOURCES}
        ${MQTT_SERIALIZER_SOURCES}
)

target_link_libraries(
    ${DEMO_NAME}
    PRIVATE                 
        clock_posix
        atec_mbedtls_posix
        retry_utils_posix
        mbedtls
        cryptoauth
        pthread
)

target_include_directories(
    ${DEMO_NAME}
    PUBLIC
		${TRANSPORT_INCLUDE_PUBLIC_DIRS}
        ${MQTT_INCLUDE_PUBLIC_DIRS}
        ${CMAKE_CURRENT_LIST_DIR}
        ${LOGGING_INCLUDE_DIRS}
)

if(ROOT_CA_CERT_PATH)
    target_compile_definitions(
        ${DEMO_NAME} PRIVATE
            ROOT_CA_CERT_PATH="${ROOT_CA_CERT_PATH}"
    )
endif()
if(BROKER_ENDPOINT)
    target_compile_definitions(
        ${DEMO_NAME} PRIVATE
            BROKER_ENDPOINT="${BROKER_ENDPOINT}"
    )
endif()
if(CLIENT_IDENTIFIER)
    target_compile_definitions(
        ${DEMO_NAME} PRIVATE
            CLIENT_IDENTIFIER="${CLIENT_IDENTIFIER}"
    )
endif()
