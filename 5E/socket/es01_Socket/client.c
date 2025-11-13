// Librerie standard Socket
#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>      // file header che consente l'accesso alle API dello standard POSIX

#define ServerPort 14503 //porta di comunicazione

int main() {
    struct sockaddr_in servizio; //struttura dati per la comunicazione

    servizio.sin_family = AF_INET;                //famiglia di protocolli
    servizio.sin_addr.s_addr = htonl(INADDR_ANY); //accetta connession
    servizio.sin_port = htons(ServerPort);        //porta di comunicazione
    char stringa[20];                             //buffer di comunicazione

    int socketFD;                                 //file descriptor del socket

    socketFD = socket(AF_INET, SOCK_STREAM, 0);   //creazione socket TCP
    connect(socketFD, (struct sockaddr *)&servizio, sizeof(servizio)); //richiesta di connessione al server

    printf("Inserisci una stringa da inviare al server: ");
    scanf("%s", stringa);                         //lettura stringa da inviare
    write(socketFD, stringa, sizeof(stringa) + 1); //invio stringa al server
    close(socketFD);                              //chiusura socket
    
    return 0;
}