// SERVER TCP – Riceve una stringa dal client e risponde con un messaggio di conferma

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

    int socketFD, soa;
    socklen_t fromlen;
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

    // Associazione indirizzo/porta al socket
    if (bind(socketFD, (struct sockaddr *)&servizio, sizeof(servizio)) < 0) {
        perror("Errore bind");
        exit(1);
    }

    // Messa in ascolto
    listen(socketFD, 10);

    printf("SERVER AVVIATO – In ascolto...\n");

    while (1) {

        fromlen = sizeof(servizio);
        soa = accept(socketFD, (struct sockaddr *)&servizio, &fromlen);

        if (soa < 0) {
            perror("Errore accept");
            continue;
        }

        // Pulizia buffer
        memset(stringa, 0, sizeof(stringa));

        // Ricezione messaggio
        int n = read(soa, stringa, sizeof(stringa));
        if (n > 0) {
            printf("Stringa ricevuta: %s\n", stringa);
            strcpy(risposta, "Messaggio ricevuto correttamente!");
        } else {
            strcpy(risposta, "Errore: nessun messaggio ricevuto.");
        }

        // Invio risposta al client
        write(soa, risposta, strlen(risposta) + 1);

        close(soa);
    }

    close(socketFD);
    return 0;
}
