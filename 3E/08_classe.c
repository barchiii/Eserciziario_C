/* Scrivere un programma in C che dopo aver inserito
i cognomi e i voti di una classe di studenti
determini e/o verifichi: 
1) La media dei voti visualizzando, inoltre il numero di studenti inseriti;   
 2) Il voto massimo, il voto minimo ed I relativi cognomi degli studenti  
 3) Il numero degli studenti che hanno una valutazione sufficiente o superiore
 4) Il numero degli studenti che hanno una valutazione insufficiente o inferiore;   
 5) Il numero di studenti che hanno un voto compreso tra 7.50 e 10 estremi inclusi.
Il programma deve permettere il re-inserimento degli studenti e dei relativi voti. */

#include <stdio.h>
#include<string.h>
int main() {

    int nStundenti = 20;
    int  i = 0, k = 0, j = 0;
    float somma = 0;
    float media = 0;
    char risposta = 's';
    int contSuff = 0, contInsuff = 0, contBravi = 0, nStudenti = 0;
    int votoMin = 0, votoMax = 0;
    	
    // Dichiarazione degli array
    char studenti[20];
    float voti[20];
    
    do{
    	nStudenti++;
    	
        // Popolamento
        printf("\nInserisci il nome dello studente: \n");
        scanf("%s", &studenti[nStudenti]);

        printf("\nInserisci il voto dello studente: \n");
        scanf("%d", &voti[nStudenti]);
        
        // Inserimento altri studenti
        printf("\nVuoi inserire un altro studente? Scrivi 's' per continuare o premi un tasto per annullare\n");
        scanf("%s", &risposta);
        
    } while (risposta == 's');
    
    // Calcolo studenti della classe
    printf("Gli studenti della classe sono: %d\n", nStudenti);
    
    // Calcolo della media
    
    for (i = 0; i < nStudenti; i++) {
    	somma = somma + voti[i];
	}

    media = somma / nStudenti;
    printf("La media dei voti della classe e': %d\n", media);

    // Voto massimo e minimo
    for(k = 0; k < nStudenti; k++){
		if (voti[k] > votoMax) {
			votoMax = voti[k];
		}
		if (voti[k] < votoMin){
			votoMin = voti[k];
		}
	}
	printf("Il voto massimo della classe è: %d\n di %s", votoMax, studenti[k]);
	printf("Il voto minimo della classe è: %d\n di %s", votoMin, studenti[k]);
	
	
	// Conteggio sufficenti e insufficenti
	for (j = 0; j < nStudenti; j++) {
		if (voti[nStudenti] >= 6 )
        	contSuff++;

        if (voti[nStudenti] >= 7.50 && voti[nStudenti] <= 10)
        	contBravi++;
        
    	else 
        	contInsuff++;
	}
	
    // Voto sufficente o superiore
    printf("Il numero degli studenti con valutazione di 6 o superiore sono: %d\n", contSuff);

    // Voti insufficenti e insufficenti
    printf("Gli studenti con valutazione sufficente sono: %d\n", contSuff);
    printf("Gli studenti con valutazione insufficente sono: %d\n", contInsuff);

    // Voti superiori a 7.50
    printf("Gli studenti con valutazione superiore a 7.50 sono: %d\n", contBravi);
    
    return 0;
}
