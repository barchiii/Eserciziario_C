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

    int socketFD, soa fromlen = sizeof(servizio); //file descriptor del socket

    socketFD = socket(AF_INET, SOCK_STREAM, 0);   //creazione socket TCP

    bind(socketFD, (struct sockaddr *)&servizio, sizeof(servizio)); //bind del socket alla struttura dati
    listen(socketFD, 10); //messa in ascolto del socket

    while (1) {
        printf("Server in ascolto...\n");
        fflush(stdout);
        soa = accept(socketFD, (struct sockaddr *)&servizio, &fromlen); //accettazione connessione dal client

        read(soa, stringa, sizeof(stringa) + 1); //lettura stringa inviata dal client
        printf("Stringa ricevuta dal client: %s\n", stringa); //stampa della stringa ricevuta

        close(soa); //chiusura socket di accettazione
    }

    return 0;
}