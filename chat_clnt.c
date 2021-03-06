#include <memory.h> 
#include "chat.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

operand *
printmessage_1(operand *argp, CLIENT *clnt)
{
	static operand clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, PRINTMESSAGE,
		(xdrproc_t) xdr_operand, (caddr_t) argp,
		(xdrproc_t) xdr_operand, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
