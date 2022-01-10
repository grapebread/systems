#include "pipe_networking.h"

int main()
{

    int to_server;
    int from_server = client_handshake(&to_server);

    char buff[512];

    while (TRUE)
    {
        printf("Input: ");
        memset(buff, '\0', sizeof(buff));
        fgets(buff, sizeof(buff), stdin);
        *strchr(buff, '\n') = '\0';

        write(from_server, buff, strlen(buff));

        read(from_server, buff, sizeof(buff));
        printf("[client]: -%s-\n", buff);
    }
}
