#include "pipe_networking.h"

int main()
{

    int to_client;
    int from_client;

    while (TRUE)
    {
        from_client = server_setup();
        int f = fork();

        if (f)
        {
        }
        else
        {
            to_client = server_connect(from_client);

            while (TRUE)
            {
                char buff[512];
                memset(buff, '\0', sizeof(buff));
                read(from_client, buff, sizeof(buff));

                for (int i = 0; buff[i]; ++i)
                    buff[i] = toupper(buff[i]);

                write(to_client, buff, strlen(buff));
            }
        }
    }
}
