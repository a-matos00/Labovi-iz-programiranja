
/* Za rijesit zadatak treba znat formulu za racunanje udaljenosti tocaka koju mozes nac na ovon linku
   https://www.mim-sraga.com/slike/Math-Type-slike/Analiticka-geometrija.formule-mat-1---2--bold.gif  */


/* !!!JAKO BITNO!!! Kad kompajliramo kod treba dodat -lm na kraju ( eg. gcc ime.c -lm )     
   koristimo "-lm" da bi mogli koristit <math.h>         */

#include<stdio.h>
#include<math.h> //omogucuje nam da koristimo predefiniranu funkciju "sqrt()" (korijen);
#define MAX 20
#define KVAD(x) ((x)*(x))  // moramo definirat funkciju za racunat kvadrate

double minudalj(int, double[], double[], double[], int*, int*); // funkcija koja trazi koje tocke imaju najmanju udaljenost
double udalj(double[], double[], double[], int, int);           //funkcija koja racuna udaljenost tocaka
int main()
{

    int br_tocaka, t1, t2, i;    //kolicina tocaka koji zelimo unijeti
    double x[MAX], y[MAX], z[MAX], udaljenost;

    printf("Koliko tocaka zelite unijeti\n");  
    scanf("%d", &br_tocaka);                // unosimo koliko tocaka zelimo upisati

    for( i = 0;i < br_tocaka; i++){        //unosimo koordinate tocaka  (eg. 2 1 3)
        printf("Unesite %d. tocku\n", i+1);
        scanf("%lf %lf %lf",&x[i], &y[i], &z[i]); // svaka koordinata ima vlastiti niz
    }

    udaljenost = minudalj( br_tocaka, x, y, z, &t1, &t2);  //pozivamo funkciju koja pronalazi koje su tocke najblize

    printf("Dvije najblize tocke su %d i %d a udaljene su za %.2lf\n", t1 + 1, t2 + 1, udaljenost); //ispisujemo rezultate programa

    return 0;
}

double minudalj(int br_tocaka, double x[], double y [], double z [], int *t1, int *t2)
{
    int i,j;       //iteratori
    double udaljenost, min_udaljenost;

    *t1 = 0;   // pocinjemo s nulom jer radimo s nizovima koji sadrze koordinate tocaka
    *t2 = 1;
    min_udaljenost = udalj( x, y , z, *t1, *t2); // zapocinjemo racunanjem udaljenosti prvih dvaju tocaka pozivanjem funkcije udalj()

    for( i = 0; i < br_tocaka - 1; i++)          //slicno selection sortu
        for( j = i+1; j < br_tocaka; j++){
            udaljenost = udalj(x, y, z, j, i);  // nakon svake promjene "i" i "j" racunamo udaljenost izmedu tih novih dvaju tocaka
            if(udaljenost < min_udaljenost){    //ako je udaljenost izracunata u prethodnoj crti manja od trenutne najmanje udaljenosti
                min_udaljenost = udaljenost;    // dodjeljujemo novu najmanju udaljenost
                *t1 = i;           //vrijednostima  na adresama t1 i t2 dodjeljujemo indeksne redne brojeve koordinata najblizih tocki 
                *t2 = j;
            }
        }
    return min_udaljenost;
}

double udalj(double x[], double y[], double z[], int i, int j)
{

    return sqrt(KVAD(x[j] - x[i]) + KVAD(y[j] - y[i]) + KVAD( z[j] - z[i]));  // funkcija vraca udaljenost izmedu dvaju tocaka
}                                                                             // povlaci koordinate iz nizova
                                                                              // "i" i "j" predstavljaju redni broj tocke u nizu

