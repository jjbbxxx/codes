#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    socklen_t server_addr_size;

    // �����ͻ���socket
    client_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // ���÷�������ַ��Ϣ
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // ���ӵ�������
    if (connect(client_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect() error");
        exit(1);
    }

    // ʹ��select()ʵ��˫��ͨ��
    fd_set reads, temps;
    int fd_max, str_len, fd_num;
    char buf[BUF_SIZE];

    FD_ZERO(&reads);
    FD_SET(0, &reads);
    FD_SET(client_sock, &reads);
    fd_max = client_sock;

    while (1) {
        temps = reads;
        if (select(fd_max + 1, &temps, 0, 0, NULL) == -1) {
            perror("select() error");
            break;
        }

        for (int i = 0; i < fd_max + 1; i++) {
            if (FD_ISSET(i, &temps)) {
                if (i == 0) {
                    // ��stdin��ȡ���ݲ����͸�������
                    str_len = read(0, buf, BUF_SIZE);
                    if (str_len == 0) {
                        // ����ͨ��
                        FD_CLR(0, &reads);
                        close(client_sock);
                        break;
                    } else {
                        write(client_sock, buf, str_len);
                    }
                } else if (i == client_sock) {
                    // �ӷ�������ȡ���ݲ������stdout
                    str_len = read(client_sock, buf, BUF_SIZE);
                    if (str_len == 0) {
                        // ����ͨ��
                        FD_CLR(client_sock, &reads);
                        close(client_sock);
                        break;
                    } else {
                        write(1, buf, str_len);
                    }
                }
            }
        }
    }

    close(client_sock);
    return 0;
}