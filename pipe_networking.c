#include "pipe_networking.h"

/*=========================
  server_handshake
  args: int * to_client
  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.
  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client)
{
    mkfifo(WKP, 0644);
    printf("Server: created pipe\n");

    int from_client = open(WKP, O_RDONLY);
    char secret[512];
    memset(secret, '\0', sizeof(secret));
    read(from_client, secret, sizeof(secret));
    printf("Server: got secret name (%s) from client\n", secret);
    remove(WKP);

    *to_client = open(secret, O_WRONLY);
    printf("Server: opened secret pipe (%s)\n", secret);
    write(*to_client, ACK, strlen(ACK));

    char res[512];
    memset(res, '\0', sizeof(res));
    read(from_client, res, sizeof(res));
    printf("Server: recieved response (%s)\n", res);

    return from_client;
}

/*=========================
  client_handshake
  args: int * to_server
  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.
  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server)
{
    char secret[512];
    memset(secret, '\0', sizeof(secret));
    sprintf(secret, "%d", getpid());
    mkfifo(secret, 0644);

    *to_server = open(WKP, O_WRONLY);
    write(*to_server, secret, strlen(secret));

    int from_server = open(secret, O_RDONLY);

    char res[512];
    memset(res, '\0', sizeof(res));
    read(from_server, res, sizeof(res));
    printf("Client: received response (%s)\n", res);

    remove(secret);

    if (!strcmp(res, ACK))
    {
        char s[] = "Client: success";
        write(*to_server, s, sizeof(res));
    }

    return from_server;
}