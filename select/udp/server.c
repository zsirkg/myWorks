#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

//macro
#define BUF_SIZE 1024 
#define PORT 1025 
#undef handle_error
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr;
    fd_set read_fds;
    socklen_t len;
    char buf[BUF_SIZE];
    int server_fd = -1;
    int ret;

    if((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
        handle_error("socket");

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); /*any ip*/
    
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        handle_error("bind");

    printf("accepting connections on port %d\n", PORT);
    
    while(1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd ,&read_fds);

        ret = select(server_fd + 1, &read_fds, NULL, NULL, NULL);

        if(ret == -1 && errno == EINTR)
            continue;

        if(ret == -1)
            handle_error("select");
        
        if(ret == 0) /*timeout, if you set timeout.*/
            continue;
    
        if(FD_ISSET(server_fd, &read_fds)) {
            memset(buf, 0, BUF_SIZE);
            len = sizeof(server_addr);
            if(recvfrom(server_fd, (void *)buf, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &len) > 0) {
                printf("Receive packet from %s:%d\nData:%s\n", 
                        inet_ntoa(server_addr.sin_addr),
                        ntohs(server_addr.sin_port),
                        buf);
            } else {
                handle_error("recvfrom");
            }
        }
    }

    close(server_fd);

    return 0;
}
