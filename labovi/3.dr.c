/*
Unosite niz cjelobrojnih vrijednosti (max 100) dok se ne unese broj 0.
  Poredati unesene brojeve od najvećeg prema najmanjem u posebnoj funkciji
 sortiraj. ???Zamjenu izvršiti u posebnoj funkciji zamjena (po adresama).???
 U posebnoj funkciji par_nepar prebrojati parne i neparne brojeve i ispisati ih u main
 funkciji.
*/

//NIJE DOVRSENO - radi samo unos i ispis niza

#include<stdio.h>
#define MAX 100

void sortiraj(int, int []);
void par_nepar(int, int [],int [],int [],int *,int *);

int main()
{
    int i; 
    int niz[MAX];
    int n = 0;
    
    printf("Unesite clanove u niz (max 100), za prekid upisite nulu\n");

    for( i = 0; i < MAX; i++){  // petlja se vrti sve do maksimalne duljine niza
        printf("Unesite %d clan niza\n", i+1);
        scanf("%d",&niz[i]);   //
        n++;                  //racunamo kolicinu upisanih clanova da poslije nebi ispisivali neupisane vrijednosti
        
        if(niz[i] == 0){
            n--;        // necemo racunat nulu kao clan niza pa moramo uklonit jedno mjesto koje je dodjeljeno nuli
            break;      //zaustavljamo petlju kad upisemo
        }
    }

    for( i = 0; i < n; i++){   //ispis niza
        printf("%d,",niz[i]);
    }

    printf("\n");
    
    
    return 0;
}
