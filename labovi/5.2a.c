#include<stdio.h>

unsigned zbroji(unsigned, unsigned);  //unsigned == prirodni brojevi
int main()
{
    unsigned a, b, sum;
    
    puts("Unesi prvi broj");   //unosimo brojeve koje zelimo zbrojit
    scanf("%u", &a);
    puts("Unesi drugi broj");
    scanf("%u", &b);

    sum = zbroji(a, b);  // varijabli "sum" pridruzujemo vrijednost koju nam vraca funkcija zbroji

    printf("Rezultat zbrajanja je %u\n", sum); //ispis rezultata
    
    return 0;
}

unsigned zbroji( unsigned a, unsigned b)  
{
    if( b == 1)           
        return a + 1;
    else
        return zbroji( a + 1, b - 1); //funckija poziva samu sebe sve dok b ne postane 1

}

//primjer zbroji(3, 3) => zbroji(4, 2) => zbroji(5, 1) => ispunjen je uvjet (b == 1) pa funkcija vraca (5 + 1) == 6

/*filozofija rekurzivnog zbrajanja je u povecavanju prvog argumenta za 1 i smanjivanja drugog sve dok ne postane 1 jer je tada
  ispunjen prvi uvjet koji vraca ( a + 1 ); */
