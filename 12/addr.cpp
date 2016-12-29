#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENT_NUMBER 1024
#define TCP_BUFFER_SIZE 512
#define UDP_BUFFER_SIZE 1024


int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        printf("usage: %s ip_address port_number\n", basename(argv[0]));
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in src;
    bzero(&src, sizeof(src));
    src.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &src.sin_addr);
    src.sin_port = htons(port);

    struct sockaddr_in result;
#if 0
    result.sin_family = ntohs(src.sin_family);
    result.sin_port = ntohs(src.sin_port);
    result.sin_addr.s_addr = ntohl(src.sin_addr.s_addr);
#endif
    memcpy(&result, &src, sizeof(struct sockaddr_in));

    char tmpAddr[16] = "";
    strncpy(tmpAddr, inet_ntoa(result.sin_addr), sizeof(tmpAddr) - 1);
    printf("addr:%s:%d\n", tmpAddr, ntohs(result.sin_port));

    return 0;
}
