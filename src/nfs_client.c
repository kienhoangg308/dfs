#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "nfs.h"

void nfs_program_1(char *host) {
    CLIENT *clnt;
    char *ls_1_arg = ""; // Example argument for ls
    int *result_2;
    char *create_1_arg = "newfile.txt";
    int *result_3;
    char *delete_1_arg = "oldfile.txt";
    chunk *result_4;
    request retrieve_file_1_arg = { "file_to_retrieve.txt", 0 };
    chunk send_file_1_arg = { "file_to_send.txt", {4, "data"}, 4, 0 };
    int *result_6;
    char *mkdir_1_arg = "new_directory";

    clnt = clnt_create(host, NFS_PROGRAM, NFS_VERSION_1, "tcp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }

    if (ls_1(&ls_1_arg, clnt) == (char **) NULL) {
        clnt_perror(clnt, "call failed for ls");
    }

    if (create_1(&create_1_arg, clnt) == (int *) NULL) {
        clnt_perror(clnt, "call failed for create");
    }

    if (delete_1(&delete_1_arg, clnt) == (int *) NULL) {
        clnt_perror(clnt, "call failed for delete");
    }

    if (retrieve_file_1(&retrieve_file_1_arg, clnt) == NULL) {
        clnt_perror(clnt, "call failed for retrieve file");
    }

    if (send_file_1(&send_file_1_arg, clnt) == NULL) {
        clnt_perror(clnt, "call failed for send file");
    }

    if (mkdir_1(&mkdir_1_arg, clnt) == (int *) NULL) {
        clnt_perror(clnt, "call failed for mkdir");
    }

    clnt_destroy(clnt);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s server_host\n", argv[0]);
        exit(1);
    }
    nfs_program_1(argv[1]);
    return 0;
}
