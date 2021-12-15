#include <ctype.h>

#include "pipe_networking.h"

#define TRUE 1

static void sighandler(int signo)
{
    if (signo == SIGINT)
    {
        printf("Shutting down server\n");
        exit(0);
    }
}

int main()
{
    signal(SIGINT, sighandler);

    int to_client;
    int from_client;

    printf("Starting server\n");

    while (TRUE)
    {
        from_client = server_handshake(&to_client);

        char buffer[512];
        memset(buffer, '\0', sizeof(buffer));

        while (read(from_client, buffer, sizeof(buffer)) != 0)
        {
            for (int i = 0; buffer[i]; ++i)
                buffer[i] = toupper(buffer[i]);

            write(to_client, buffer, strlen(buffer));
            memset(buffer, '\0', sizeof(buffer));
        }
    }
}