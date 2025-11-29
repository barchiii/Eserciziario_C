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
    int sock;
    struct sockaddr_in server_addr;
    int scelta, scelta_server, risultato;
    int p_server, p_client;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Errore socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Errore connect");
        exit(1);
    }

    printf("Connesso al server.\n");

    while (1) {
        printf("Scegli (0: Sasso, 1: Carta, 2: Forbice, 9 per uscire): ");
        scanf("%d", &scelta);

        send(sock, &scelta, sizeof(int), 0);

        if (scelta == 9) break;

        recv(sock, &scelta_server, sizeof(int), 0);
        recv(sock, &risultato, sizeof(int), 0);
        recv(sock, &p_server, sizeof(int), 0);
        recv(sock, &p_client, sizeof(int), 0);

        printf("Server ha scelto %s\n",
            (scelta_server == 0) ? "Sasso" :
            (scelta_server == 1) ? "Carta" : "Forbice");

        printf("Risultato: %s\n",
            (risultato == 0) ? "Pareggio" :
            (risultato == 1) ? "Client vince" : "Server vince");

        printf("Punteggio: Server %d Client %d\n-------------\n", p_server, p_client);
    }

    close(sock);
    return 0;
}
