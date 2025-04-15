#include <stdio.h>
#include <math.h>

// Funzioni per le operazioni
double somma(double a, double b)
{
    return a + b;
}

double sottrazione(double a, double b)
{
    return a - b;
}

double moltiplicazione(double a, double b)
{
    return a * b;
}

double divisione(double a, double b)
{
    if (b != 0)
        return a / b;
    else
    {
        printf("Errore: divisione per zero!\n");
        return 0;
    }
}

double potenza(double base, double esponente)
{
    return pow(base, esponente);
}

double radice(double numero)
{
    if (numero >= 0)
        return sqrt(numero);
    else
    {
        printf("Errore: radice quadrata di numero negativo!\n");
        return 0;
    }
}

/*
// Funzione menu
void mostra_menu()
{
    printf("\n--- Calcolatrice ---\n");
    printf("1. Somma\n");
    printf("2. Sottrazione\n");
    printf("3. Moltiplicazione\n");
    printf("4. Divisione\n");
    printf("5. Potenza\n");
    printf("6. Radice quadrata\n");
    printf("0. Esci\n");
    printf("Scegli un'opzione: ");
}


int main() {
    int scelta;
    double num1, num2, risultato;

    do {
        mostra_menu();
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Inserisci due numeri: ");
                scanf("%lf %lf", &num1, &num2);
                risultato = somma(num1, num2);
                printf("Risultato: %.2lf\n", risultato);
                break;

            case 2:
                printf("Inserisci due numeri: ");
                scanf("%lf %lf", &num1, &num2);
                risultato = sottrazione(num1, num2);
                printf("Risultato: %.2lf\n", risultato);
                break;

            case 3:
                printf("Inserisci due numeri: ");
                scanf("%lf %lf", &num1, &num2);
                risultato = moltiplicazione(num1, num2);
                printf("Risultato: %.2lf\n", risultato);
                break;

            case 4:
                printf("Inserisci due numeri: ");
                scanf("%lf %lf", &num1, &num2);
                risultato = divisione(num1, num2);
                printf("Risultato: %.2lf\n", risultato);
                break;

            case 5:
                printf("Inserisci base ed esponente: ");
                scanf("%lf %lf", &num1, &num2);
                risultato = potenza(num1, num2);
                printf("Risultato: %.2lf\n", risultato);
                break;

            case 6:
                printf("Inserisci un numero: ");
                scanf("%lf", &num1);
                risultato = radice(num1);
                printf("Risultato: %.2lf\n", risultato);
                break;

            case 0:
                printf("Uscita in corso... Ciao!\n");
                break;

            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);

    return 0;
}
*/
