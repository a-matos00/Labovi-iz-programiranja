#include<stdio.h>
#define MAX 20   //definiramo maksimalni broj stupaca i redaka

void zbroji( int[][MAX], int[][MAX], int[][MAX], int, int);
void unesi(int[][MAX], int, int); 
void ispis(int[][MAX], int, int);  //ova funkcija  nije obavezna u zadatku ali sam je dodao radi prakticnosti
int main()
{
    int A[MAX][MAX], B[MAX][MAX],Rez[MAX][MAX], i, j, red, stup;

    puts("Koliko redova zelite da imaju matrice?");  
    scanf("%d", &red);
    puts("Koliko stupaca zelite da imaju matrice?");
    scanf("%d", &stup);
    
    puts("Unesite vrijednosti u prvu matricu");  //Unosimo vrijednosti u prvu matricu
    unesi(A, red, stup);                        //za unos pozivamo funkciju unesi() koja prim

    puts("");  // razmak

    puts("Unesite vrijednosti u drugu matricu");
    unesi(B, red, stup);

    puts("Prva matrica:");
    ispis(A, red, stup);

    puts("Druga matrica:");
    ispis(B, red, stup);

    zbroji( A, B , Rez, red, stup);  //pozivamo funkciju za zbrajanje matrica

    puts("Reultat zbrajanja matrica");
    
    ispis( Rez, red, stup);  // ispis rezultata zbrajanja
    

    return 0;
}

void zbroji( int A[][MAX], int B[][MAX], int Rez[][MAX], int red, int stup)
{
    int i,j;
    for( i = 0; i < red; i++)
        for(j = 0; j < stup; j++){
           Rez[i][j] = A[i][j] + B[i][j]; //zbrajamo elemente matrica koji su na istim pozicijama
        }
}


void unesi( int X[][MAX],int red, int stup)
{
    int i,j;
    for( i = 0; i < red; i++)
        for(j = 0; j < stup; j++){
            printf("Unesite vrijednost na mjestu (%d,%d)\n", i, j);
            scanf("%d", &X[i][j]);
        }
} 

void ispis( int X[][MAX],int red, int stup)
{
    int i,j;
    for( i = 0; i < red; i++){
        for(j = 0; j < stup; j++){
            printf(" %d",X[i][j]);
        }
        puts("");
    }

    return;
} 
