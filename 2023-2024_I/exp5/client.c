#include "unp.h" 
#include <sys/select.h> 

#define PORT 8888
#define ADDR "127.0.0.1"

// ������Ϣ����
#define LOGIN 'L' // �û���¼
#define CHAT 'C' // �û�������ͨ����Ϣ
#define QUIT 'Q' // �û�����quit

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

    // �����������͵�¼��Ϣ����Ϣ����ΪLOGIN����Ϣ����Ϊ�û���
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

            // ������Ϣ���ͽ��в�ͬ�Ĵ���
            switch (buf[0]) {
                case LOGIN: // �û���¼
                    printf("%s login!\n", buf + 1); // ��ӡ��¼���û���
                    break;
                case CHAT: // �û�������ͨ����Ϣ
                    printf("%s: %s\n", buf + 1, buf + 33); // ��ӡ�û�������Ϣ����
                    break;
                case QUIT: // �û�����quit
                    printf("%s quit!\n", buf + 1); // ��ӡ�˳����û���
                    break;
                default: // ��Ч����Ϣ����
                    printf("Invalid message type: %c\n", buf[0]);
                    break;
            }
        }

        if (FD_ISSET(STDIN_FILENO, &rset)) {
            if (fgets(buf + 1, MAXLINE - 1, stdin) == NULL) {
                break;
            }
            // ����������Ϣ��quit����Ϣ����ΪQUIT������ΪCHAT
            if (strcmp(buf + 1, "quit\n") == 0) {
                buf[0] = QUIT;
            } else {
                buf[0] = CHAT;
            }
            n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
            // ������͵���Ϣ��quit���˳�ѭ��
            if (buf[0] == QUIT) {
                break;
            }
        }
    }

    close(sockfd);
    return 0;
}
