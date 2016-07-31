#include <stdio.h>      /* for printf() and fprintf() */
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
#undef max
#define max(x, y) ((x) > (y) ? (x) : (y))
#undef handle_error
#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while(0)

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr;
    struct sockaddr_in conn_addr;
    fd_set read_fds;
    socklen_t len;
    char buf[BUF_SIZE];
    int conn_fd = -1;
    int server_fd = -1;
    int ret;

    /*创建tcp描述符*/
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1)
        handle_error("socket");

    /*指定server信息并绑定*/
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY); //ip地址为任意，只要port满足即可
    
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        handle_error("bind");

    /*监听server描述符*/
    if(listen(server_fd, 5) == -1)
        handle_error("listen");

    printf("accepting connections on port %d\n", PORT);
    while(1) {
        int max_fd = 0;

        FD_ZERO(&read_fds);
        FD_SET(server_fd ,&read_fds);
        max_fd = max(server_fd, max_fd);
        if(conn_fd > 0) {
            FD_SET(conn_fd ,&read_fds);
            max_fd = max(conn_fd, max_fd);
        }
        /*检测描述符集中的描述符的I/O状态*/
        ret = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if(ret == -1 && errno == EINTR)
            continue;

        if(ret == -1)
            handle_error("select");
    
        if(FD_ISSET(server_fd, &read_fds)) { //server_fd可读，即有client连接
            len = sizeof(conn_addr);
            if(conn_fd > 0) { //如果已有连接，则先关闭，因此此server只与最后一次连接的client进行通信
                close(conn_fd);
            }
            /*接受并得到client信息*/
            conn_fd = accept(server_fd, (struct sockaddr *)&conn_addr, &len);
            if(conn_fd == -1)
                handle_error("accept");
            printf("client is connected\n");
            
        } else if(FD_ISSET(conn_fd, &read_fds)) { //conn_fd可读，即接收到client数据
            int n;
            memset(buf, 0, BUF_SIZE);
            n = recv(conn_fd, buf, BUF_SIZE, 0);
            if(n == -1) { //recv函数返回错误
                perror("recv");
                close(conn_fd);
                conn_fd = -1;
            } else if(n == 0) { //client端套接字被关闭
                printf("client is closed\n");
                close(conn_fd);
                conn_fd = -1;
            } else { //读取成功
                /*对收到的数据进行处理*/
                printf("receive data:%s\n", buf);
            }
        }
    }

    /*关闭描述符*/
    printf("close\n");
    close(server_fd);

    return 0;
}
