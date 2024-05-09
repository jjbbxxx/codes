#include "unp.h"
#include <sys/select.h> 

#define PORT 8888
#define MAXCLIENT 10 


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


            printf("Username: %s, ip:%s, port:%d\n", buf, inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));


            add_client(&cliaddr, buf);


            send_to_all(buf, &cliaddr,sockfd);
        }
    }


    close(sockfd);

    return 0;
}
