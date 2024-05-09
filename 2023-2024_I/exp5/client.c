#include "unp.h" 
#include <sys/select.h> 

#define PORT 8888
#define ADDR "127.0.0.1"

// 定义消息类型
#define LOGIN 'L' // 用户登录
#define CHAT 'C' // 用户发送普通的消息
#define QUIT 'Q' // 用户发送quit

int main(int argc, char **argv) {
    int sockfd, n, maxfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buf[MAXLINE];
    char name[MAXLINE]; 
    fd_set rset; 


    strcpy(name, argv[1]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);



    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ADDR); 
    servaddr.sin_port = htons(PORT);

    // 给服务器发送登录消息，消息类型为LOGIN，消息内容为用户名
    buf[0] = LOGIN;
    strcpy(buf + 1, name);
    n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));



    for (;;) {

        FD_ZERO(&rset);

        FD_SET(sockfd, &rset);
        FD_SET(STDIN_FILENO, &rset);

        maxfd = max(sockfd, STDIN_FILENO);


        select(maxfd + 1, &rset, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &rset)) {
            len = sizeof(cliaddr);
            n = recvfrom(sockfd, buf, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
            buf[n] = '\0'; 

            // 根据消息类型进行不同的处理
            switch (buf[0]) {
                case LOGIN: // 用户登录
                    printf("%s login!\n", buf + 1); // 打印登录的用户名
                    break;
                case CHAT: // 用户发送普通的消息
                    printf("%s: %s\n", buf + 1, buf + 33); // 打印用户名和消息内容
                    break;
                case QUIT: // 用户发送quit
                    printf("%s quit!\n", buf + 1); // 打印退出的用户名
                    break;
                default: // 无效的消息类型
                    printf("Invalid message type: %c\n", buf[0]);
                    break;
            }
        }

        if (FD_ISSET(STDIN_FILENO, &rset)) {
            if (fgets(buf + 1, MAXLINE - 1, stdin) == NULL) {
                break;
            }
            // 如果输入的消息是quit，消息类型为QUIT，否则为CHAT
            if (strcmp(buf + 1, "quit\n") == 0) {
                buf[0] = QUIT;
            } else {
                buf[0] = CHAT;
            }
            n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
            // 如果发送的消息是quit，退出循环
            if (buf[0] == QUIT) {
                break;
            }
        }
    }

    close(sockfd);
    return 0;
}
