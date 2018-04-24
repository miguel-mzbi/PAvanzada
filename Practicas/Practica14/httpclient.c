#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    char *serverName = argv[1];
    struct hostent *serverIp;
    struct sockaddr_in server;
    int mySocket;
    char *msg = "GET wiki/Main_Page HTTP/1.0\r\n Host: 10.43.102.11 \r\n";
    char buffer[1024];

    serverIp = gethostbyname(serverName);
    memcpy(&server.sin_addr, serverIp->h_addr_list[0], serverIp->h_length);
    server.sin_port = htons(443);
    server.sin_family = AF_INET;
    mySocket = socket(AF_INET, SOCK_STREAM, 0);
    
    if(connect(mySocket, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("CONNECTED!\n");
        write(mySocket, msg, sizeof(msg));
        read(mySocket, buffer, sizeof(buffer));
        printf("Data: %s\n", buffer);
    }
    else {
        printf("Error connecting %d\n", errno);
    }

    return 0;
}