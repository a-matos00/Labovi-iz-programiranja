#include<stdio.h>
#include<malloc.h>

void unos(char *, int); //funkcija za unos clanova niza(nije obavezna)
void ispis(char *, int); //funkcija za ispis clanova niza(nije obavezna)

int main()
{
    char *pniz; //incijalizacija pokazivaca koji cemo koristit za inicijalizirat niz
    int n;
    
    puts("Unesite velicinu niza"); //unos velicine niza
    scanf("%d", &n);

    pniz = (char*)malloc(sizeof(char) * n);     //alokacija memorije

    unos(pniz, n); //poziv funkcije za unos clanova niza

    puts("Ispis niza");    
    ispis(pniz, n);     //ispis niza
        
    return 0;
}

void ispis(char *pniz, int n)
{
    int i;

    for(i = 0; i < n; i++){
        printf("%c, ", *(pniz + i));
    }
    return;
}

void unos(char *pniz, int n)
{
    int i;

    for(i = 0; i < n; i++){
        printf("Unesite %d. clan niza\n", i + 1);
        scanf(" %c", pniz + i);
    }
    return;
}
