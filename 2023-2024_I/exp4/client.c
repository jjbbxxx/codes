#include "unp.h" 
#include <sys/select.h> 

#define PORT 8888
#define ADDR "127.0.0.1"

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

    n = sendto(sockfd, name, strlen(name), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));



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


            printf("%s login!\n", buf);
        }

        if (FD_ISSET(STDIN_FILENO, &rset)) {
            if (fgets(buf, MAXLINE, stdin) == NULL) {
                break;
            }
            n = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
            
        }
    }

    close(sockfd);
    return 0;
}
