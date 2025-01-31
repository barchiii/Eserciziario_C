#include <stdio.h>

int main(){
    
    int menu=0;
    
    printf("Scegli che esercizio vuoi eseguire:");
    printf("\n1)Somma e media di n numeri interi\n");
    printf("\n2)Somma e media di massimo 20 numeri maggiori di 5\n");
    printf("\n3)Somma e media di massimo 30 numeri pari e dispari\n");
    printf("\n4)Sconto applicato su somme di denaro\n");
    printf("\n5)Somma e media di n numeri positivi e negativi\n");
    
    
    scanf("%d",&menu);
    
    if(menu==1){
        esercizio1();
    }else if(menu==2){
        esercizio2();
    }else if(menu==3){
        esercizio3();
    }else if(menu==4){
        esercizio4();
    }else if(menu==5){
        esercizio5();
    }else{
        printf("ERRORE");
    }
    
    
    return 0;
}

void esercizio1(){

    int n, num, somma = 0, n2, i = 0; 
    float media;
    printf("Quanti numeri vuoi inserire?\n"); 
    scanf("%d", &n);                          
    n2 = n;
    while (n2 > 0)
    {
        i = i + 1;
        printf("Inserisci il numero %d\n", i);
        scanf("%d", &num);
        somma = somma + num; 
        n2--;
    }

    media = (float)somma / n; 
    printf("\n");
    printf("La somma risulta: %d\n", somma);
    printf("La media risulta: %.2f\n", media);
    
}

void esercizio2(){
    int n, num, somma = 0, vett[30], i, cont = 0;
    float media;

    do
    {
        printf("Quanti numeri vuoi inserire?\n");
        scanf("%d", &n);
    } while (n <= 0 || n > 20);

    for (i = 0; i < n; i++)
    {
        printf("Inserisci un numero\n");
        scanf("%d", &vett[i]); // Prendo il vettore nella posizione i, cosi si andrà a riempire ogni posizione ogni volta che inseriamo un numero
        if (vett[i] > 5)
        {
            cont++;
            somma = somma + vett[i]; // Se non inizializzamo somma il computer gli assegna un valore a random
        }
    }

        printf("\n");
    if (cont > 0)
    {
        media = (float)somma / cont; // Casting, non si possono usare variabili di deu tipi diversi in una stessa assegnazione
        printf("La media dei numeri maggiori di 5 risulta: %.2f\n", media);
    }

    else
        printf("Non ci sono numeri maggiori di 5\n");
    printf("La somma dei numeri maggiori di 5 risulta: %d\n", somma);
}
 void esercizio3(){

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

void esercizio4(){
    float importo=0, totale=0, daPagare=0, sconto=0;
    char scelta;
    
    do{
    printf("Inserisci l'importo ");
    scanf("%f",&importo);
    
    if(importo<=500){
    	sconto=10;
        totale=(importo*sconto)/100;
    }else if(importo>=501 && importo<=1000){
    	sconto=20;
        totale=(importo*sconto)/100;
    }else if(importo>=1001){
    	sconto=30;
        totale=(importo*sconto)/100;
    }
    daPagare=importo-totale;
    printf("IL TOTALE e'': >>> %.2f",daPagare);
    
    printf("\nVuoi inserire un'altro importo?");
    scanf("%s",&scelta);
    }while(scelta!='N' || scelta!='n');
}

void esercizio5(){
    int N, numero;
    int sommaPositivi = 0, sommaNegativi = 0, conteggioPositivi = 0, conteggioNegativi = 0;

    
    printf("Inserisci il numero di elementi (N): ");
    scanf("%d", &N);

    
    for (int i = 0; i < N; ++i) {
        printf("Inserisci il numero %d: ", i + 1);
        scanf("%d", &numero);

        if (numero > 0) {
            sommaPositivi += numero;
            conteggioPositivi++;
        } else if (numero < 0) {
            sommaNegativi += -numero; 
            conteggioNegativi++;
        }
       
    }

    double mediaPositivi = 0.0, mediaNegativi = 0.0;

    if (conteggioPositivi > 0) {
        mediaPositivi = (double)sommaPositivi / conteggioPositivi;
    }

    if (conteggioNegativi > 0) {
        mediaNegativi = (double)sommaNegativi / conteggioNegativi;
    }

    
    printf("\nRisultati:\n");
    printf("Somma positivi: %d\n", sommaPositivi);
    printf("Somma negativi (in valore assoluto): %d\n", sommaNegativi);
    printf("Conteggio dei numeri positivi: %d\n", conteggioPositivi);
    printf("Conteggio dei numeri negativi: %d\n", conteggioNegativi);
    printf("Media positivi: %.2f\n", mediaPositivi);
    printf("Media negativi: %.2f\n", mediaNegativi);
}
