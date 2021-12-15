#include "pipe_networking.h"

static void sighandler(int signo)
{
    if (signo == SIGINT)
    {
        printf("Shutting down client\n");
        exit(0);
    }
}

int main()
{
    signal(SIGINT, sighandler);

    int to_server;
    int from_server;

    from_server = client_handshake(&to_server);

    printf("Enter input: ");
    char buffer[512];
    memset(buffer, '\0', sizeof(buffer));

    while (fgets(buffer, sizeof(buffer), stdin))
    {
        write(to_server, buffer, strlen(buffer));

        memset(buffer, '\0', sizeof(buffer));
        read(from_server, buffer, sizeof(buffer));
        printf("Output from server: %s\n", buffer);

        printf("Enter input: ");
    }
}