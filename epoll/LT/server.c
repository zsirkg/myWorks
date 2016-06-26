#include <stdio.h> // for printf()
#include <stdlib.h> // for exit()
#include <unistd.h> // for read() and write()
#include <sys/epoll.h> // for epoll
#include <sys/socket.h> // for epoll
#include <netinet/in.h> //struct sockaddr_in
#include <string.h> // memset
#include <fcntl.h> // fcntl
#include <errno.h> // errno

#define EPOLL_QUEUE_LEN 32 //监听的最大连接数
#define BUF_SIZE 1024

static int listen_socket(int port)
{
    int fd;
    struct sockaddr_in sa;


    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1) {
        perror("socket");
        return -1;
    }
    
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(fd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("bind");
        close(fd);
        return -1;
    }

    if(listen(fd, 5) == -1) {
        perror("listen");
        close(fd);
        return -1;
    }

    return fd;
}

int main(int argc, char **argv)
{
    struct epoll_event ev;
    struct epoll_event events[EPOLL_QUEUE_LEN];
    int epfd;
    int sfd;
    int nfds;

    if(argc != 2) {
        printf("usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*创建 epoll 实例*/
    epfd = epoll_create(EPOLL_QUEUE_LEN);
    if(epfd == -1) {
        perror("epoll_create");
        exit(EXIT_FAILURE);
    }

    /*对输入port进行监听*/
    printf("server listen form port: %d\n", atoi(argv[1]));
    sfd = listen_socket(atoi(argv[1]));
    if(sfd == -1) {
        printf("listen_socket failed\n");
        exit(EXIT_FAILURE);
    }

    /*将server描述符添加到epoll中*/
    ev.data.fd = sfd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epfd, EPOLL_CTL_ADD, sfd, &ev) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    /*主循环*/
    while(1) {
        int i;

        /*等待epoll实例中描述符有I/O事件发生*/
        nfds = epoll_wait(epfd, events, EPOLL_QUEUE_LEN, -1);
        for(i = 0; i < nfds; i++) {
            if(events[i].events & (EPOLLERR | EPOLLHUP)) {
                //EPOLLERR - 出现错误
                //EPOLLHUP - 客户端提前关闭连接(close by peer)
                continue;
            }

            if(!(events[i].events & EPOLLIN)) { //不是IN操作
                continue;
            }

            if(sfd == events[i].data.fd) { 
                /*有客户端连入server*/
                struct sockaddr_in in_addr;
                socklen_t in_len;
                int infd;

                infd = accept(sfd, (struct sockaddr *)&in_addr, &in_len);
                if(infd == -1) {
                    perror("accept");
                    continue;
                }

                ev.data.fd = infd;
                ev.events = EPOLLIN;
                if(epoll_ctl(epfd, EPOLL_CTL_ADD, infd, &ev) == -1) {
                    perror("epoll_ctl");
                    exit(EXIT_FAILURE);
                }
                printf("incoming client [fd=%d]\n", infd);
            } else {
                /*收到客户端数据*/
                ssize_t cnt;
                char buf[BUF_SIZE];

                memset(buf, 0, sizeof(buf));
                cnt = read(events[i].data.fd, buf, sizeof(buf));
                if(cnt == -1) {
                    perror("read");
                } else if (cnt == 0) { //fd 被关闭
                    printf("remote close fd\n");
                } else {
                    printf("receive data: %s\n", buf);
                }

                printf("close client [fd=%d]\n", events[i].data.fd);
                close(events[i].data.fd);
            } 
        }
    }

    close(sfd);

    return 0;
}
