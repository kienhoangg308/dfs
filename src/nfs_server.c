#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "nfs.h"  // Include the generated header from the RPC definitions

// Function to handle RPC requests
void nfs_program_1(struct svc_req *rqstp, register SVCXPRT *transp) {
    switch (rqstp->rq_proc) {
        case NULLPROC:
            svc_sendreply(transp, (xdrproc_t) xdr_void, NULL);
            return;
        // Additional cases for your other RPC procedures
        default:
            svcerr_noproc(transp);
            return;
    }
}

char **ls_1_svc(char **argp, struct svc_req *rqstp) {
    static char *result = "directory listing here";
    return &result;
}

int *create_1_svc(char **argp, struct svc_req *rqstp) {
    static int result = 0; // Simulated success
    return &result;
}

int *delete_1_svc(char **argp, struct svc_req *rqstp) {
    static int result = 0; // Simulated success
    return &result;
}

chunk *retrieve_file_1_svc(request *argp, struct svc_req *rqstp) {
    static chunk result; // Example result, normally you would fill this with actual data
    return &result;
}

int *send_file_1_svc(chunk *argp, struct svc_req *rqstp) {
    static int result = 0; // Simulated success
    return &result;
}

int *mkdir_1_svc(char **argp, struct svc_req *rqstp) {
    static int result = 0; // Simulated success
    return &result;
}

int main() {
    register SVCXPRT *transp;

    pmap_unset(NFS_PROGRAM, NFS_VERSION_1);

    transp = svcudp_create(RPC_ANYSOCK);
    // if (transp == NULL) {
    //     fprintf(stderr, "cannot create UDP service.\n");
    //     exit(1);
    // }

    // if (!svc_register(transp, NFS_PROGRAM, NFS_VERSION_1, nfs_program_1, IPPROTO_UDP)) {
    //     fprintf(stderr, "unable to register (NFS_PROGRAM, NFS_VERSION_1, udp).\n");
    //     exit(1);
    // }

	if (transp == NULL) {
    fprintf(stderr, "cannot create UDP service.\n");
    exit(1);
}
if (!svc_register(transp, NFS_PROGRAM, NFS_VERSION_1, nfs_program_1, IPPROTO_UDP)) {
    fprintf(stderr, "unable to register (NFS_PROGRAM, NFS_VERSION_1, udp).\n");
    exit(1);
}

transp = svctcp_create(RPC_ANYSOCK, 0, 0);
if (transp == NULL) {
    fprintf(stderr, "cannot create TCP service.\n");
    exit(1);
}
if (!svc_register(transp, NFS_PROGRAM, NFS_VERSION_1, nfs_program_1, IPPROTO_TCP)) {
    fprintf(stderr, "unable to register (NFS_PROGRAM, NFS_VERSION_1, tcp).\n");
    exit(1);
}

    svc_run();
    fprintf(stderr, "Error: svc_run returned!\n");
    exit(1);
}
