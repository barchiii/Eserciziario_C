/*Dopo aver letto N numeri (interi),
con N scelto dall'utente
e non superiore ai 30 elementi,
calcolare la somma e la media dei numeri pari,
e dei numeri dispari (utilizzare %).
*/

#include <stdio.h>
void main() {
	int N, num[30], pari=0, dispari=0, i;
	int sommaP=0, sommaD=0;
	float mediaP, mediaD;

	do {
		printf("Quanti numeri interi vuoi inserire?\n");
		scanf("%d", &N);
	} while (N<=0 || N>30);

	for (i=0; i<N; i++) { //inizio for
		printf("Inserisci un numero\n");
		scanf("%d", &num[i]);

		if(num[i]%2==0) {
			pari++;
			sommaP=sommaP+num[i];
		}

		else {
			dispari++;
			sommaD=sommaD+num[i];
		}

	} // fine for

	mediaP=sommaP/pari;
	mediaD=sommaD/dispari;

	// output
	printf("Sono stati inseriti %d numeri pari e %d numeri dispari\n", pari, dispari);
	printf("La somma dei numeri pari e': %d\n", sommaP);
	printf("La media dei numeri pari e': %.2f\n", mediaP);
	printf("\n");
	printf("La somma dei numeri dispari e': %d\n", sommaD);
	printf("La media dei numeri dispari e': %.2f\n", mediaD);
}
