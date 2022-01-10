#include "pipe_networking.h"

int main()
{

    int to_client = server_setup();
    int from_client;

    while (TRUE)
    {
        from_client = server_connect(to_client);
        int f = fork();

        if (f)
        {
            close(from_client);
        }
        else
        {
            while (TRUE)
            {
                char buff[512];
                memset(buff, '\0', sizeof(buff));
                read(from_client, buff, sizeof(buff));

                for (int i = 0; buff[i]; ++i)
                    buff[i] = toupper(buff[i]);

                write(from_client, buff, strlen(buff));
            }
        }
    }
}
