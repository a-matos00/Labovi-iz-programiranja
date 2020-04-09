#include<stdio.h>

unsigned zbroji(unsigned, unsigned);
unsigned pomnozi(unsigned, unsigned);
unsigned potenciraj(unsigned, unsigned);
int main()
{
    unsigned a, b, sum, rezultat;
    
    puts("Unesi prvi broj");   
    scanf("%u", &a);
    puts("Unesi drugi broj");
    scanf("%u", &b);

    rezultat = potenciraj(a, b);  // "a" je baza a "b" eksponent

    printf("Rezultat potenciranja je %u\n", rezultat); 
    
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
        return a;
    else zbroji( a, pomnozi(a , b - 1));
}

unsigned potenciraj(unsigned a, unsigned b)
{
    if( b == 1)    //cilj je potenciranje svest na mnozenje
        return a;
    else
        return pomnozi(a, potenciraj(a, b - 1)); 
}

/* PRIMJER!! potenciraj(2,3) => pomnozi(2, potenciraj(2,2)) => pomnozi(2, pomnozi(2, potenciraj(2,1)) => pomnozi(2, pomnozi(2,2)) =>
            pomnozi(2,4) == 8  ovo je skraceni raspis moze se ovo jos rasirit ako cemo raspisivat pomnozi()
*/




