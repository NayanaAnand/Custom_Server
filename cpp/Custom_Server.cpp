#include "Custom_Server.h"
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 4455
#define SA struct sockaddr

PREPARE_LOGGING(Custom_Server_i)


Custom_Server_i::Custom_Server_i(const char *uuid, const char *label) :
    Custom_Server_base(uuid, label)
{
    // Avoid placing constructor code here. Instead, use the "constructor" function.

}

Custom_Server_i::~Custom_Server_i()
{
}

void Custom_Server_i::constructor()
{
    /***********************************************************************************
     This is the RH constructor. All properties are properly initialized before this function is called 
    ***********************************************************************************/
}

void func(int sockfd)
{
}

int Custom_Server_i::serviceFunction()
{
    //RH_DEBUG(this->_baseLog, "serviceFunction() example log message");

    char buff[MAX];
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
                printf("socket creation failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully created..\n");
        bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htons(INADDR_ANY);
        servaddr.sin_port = htons(PORT);

	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
                printf("socket bind failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully binded..\n");

	if ((listen(sockfd, 5)) != 0) {
                printf("Listen failed...\n");
                exit(0);
        }
        else
                printf("Server listening..\n");
        len = sizeof(cli);

	connfd = accept(sockfd, (SA*)&cli, (socklen_t *)&len);
        if (connfd < 0) {
                printf("server acccept failed...\n");
                exit(0);
        }
        else
                LOG_INFO(Custom_Server_i,"server acccepted the client...");

    //func(connfd);

    //for (;;) {
            bzero(buff, MAX);
            read(connfd, buff, sizeof(buff));
            LOG_INFO(Custom_Server_i, "Data Recieved : " << buff);
            //printf("From client: %s\t To client : ", buff);
            //while ((buff[n++] = getchar()) != '\n');
            bzero(buff, MAX);
            strcpy(buff, "Hi, I am Server");
            write(connfd, buff, sizeof(buff));

            if (strncmp("exit", buff, 4) == 0) {
                    printf("Server Exit...\n");
            //        break;
            }
    //}

	close(sockfd);

    return 0;
}

