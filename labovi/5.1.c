#include<stdio.h>

unsigned zbroji(unsigned);     //prototip funkcije, (unsigned == prirodni brojevi)
int main()
{
    int N, zbroj; 

    puts("Koliko brojeva zelite zbrojiti");
    scanf("%u",&N);
    
    zbroj = zbroji(N);     // varijabli "zbroj" pridruzujemo povratnu vrijednost funkcije zbroji()
    
    printf("Zbroj prvih %u. prirodnih brojeva je %d\n", N, zbroj);  //ispis rezultata

    return 0;
}

unsigned zbroji( unsigned n) 
{
    if( n == 1 )           // ako je korisnik unio 1 onda odmah vracamo 1 
        return n;
    else
        return n + zbroji(n - 1); // ako korisnik nije unio 1 onda funkcija poziva samu sebe
}

    /* PRIMJER 

    zbroji(3) = 3 + zbroji(2) = 3 + 2 + zbroji(1) = 3 + 2 + 1 = 6

    */
