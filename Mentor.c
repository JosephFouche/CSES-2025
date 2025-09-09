#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    char *target = "127.0.0.1";  // Target host (localhost)
    int start_port = 20, end_port = 1024;
    int sock;
    struct sockaddr_in server;

    printf("Scanning host %s...\n", target);

    for (int port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation failed");
            exit(1);
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(target);

        // Try connecting
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is OPEN\n", port);
        }
        close(sock);
    }

    return 0;
}
