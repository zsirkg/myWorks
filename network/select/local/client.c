#include <stdio.h>      /* for printf() */
#include <sys/types.h>  /* for Socket data types */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <sys/un.h>     /* for sockaddr_un */
#include <netinet/in.h> /* for IP Socket data types */
#include <stdlib.h>     /* for exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <errno.h>      /* for errno*/

//macro
#define BUF_SIZE 1024 
#define LOCAL_SERVER_PATH "/tmp/local.server"
#define SEND_PACK_CNT 3
#undef handle_error
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
    struct sockaddr_un server_addr;
    char buf[BUF_SIZE];
    int conn_fd = -1;
    int i;

    /*创建unix域套接字*/
    conn_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(conn_fd == -1)
        handle_error("socket");

    /*指定将连接的server信息*/
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, LOCAL_SERVER_PATH);

    /*连接到server*/
    if(connect(conn_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        handle_error("connect");

    printf("connect to server on path:%s\n", LOCAL_SERVER_PATH);
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
