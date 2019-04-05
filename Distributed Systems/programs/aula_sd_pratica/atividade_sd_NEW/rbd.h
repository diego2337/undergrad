/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RBD_H_RPCGEN
#define _RBD_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct agenda {
	char nome[65];
	u_int fone;
	char endereco[513];
};
typedef struct agenda agenda;

#define RBDPROG 0x30090949
#define RDBVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define INICIALIZAR 1
extern  int * inicializar_1(void *, CLIENT *);
extern  int * inicializar_1_svc(void *, struct svc_req *);
#define INSERE 2
extern  int * insere_1(agenda *, CLIENT *);
extern  int * insere_1_svc(agenda *, struct svc_req *);
#define REMOVE 3
extern  int * remove_1(agenda *, CLIENT *);
extern  int * remove_1_svc(agenda *, struct svc_req *);
#define BUSCA 4
extern  int * busca_1(agenda *, CLIENT *);
extern  int * busca_1_svc(agenda *, struct svc_req *);
extern int rbdprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INICIALIZAR 1
extern  int * inicializar_1();
extern  int * inicializar_1_svc();
#define INSERE 2
extern  int * insere_1();
extern  int * insere_1_svc();
#define REMOVE 3
extern  int * remove_1();
extern  int * remove_1_svc();
#define BUSCA 4
extern  int * busca_1();
extern  int * busca_1_svc();
extern int rbdprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_agenda (XDR *, agenda*);

#else /* K&R C */
extern bool_t xdr_agenda ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RBD_H_RPCGEN */
