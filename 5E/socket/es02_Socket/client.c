// CLIENT TCP – Invia una stringa al server e attende una risposta

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

#define ServerPort 14503

int main() {

    int socketFD;
    char stringa[50];
    char risposta[50];

    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(ServerPort);

    // Creazione socket
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD < 0) {
        perror("Errore creazione socket");
        exit(1);
    }

    // Connessione al server
    if (connect(socketFD, (struct sockaddr *)&servizio, sizeof(servizio)) < 0) {
        perror("Errore connessione");
        exit(1);
    }

    printf("Inserisci una stringa da inviare al server: ");
    scanf("%s", stringa);

    // Invio stringa al server
    write(socketFD, stringa, strlen(stringa) + 1);

    // Ricezione risposta dal server
    memset(risposta, 0, sizeof(risposta));
    read(socketFD, risposta, sizeof(risposta));

    printf("Risposta del server: %s\n", risposta);

    close(socketFD);
    return 0;
}
