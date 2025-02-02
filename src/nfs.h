/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NFS_H_RPCGEN
#define _NFS_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define FILENAME_LENGTH 128
#define DATA_LENGTH 1024

struct request {
	char *filename;
	int start;
};
typedef struct request request;

struct chunk {
	char *filename;
	struct {
		u_int data_len;
		char *data_val;
	} data;
	int size;
	int dest_offset;
};
typedef struct chunk chunk;


#define NFS_PROGRAM 0x21000001
#define NFS_VERSION_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define ls 1
extern  char ** ls_1(char **, CLIENT *);
extern  char ** ls_1_svc(char **, struct svc_req *);
#define create 2
extern  int * create_1(char **, CLIENT *);
extern  int * create_1_svc(char **, struct svc_req *);
#define delete 3
extern  int * delete_1(char **, CLIENT *);
extern  int * delete_1_svc(char **, struct svc_req *);
#define retrieve_file 4
extern  chunk * retrieve_file_1(request *, CLIENT *);
extern  chunk * retrieve_file_1_svc(request *, struct svc_req *);
#define send_file 5
extern  int * send_file_1(chunk *, CLIENT *);
extern  int * send_file_1_svc(chunk *, struct svc_req *);
#define mkdir 6
extern  int * mkdir_1(char **, CLIENT *);
extern  int * mkdir_1_svc(char **, struct svc_req *);
extern int nfs_program_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ls 1
extern  char ** ls_1();
extern  char ** ls_1_svc();
#define create 2
extern  int * create_1();
extern  int * create_1_svc();
#define delete 3
extern  int * delete_1();
extern  int * delete_1_svc();
#define retrieve_file 4
extern  chunk * retrieve_file_1();
extern  chunk * retrieve_file_1_svc();
#define send_file 5
extern  int * send_file_1();
extern  int * send_file_1_svc();
#define mkdir 6
extern  int * mkdir_1();
extern  int * mkdir_1_svc();
extern int nfs_program_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_request (XDR *, request*);
extern  bool_t xdr_chunk (XDR *, chunk*);
extern  bool_t xdr_chunk (XDR *, chunk*);

#else /* K&R C */
extern bool_t xdr_request ();
extern bool_t xdr_chunk ();
extern bool_t xdr_chunk ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NFS_H_RPCGEN */
