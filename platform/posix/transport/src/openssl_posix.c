/* Standard includes. */
#include <assert.h>
#include <string.h>

/* POSIX socket include. */
#include <unistd.h>

/* Transport interface include. */
#include "transport_interface.h"

#include "openssl_posix.h"
#include <openssl/err.h>

int32_t Openssl_Recv(  NetworkContext_t * pNetworkContext,
                      void * pBuffer,
                      size_t bytesToRecv )
{
	return 0; 
}


int32_t Openssl_Send( NetworkContext_t * pNetworkContext,
                      const void * pBuffer,
                      size_t bytesToSend )
{
	return 0; 
}	
	

OpensslStatus_t Openssl_Connect( NetworkContext_t * pNetworkContext,
                                 const ServerInfo_t * pServerInfo,
                                 const OpensslCredentials_t * pOpensslCredentials,
                                 uint32_t sendTimeoutMs,
                                 uint32_t recvTimeoutMs )
{
	return OPENSSL_CONNECT_FAILURE; 	
}                                 
		
OpensslStatus_t Openssl_Disconnect( const NetworkContext_t * pNetworkContext )
{
	return OPENSSL_SUCCESS;
}	
