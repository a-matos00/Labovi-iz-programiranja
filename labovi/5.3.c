#include<stdio.h>

void prebaci(unsigned, unsigned, unsigned);
unsigned pomakni(unsigned, unsigned);
int main()
{
    unsigned pocetni, odredisni, n;  

    puts("Zadana su tri kolca");

    puts("Unesite pocetni kolac");  // odredujemo pocetni kolac
    scanf("%u", &pocetni);

    puts("Unesite odredisni kolac");  // kolac na koji trebamo prebaciti kolute
    scanf("%u", &odredisni);

    puts("Koliko prstenova ima kolac");  // kolicina koluta
    scanf("%u", &n);

    prebaci(n, pocetni, odredisni);
    
    puts("");
    
    return 0;
}

void prebaci(unsigned n, unsigned poc, unsigned kraj)
{
    unsigned pom;
    pom = pomakni(poc, kraj);

    if(n == 1){                                             
        printf("Prebaci  sa %u na %u\n", poc, kraj);
        return;
    }
    else
    prebaci(n - 1, poc, pom);
    prebaci(1, poc, kraj);
    prebaci(n - 1, pom, kraj);
    return;
}

unsigned pomakni(unsigned a, unsigned b)
{
    if((a != 1) && (b != 1))
        return 1;
    else if((a != 2) && (b != 2))
        return 2;
    else
        return 3;
}
