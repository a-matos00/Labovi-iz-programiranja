#include<stdio.h>

unsigned zbroji(unsigned, unsigned);
unsigned pomnozi(unsigned, unsigned);
int main()
{
    unsigned a, b, sum, umnozak;
    
    puts("Unesi prvi broj");   
    scanf("%u", &a);
    puts("Unesi drugi broj");
    scanf("%u", &b);

    umnozak = pomnozi(a, b);  

    printf("Rezultat mnozenja je %u\n", umnozak); 
    
    return 0;
}

unsigned zbroji( unsigned a, unsigned b)  
{
    if( b == 1)           
        return a + 1;
    else
        return zbroji( a + 1, b - 1); 

}

unsigned pomnozi( unsigned a, unsigned b)  
{
    if( b == 1)
        return a; // mnozenje sa jedan vraca taj isti broj (cilj nam je doc do ovog slucaja 
    else zbroji( a, pomnozi(a , b - 1));
}

/* PRIMJER !! pomnozi(3,3) => zbroji(3, pomnozi(3,2)) => zbroji(3, zbroji(3, pomnozi(3,1)) => zbroji(3, zbroji(3,3) => zbroji(3,6) == 9

    Rekurzivno mnozenje svodimo na zbrajanje dva broja, kao i kod zbrajanja smanjujemo drugi argument dok ne postane "1" dok u isto
    vrijeme povecavamo drugi argument
*/




