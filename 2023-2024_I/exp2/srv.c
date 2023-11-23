// �������˳���
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
		fprintf(stderr, "%s\n", "�����׽��ִ���ʧ�ܡ�");
		exit(-1);
	}
 
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(listenfd, (struct sockaddr *)&server, sizeof(server)) == -1){
		fprintf(stderr, "%s\n", "bindִ��ʧ�ܡ�");
		exit(-1);
	}
 
	if (listen(listenfd, BACKLOG) == -1){
		fprintf(stderr, "%s\n", "��������");
		exit(-1);
	}
 
	sin_size = sizeof(client);
	while(1){
		if ((connectfd = accept(listenfd, (struct sockaddr*)&client, &sin_size)) == -1){
			fprintf(stderr, "%s\n", "accept����");
			exit(-1);
		}
		printf("%s\n", "һ���ͻ������ӣ�");
		char *ip = inet_ntoa(client.sin_addr);
		int port = ntohs(client.sin_port);
		printf("%s%s\n", "�ͻ���IP�ǣ�", ip);
		printf("%s%d;\n", "�ͻ��Ķ˿ں��ǣ�", port);
	}
}