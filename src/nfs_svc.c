/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "nfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
nfs_program_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
    union {
        char *ls_1_arg;
        char *create_1_arg;
        char *delete_1_arg;
        request retrieve_file_1_arg;
        chunk send_file_1_arg;
        char *mkdir_1_arg;
    } argument;
    char *result;
    xdrproc_t _xdr_argument, _xdr_result;
    char *(*local)(char *, struct svc_req *);

    switch (rqstp->rq_proc) {
    case NULLPROC:
        (void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
        return;

    case ls:
        _xdr_argument = (xdrproc_t) xdr_wrapstring;
        _xdr_result = (xdrproc_t) xdr_wrapstring;
        local = (char *(*)(char *, struct svc_req *)) ls_1_svc;
        break;

    case create:
        _xdr_argument = (xdrproc_t) xdr_wrapstring;
        _xdr_result = (xdrproc_t) xdr_int;
        local = (char *(*)(char *, struct svc_req *)) create_1_svc;
        break;

    case delete:
        _xdr_argument = (xdrproc_t) xdr_wrapstring;
        _xdr_result = (xdrproc_t) xdr_int;
        local = (char *(*)(char *, struct svc_req *)) delete_1_svc;
        break;

    case retrieve_file:
        _xdr_argument = (xdrproc_t) xdr_request;
        _xdr_result = (xdrproc_t) xdr_chunk;
        local = (char *(*)(char *, struct svc_req *)) retrieve_file_1_svc;
        break;

    case send_file:
        _xdr_argument = (xdrproc_t) xdr_chunk;
        _xdr_result = (xdrproc_t) xdr_int;
        local = (char *(*)(char *, struct svc_req *)) send_file_1_svc;
        break;

    case mkdir:
        _xdr_argument = (xdrproc_t) xdr_wrapstring;
        _xdr_result = (xdrproc_t) xdr_int;
        local = (char *(*)(char *, struct svc_req *)) mkdir_1_svc;
        break;

    default:
        svcerr_noproc (transp);
        return;
    }
    memset ((char *)&argument, 0, sizeof (argument));
    if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
        svcerr_decode (transp);
        return;
    }
    result = (*local)((char *)&argument, rqstp);
    if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
        svcerr_systemerr (transp);
    }
    if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
        fprintf (stderr, "%s", "unable to free arguments");
    }
}