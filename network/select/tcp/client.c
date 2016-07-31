#include <stdio.h>      /* for printf() */
#include <sys/types.h>  /* for Socket data types */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <netinet/in.h> /* for IP Socket data types */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <errno.h>      /* for errno*/

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
    int conn_fd = -1;
    int i;

    /*创建tcp描述符*/
    conn_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(conn_fd == -1)
        handle_error("socket");

    /*指定将连接的server信息*/
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_aton(SRV_IP, &server_addr.sin_addr) == 0)
        handle_error("inet_aton");

    /*连接到server*/
    if(connect(conn_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        handle_error("connect");

    printf("connect to server ip:%s port:%d\n", SRV_IP, PORT);
    for(i = 0; i < SEND_PACK_CNT; i++) {
        sprintf(buf, "Packet %d", i);
        printf("send to server: %s\n", buf);
        /*发送数据*/
        send(conn_fd, buf, strlen(buf) + 1, 0);
        sleep(2);
    }

    /*关闭描述符*/
    printf("close\n");
    close(conn_fd);

    return 0;
}
