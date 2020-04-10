#include<stdio.h>

unsigned fakt(unsigned);
int main()
{
    unsigned n, rezultat;
    
    puts("Unesite broj");
    scanf("%u", &n);

    rezultat = fakt(n);

    printf("Faktorijela broja %u je %u\n", n,rezultat);  //ispis rezultata

    return 0;
}

unsigned fakt( unsigned n)
{
    if( n == 0)
        return 1;
    if( n == 1)
        return 1;
    else
        return n * fakt(n-1); //funkcija poziva samu sebe sve dok "n" ne bude 1
}

/* PRIMJER fakt(3) => 3 * fakt(2) => 3 * 2 * fakt(1) => 3 * 2 * 1 => 6
