/*  pniz = (int *)malloc(n * sizeof(int)); 
    alokacija memorije = rezerviranje mjesta u memoriji
    alokaciju memorije vrsimo funkcijom malloc() koja za argument prima velicinu memorije koju treba alocirati
    za velicinu je najbolje koristiti sizeof() koji za argument prima vrstu podatak niza npr. int. sizeof() funkciju unutar
    argumenta malloc() funkcije mnozimo sa velicinom niza.
    Primjer malloc(sizeof(int) * 10) ==> malloc( 4 * 10) ==> malloc(40) ==> alocirat ce se 40 bajtova memorije jer je velicina
    int tipa datoteke 4 bajta.
    
    Kada koristimo malloc() onda ni ne moramo incijalizirati niz. Da bi razumili zasto treba pogledat sta zapravo radi incijalizacija
    niza.

    1. ako napisemo int niz[5], program ce rezrvirati dovoljno memorije za 5 podataka vrste int na stacku
    2. funkcija malloc( 5 * sizeof(int)) radi isto to ali na heapu.

    Kada kazu da koristimo aritmetiku pokazivaca to znaci da ne inicijaliziramo niz na stack vec na heap te radimo s njim
    koristeci pokazivace.

  
*/

#include<stdio.h>
#include<malloc.h>

void slozi(int, int *);  //prototip funkcije za slaganje niza po velicine, argumenti su velicina niza i adresa prvog clana
int main()
{
    int n,i;
    int *pniz; 
    
    puts("Unesite zeljenu velicinu niza");
    scanf("%d", &n);
    
    pniz = (int *)malloc(n * sizeof(int)); //objasnjeno na vrhu

    for( i = 0; i < n; i++){
        printf("Unesite %d. clan niza\n", i);
        scanf("%d", pniz + i);
    }
    puts("Ispis niza");
    for( i = 0; i < n; i++){
        printf("%d, ", *(pniz + i));
    }
    puts("");
    slozi(n,pniz);
     puts("Ispis niza");
    for( i = 0; i < n; i++){
        printf("%d, ", *(pniz + i));
    }
   
}

void slozi( int n, int *p)
{
    int i,j,temp;

    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++){
            if( *(p + i) > *(p + j)){
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    return;
}
