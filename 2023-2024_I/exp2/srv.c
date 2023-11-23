// 服务器端程序
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
 
#define PORT 65531
#define BACKLOG 1
 
int main(){
	int listenfd, connectfd;
	struct sockaddr_in server, client;
	socklen_t sin_size;
 
	if((listenfd=socket(AF_INET, SOCK_STREAM, 0)) == -1){
		fprintf(stderr, "%s\n", "监听套接字创建失败。");
		exit(-1);
	}
 
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1){
		fprintf(stderr, "%s\n", "bind执行失败。");
		exit(-1);
	}
 
	if (listen(listenfd, BACKLOG) == -1){
		fprintf(stderr, "%s\n", "监听错误");
		exit(-1);
	}
 
	sin_size = sizeof(client);
	while(1){
		if ((connectfd = accept(listenfd, (struct sockaddr*)&client, &sin_size)) == -1){
			fprintf(stderr, "%s\n", "accept错误");
			exit(-1);
		}
		printf("%s\n", "一个客户端连接：");
		char *ip = inet_ntoa(client.sin_addr);
		int port = ntohs(client.sin_port);
		printf("%s%s\n", "客户的IP是：", ip);
		printf("%s%d;\n", "客户的端口号是：", port);
	}
}