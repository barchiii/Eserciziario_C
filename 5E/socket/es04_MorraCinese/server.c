/* Realizzare il gioco della Morra Cinese utilizzando le socket in linguaggio C 
   dove il server è il giocatore numero 1 ed il client il giocfatore numero 2. 
   Utilizzare l'elaborazione sequenziale. */

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
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int scelta_client, scelta_server;
    int punteggio_server = 0, punteggio_client = 0;

    printf("Server in ascolto sulla porta 12345...\n");

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Errore creazione socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Errore bind");
        exit(1);
    }

    listen(server_fd, 1);

    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Errore accept");
        exit(1);
    }

    printf("Client connesso.\n");

    while (1) {
        recv(client_fd, &scelta_client, sizeof(int), 0);

        if (scelta_client == 9) {
            printf("Connessione terminata dal client.\n");
            break;
        }

        scelta_server = rand() % 3;

        printf("Client ha scelto: %s\n", 
            (scelta_client == 0) ? "Sasso" :
            (scelta_client == 1) ? "Carta" : "Forbice");

        printf("Server sceglie: %s\n", 
            (scelta_server == 0) ? "Sasso" :
            (scelta_server == 1) ? "Carta" : "Forbice");

        int risultato = 0;   // 0 = pareggio, 1 = vince client, 2 = vince server

        if (scelta_client == scelta_server) risultato = 0;
        else if ((scelta_client == 0 && scelta_server == 2) ||
                 (scelta_client == 1 && scelta_server == 0) ||
                 (scelta_client == 2 && scelta_server == 1)) risultato = 1;
        else risultato = 2;

        if (risultato == 1) punteggio_client++;
        if (risultato == 2) punteggio_server++;

        send(client_fd, &scelta_server, sizeof(int), 0);
        send(client_fd, &risultato, sizeof(int), 0);
        send(client_fd, &punteggio_server, sizeof(int), 0);
        send(client_fd, &punteggio_client, sizeof(int), 0);

        printf("Risultato: %s\n", (risultato == 0) ? "Pareggio" :
                                  (risultato == 1) ? "Client vince" : "Server vince");
        printf("Punteggio: Server %d Client %d\n-------------\n",
            punteggio_server, punteggio_client);
    }

    close(client_fd);
    close(server_fd);

    return 0;
}
