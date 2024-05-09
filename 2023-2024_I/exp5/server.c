#include "unp.h"
#include <sys/select.h> 

#define PORT 8888
#define MAXCLIENT 10 

// 定义消息类型
#define LOGIN 'L' // 用户登录
#define CHAT 'C' // 用户发送普通的消息
#define QUIT 'Q' // 用户发送quit

struct client {
    struct sockaddr_in addr; 
    char name[MAXLINE]; 
    int active; 
};

struct client clients[MAXCLIENT];

void init_clients() {
    int i;
    for (i = 0; i < MAXCLIENT; i++) {
        clients[i].active = 0; 
    }
}

void add_client(struct sockaddr_in *addr, char *name) {
    int i;
    for (i = 0; i < MAXCLIENT; i++) {
        if (clients[i].active == 0) { 
            clients[i].addr = *addr; 
            strcpy(clients[i].name, name); 
            clients[i].active = 1; 
            break;
        }
    }
}

void delete_client(struct sockaddr_in *addr) {
    int i;
    for (i = 0; i < MAXCLIENT; i++) {
        if (clients[i].active == 1 && clients[i].addr.sin_addr.s_addr == addr->sin_addr.s_addr && clients[i].addr.sin_port == addr->sin_port) { 
            clients[i].active = 0; 
            break;
        }
    }
}

void send_to_all(char *msg, struct sockaddr_in *from, int sockfd) {
    int i, n;
    for (i = 0; i < MAXCLIENT; i++) {
        if (clients[i].active == 1 && !(clients[i].addr.sin_addr.s_addr == from->sin_addr.s_addr && clients[i].addr.sin_port == from->sin_port)) { 
            n = sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&clients[i].addr, sizeof(clients[i].addr));
        }
    }
}

int main() {
    int sockfd, n, maxfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buf[MAXLINE];
    fd_set rset; 


    sockfd = socket(AF_INET, SOCK_DGRAM, 0);



    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);


    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {

    }

    init_clients();

    for (;;) {

        FD_ZERO(&rset);

        FD_SET(sockfd, &rset);

        maxfd = sockfd;


        if (select(maxfd + 1, &rset, NULL, NULL, NULL) < 0) {

        }


        if (FD_ISSET(sockfd, &rset)) {

            len = sizeof(cliaddr);
            n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);

            buf[n] = '\0'; 

            // 根据消息类型进行不同的处理
            switch (buf[0]) {
                case LOGIN: // 用户登录
                    printf("Username: %s, ip:%s, port:%d\n", buf + 1, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    add_client(&cliaddr, buf + 1); // 将客户端的地址信息存储起来
                    send_to_all(buf, &cliaddr, sockfd); // 将该客户端发送的name发给所有其他的已登录的客户端
                    break;
                case CHAT: // 用户发送普通的消息
                    printf("Username: %s, ip:%s, port:%d, message: %s\n", clients[i].name, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port), buf + 1);
                    send_to_all(buf, &cliaddr, sockfd); // 将该消息转发给其他客户端
                    break;
                case QUIT: // 用户发送quit
                    printf("Username: %s, ip:%s, port:%d, quit\n", clients[i].name, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
                    delete_client(&cliaddr); // 将已存储的地址信息删除
                    send_to_all(buf, &cliaddr, sockfd); // 将该消息转发给其他客户端
                    break;
                default: // 无效的消息类型
                    printf("Invalid message type: %c\n", buf[0]);
                    break;
            }
        }
    }


    close(sockfd);

    return 0;
}
