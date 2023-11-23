// ¿Í»§¶Ë³ÌÐò
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
 
int sockfd;
const char* ip_string = "127.0.0.1";
const int port = 65531; 
int main(){
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1){
		printf("%s\n", "socket create failed");
		exit(-1);
	}
 
	struct sockaddr_in srv_addr;
	socklen_t addrlen;
	addrlen = sizeof(srv_addr);
	memset(&srv_addr, 0, addrlen);
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	srv_addr.sin_port = htons(port);
 
	while (1){
		if (connect(sockfd, (struct sockaddr*)&srv_addr, sizeof(srv_addr))
			== -1)
		{
			printf("connect error!\n");
			sleep(1);
			continue;
		}
		else
			break;
	}		
}