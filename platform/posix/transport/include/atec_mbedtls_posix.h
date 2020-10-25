#ifndef ATEC_MBED_POSIX_H__
#define ATEC_MBED_POSIX_H__
// Add in the necessary header files here 
/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Logging related header files are required to be included in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define LIBRARY_LOG_NAME and  LIBRARY_LOG_LEVEL.
 * 3. Include the header file "logging_stack.h".
 */

/* Include header that defines log levels. */
#include "logging_levels.h"

/* Logging configuration for the transport interface implementation which uses
 * MBEDTLS over ATEC/cryptoauthlic  and Sockets. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME     "Transport_ATECMbed_Sockets"
#endif
#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_ERROR
#endif

#include "logging_stack.h"

/************ End of logging configuration ****************/
#if 1
/* From mbedtls */
#include "mbedtls/platform.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include "mbedtls/certs.h"
#include "mbedtls/pk.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/ecdh.h"

/* From Cryptoauthlib */
#include "cryptoauthlib.h"
#include "atca_cfgs.h"
#include "atcacert/atcacert_client.h"
#include "mbedtls/atca_mbedtls_wrap.h"
 
//#include "tngtls_cert_def_1_signer.h"
//#include "tngtls_cert_def_3_device.h"
#endif 
#include "transport_interface.h"

/* Socket include. */
#include "sockets_posix.h"

/**
 * @brief Definition of the network context for the transport interface
 * implementation that uses ATEC MBED and POSIX sockets.
 *
 * @note For this transport implementation, the socket descriptor and
 * ATEC MBED context is used.
 */
 
typedef enum 
{
	ATEC_DEVICE_INIT_FAIL,
	ATEC_DEVICE_INIT_OK
} ATECDeviceState_e; 

typedef enum 
{
	ATEC_MBED_OP_SUCCESS, 
	ATEC_MBED_OP_FAILURE, 
} ATEC_MBED_Op_e; 
 
typedef struct 
{
	#if 0 // add in later 
	mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;
    mbedtls_x509_crt cacert;
    mbedtls_pk_context pkey;
    mbedtls_x509_crt cert;
    #endif 
    ATECDeviceState_e state;  
} ATEC_MBED_Context_t; 
struct NetworkContext
{
    int32_t socketDescriptor;
    ATEC_MBED_Context_t *pATEC_Context; 
};
/**
 * @brief Sets up a TLS session on top of a TCP connection using the ATEC MBED API.
 *
 * @param[out] pNetworkContext The output parameter to return the created network context.
 * @param[in] pServerInfo Server connection info.
 * @param[in] sendTimeoutMs Timeout for transport send.
 * @param[in] recvTimeoutMs Timeout for transport recv.
 *
 * @note A timeout of 0 means infinite timeout.
 *
 * @return #ATEC_MBED_OP_SUCCESS on success;
 * #ATEC_MBED_OP_FAILURE on failure.
 */

ATEC_MBED_Op_e ATEC_Mbed_Connect( NetworkContext_t * pNetworkContext,
                                 const ServerInfo_t * pServerInfo,
                                 uint32_t sendTimeoutMs,
                                 uint32_t recvTimeoutMs );

/**
 * @brief Closes a TLS session on top of a TCP connection using the ATEC MBED API.
 *
 * @param[out] pNetworkContext The output parameter to end the TLS session and
 * clean the created network context.
 *
 * @return #ATEC_MBED_OP_SUCCESS on success; #ATEC_MBED_OP_FAILURE on failure.
 */
ATEC_MBED_Op_e ATEC_Mbed_Disconnect( const NetworkContext_t * pNetworkContext );

/**
 * @brief Receives data over an established TLS session using the ATEC MBED API.
 *
 * This can be used as #TransportInterface.recv function for receiving data
 * from the network.
 *
 * @param[in] pNetworkContext The network context created using ATEC_Mbed_Connect API.
 * @param[out] pBuffer Buffer to receive network data into.
 * @param[in] bytesToRecv Number of bytes requested from the network.
 *
 * @return Number of bytes received if successful; negative value on error.
 */
int32_t ATEC_Mbed_Recv( const NetworkContext_t * pNetworkContext,
                      void * pBuffer,
                      size_t bytesToRecv );

/**
 * @brief Sends data over an established TLS session using the ATEC MBED API.
 *
 * This can be used as the #TransportInterface.send function to send data
 * over the network.
 *
 * @param[in] pNetworkContext The network context created using ATEC MBED API.
 * @param[in] pBuffer Buffer containing the bytes to send over the network stack.
 * @param[in] bytesToSend Number of bytes to send over the network.
 *
 * @return Number of bytes sent if successful; negative value on error.
 */
int32_t ATEC_Mbed_Send( const NetworkContext_t * pNetworkContext,
                      const void * pBuffer,
                      size_t bytesToSend );

#endif //ATEC_MBED_POSIX_H__
