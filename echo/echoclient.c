#include "nethelp.c"
MAXLINE = 100; 

/* usage ./echoclient host port */

int main(int argc, char *argv[]){
    int clientfd, port; 
    char *host, buf[100];

    host = argv[1];
    port = atoi(argv[2]); 

    clientfd = open_clientfd(host, port);

    while(fgets(buf, 100, stdin) != NULL){
        write(clientfd, buf, strln(buf)); 
        n = read(clientfd, buf, 100);
        write(1, buf, n);

    }

    close(clientfd);
    exit(0); 



}