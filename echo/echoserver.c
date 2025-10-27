#include <stddef.h>




void * HandleClient (void * arg)
{
    int n; 
    char buf[100];

    int connfd = int(arg); 

    pthread_detach(pthread_self()); 

    while ((n = read(connfd, buf, 100)) > 0){
        printf("server received %d bytes \n", n);
        write(connfd, buf, n);
    }

    close(connfd);
    return NULL; 
}



int main( int argc, char *argv[]){

    int listenfd; 
    int connfd; 
    struct sockaddr clientaddr; 
    int clientlen; 

clientlen = sizeof(clientaddr);
connfd = acccept(listenfd, &clientaddr, &clientlen);


    //int listenfd, connfd, port, clientlen, tid; 
    //struct sockaddr clientaddr; 

    port = atoi(argv[1]); 

    listenfd = open_listenfd(port); 

    clientlen = sizeof(clientaddr); 
    while(1){
        connfd = accept(listenfd, &clientaddr, &clientlen);
        pthread_create(&tid, NULL, HandleClient, (void*)connfd);

    }
}

