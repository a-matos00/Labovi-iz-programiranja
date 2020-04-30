#include<stdio.h>
#define MAX 10
void slozi(int *[]); // "int *[]" je polje pokazivaca
int main()
{
    int niz[MAX], *pniz[MAX];   // 1. niz brojeva, 2. niz pokazivaca
    int i;
    
    for( i = 0; i < MAX; i++){         //unosimo brojeve u niz
        printf("Unesite %d. clan niza\n", i + 1);
        scanf("%d", &niz[i]);        // brojevi se spremaju u niz[] koji se nalazi na stacku
        pniz[i] = &niz[i];           // adrese nizova se spremaju na niz pokazivaca na heapu
    }

    puts("Ispis niza"); 

    for(i = 0; i < MAX; i++)   //ispisujemo upisani niz brojeva(stack)
        printf("%d, ", niz[i]);
    
    puts("");
    
    slozi(pniz); //slazemo niz pokazivaca na heapu

    for( i = 0; i < MAX; i++){  //ispis vrijednosti pokazivaca iz niza pokazivaca(heap)
        printf("%d, ", *pniz[i]);  //zvijezdica oznacava vrijednost na adresi pniz[i]
    }
    
    return 0;
}

void slozi( int *pniz[])
{
    int i,j;
    int *tmp;  //inicijalizacija pomocnog pokazivaca
    
    for( i = 0; i < MAX - 1; i++){           //selection sort
        for( j = i + 1; j < MAX; j++){
            if( *pniz[i] > *pniz[j]){    //prijevod: ako je vrijednost na adresi pniz[i] veca od one na pniz[j] 
                tmp = pniz[i];        //vazno je primjetit da ovdje radimo sa adresama a ne sa vrijednostima
                pniz[i] = pniz[j];    //slazemo adrese na temelju koja sadrzi vecu vrijednost
                pniz[j] = tmp;
            }
        }
    }    
    return;
}


/*  Zadatak se svodi na to da inicijaliziramo dva niza, jedan privremeni("niz[]" na stacku i drugi *pniz[] 
    heapu.
    Prvi niz je niz brojeva, a drugi niz pokazivaca.
    Kad unesemo brojeve u niz brojeva njihove vrijednosti dodjelimo pokazivacima koji se nalaze u nizu
    pokazivaca.
    Pozivamo funkciju slozi() koja slaze pokazivace niza po velicini broja koji je dodjeljen adresi na
    koju pokazuju.
    
*/
