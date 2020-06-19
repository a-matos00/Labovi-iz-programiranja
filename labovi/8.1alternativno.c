#include<stdio.h>
#include<stdlib.h>
#define N 5 //koristim 5 umisto 10 radi prakticnosti

void slozi( int*[]);
int main()
{
    int i;
    int **pniz; //inicijalzacija pokazivaca na pokazivac
    int niz[N];

    pniz = (int**)malloc( sizeof(int**) * N); //stvaramo "niz pokazivaca"
                                              //dakle pniz je sada pokazivac na niz pokazivaca 
                            //vrijedi: pniz[i] = *(pniz + i) - pristupamo clanovima niza(adresama)
                           // vrijedi: *pniz[i] = **(pniz + i) - vrijednosti clanova niza(adresa)
    for( i = 0; i < N; i++){ //UNOS
        printf("Unesite %d. vrijednost\n", i + 1);
        scanf("%d", &niz[i]);
    }

    puts("Unijeli ste niz: "); //ispis unesenog niza
    for( i = 0; i < N; i++){
        printf("%d, ", niz[i]);
    }
    
    puts(""); //novi red

    for( i = 0; i < N; i++){    //ispunjavamo "pniz" adresama clanova niza niz[N]
        *(pniz + i) = &niz[i];
    }
    
    slozi(pniz);    //sortiranje

    puts("Sortirani niz: ");
    for( i = 0; i < N; i++){        //ispis sortiranog niza
        printf("%d, ", **(pniz + i)); 
    }

    puts("");
    
}

void slozi(int *pniz[])
{
    int i, j, temp;

    for( i = 0; i < N - 1; i++){           //u ovom alternativnoj verziji ne zamjenjujemo adrese
        for( j = i + 1; j < N; j++){       // vec direktno zamjenjujemo vrijednosti, tj. ne sortiramo
            if( **(pniz + i) > **(pniz + j)){ //adrese nego vrijednosti
                temp = **(pniz + i);         
                **(pniz + i) = **(pniz + j);    
                **(pniz + j) = temp;
            }
        }
    }    
    return;  
}
