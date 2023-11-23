#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    // 创建服务器socket
    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // 设置服务器地址信息
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // 绑定socket到服务器地址
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind() error");
        exit(1);
    }

    // 开始监听
    if (listen(server_sock, 1) == -1) {
        perror("listen() error");
        exit(1);
    }

    client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_size);
    if (client_sock == -1) {
        perror("accept() error");
        exit(1);
    }

    // 使用select()实现双向通信
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
                    // 从stdin读取数据并发送给客户端
                    str_len = read(0, buf, BUF_SIZE);
                    if (str_len == 0) {
                        // 结束通信
                        FD_CLR(0, &reads);
                        close(client_sock);
                        break;
                    } else {
                        write(client_sock, buf, str_len);
                    }
                } else if (i == client_sock) {
                    // 从客户端读取数据并输出到stdout
                    str_len = read(client_sock, buf, BUF_SIZE);
                    if (str_len == 0) {
                        // 结束通信
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

    close(server_sock);
    return 0;
}