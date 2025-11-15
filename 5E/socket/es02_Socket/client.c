// CLIENT TCP – Invia una stringa al server e attende una risposta

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

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
