#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

//macro
#define BUF_SIZE 1024 
#define PORT 1025 
#define SEND_PACK_CNT 3
#define SRV_IP "127.0.0.1" 
#undef handle_error
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    int server_fd = -1;
    int i;


    if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        handle_error("socket");

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_aton(SRV_IP, &server_addr.sin_addr) == 0)
        handle_error("inet_aton");
    
    for(i = 0; i < SEND_PACK_CNT; i++) {
        sprintf(buf, "Packet %d", i);
        sendto(server_fd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    }

    close(server_fd);

    return 0;
}
