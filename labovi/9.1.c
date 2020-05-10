/*
    VAZNO!!!
    1D nizove smo mogli raditi sa pokazivacima na neki tip datoteke "*p" (npr. int *pniz)
        a)takav niz sadrzi samo jednu dimenziju ==> STUPCE
        b)stoga nakon alokacije memorije uz pomoc malloc() funkcije mozemo umjesto: *(pniz + i) koristiti pniz[i] jer
          smo prakticki napravili niz.
          
    
    2D nizove(MATRICE) radimo koristeci pokazivace na pokazivac.
        a) Obicni pokazivac se odnosi na jedan redak matrice koji sadrzi vise stupaca
        b) Pokazivac na pokazivac sadrzi vise redaka i preko njega mozemo pristupati vrijednostima tih redaka
        c) Nakon alokacije memorije uz pomoc malloc() funlcije mozemo umjesto *(*(pniz + i) + j) koristiti pniz[i][j]
           jer smo prakticki napravili matricu. Redci pokazuju na pokazivac koji sadrzi niz, a stupac redno mjesto u nizu
           odredenog znaka.

    1. Prvo alociramo memoriju za niz pokazivaca
        a) Njena velicina je umnozak sizeof( pokazivac na odredeni tip podatka) * broj redaka matrice
        b) Povratnu vrijednost castamo u (int**) jer je pokazivac na retke vrste int**
    2. Zatim alociramo memoriju za svaki red brojeva
        a) Njena velicina je umnozak sizeof( tip podataka) * broj stupaca
        b) Povratnu vrijednost castamo u (int*) jer je pokazivac na niz vrste int*
        c) Koristimo for petlju jer imamo vise redaka, dok za prijasnju alokaciju nismo trebali jer postoji samo jedan
            niz redaka.
*/


#include<stdio.h>
#include<malloc.h>

int **zbrmat(int **, int **, int, int); //funkcija prima adrese matrica i dimenzije
void unmat(int **, int, int); //prima matricu i dimenzije
int main()
{
    int i,j,red,stup;
    int **a, **b, **c; //inicijalizacija pokazivaca na matrice

    puts("Koliko redaka?");  //upisujemo dimenzije matrica
    scanf("%d", &red);
    puts("Koliko stupaca?");
    scanf("%d", &stup);

    
    a = (int**)malloc(sizeof(int *) * red); //alociramo memoriju za redove
    b = (int**)malloc(sizeof(int *) * red);
        
    for(i = 0; i < red; i++){
        *(a + i) = (int*)malloc(sizeof(int) * stup); //alociramo memoriju za stupce
        *(b + i) = (int*)malloc(sizeof(int) * stup);
    }

    puts("Unesite prvu matricu");
    unmat(a, red, stup); //funcije za unos brojeva u matrice
    puts("Unesite drugu matricu");
    unmat(b, red, stup);

    c = zbrmat(a, b ,red,stup); //funkcija za zbrajanje

    for( i = 0; i < red; i++){              //ispis "a" matrice
        for( j = 0; j < stup; j++){
            printf("%4d", *(*(a + i) + j )); // radi jednostavnosti mozemo pisati i a[i][j]
        }
        printf("\t");                       //ispis "b" matrice
        for(j = 0; j < stup; j++){
            printf("%4d", *(*(b + i) + j)); // "%4d" nije obavezan on je tu cisto iz formatiranja, moze se pisati samo %d
        }
        printf("\t");   
        for( j = 0; j < stup; j++){         //ispis "c" matrice
            printf("%4d", *(*(c + i) + j));
        }
        printf("\n");
    }
    return 0;
}

int **zbrmat(int **a, int **b, int red, int stup)
{
    int **c;
    int i,j;

    c = (int**)malloc(sizeof(int *) * red);  //ISTI KORACI KAO I KOD ALOKACIJE PRIJASNJE 2 MATRICE

    for( i = 0; i < red; i++){          //postepeno alociramo svaki redak i unosimo vrijednosti u njega zbrajanjem
        *(c + i) = (int *)malloc(sizeof(int) * stup);
        for(j = 0; j < stup; j++){
        *(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
        }
    }
    return c; //vraca matricu koja je rezultat zbrajanja matrica
}

void unmat(int **x, int red, int stup)
{
    int i,j;
    
    for(i = 0; i < red; i++){               //standardni algorutam za unos u  matricu
        for( j = 0; j < stup; j++){
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%d",*(x + i) + j);
        }   
    }
    return;
}
