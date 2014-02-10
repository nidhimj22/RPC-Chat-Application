#ifndef _CHAT_H_RPCGEN
#define _CHAT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct operand {
	char myname[100];
	char message[100];
	char yourname[100];
};
typedef struct operand operand;

#define MESSAGEPROG 0x20000001
#define PRINTMESSAGEVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define PRINTMESSAGE 1
extern  operand * printmessage_1(operand *, CLIENT *);
extern  operand * printmessage_1_svc(operand *, struct svc_req *);
extern int messageprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define PRINTMESSAGE 1
extern  operand * printmessage_1();
extern  operand * printmessage_1_svc();
extern int messageprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_operand (XDR *, operand*);

#else /* K&R C */
extern bool_t xdr_operand ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CHAT_H_RPCGEN */
