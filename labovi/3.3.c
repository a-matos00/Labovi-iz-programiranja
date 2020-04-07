#include<stdio.h>
#define MAX 100

void slozi(int, int[]);
int main()
{
    int i,n,niz[MAX];  // "n" - kolicina brojeva koje zelimo unijeti u niz
    
    printf("Koliko brojeva zelite upisati u niz\n");
    scanf("%d",&n);

    for( i = 0; i < n; i++){             //unos brojeva u niz
        printf("Unesi %d broj\t", i+1);
        scanf("%d",&niz[i]);
    }

    slozi(n,niz);

    printf("Ispis slozenog niza\n");

    for( i = 0; i < n; i++)
        printf("%d,",niz[i]);

    printf("\n");

    return 0;
}

void slozi(int n, int niz[MAX])
{
    int i,j,pom;

    for( i = 0; i < n-1; i++)       //selection sort
        for( j = i+1; j < n; j++){
            if( niz[j] < niz[i]){
                pom = niz[i];
                niz[i] = niz[j];
                niz[j] = pom;
            }
        }
    return;
}
