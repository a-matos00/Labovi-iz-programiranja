/*  DETALJNA OBJAŠNJENJA NOVIH POJMOVA
        
    <stdlib.h> ova zaglavna datoteka(header file) sadrzi srand(), rand() i RAND_MAX.
    <time.h> sadrzi time().

    srand() -> funkcija koja generira seed o kojem nam ovisi koje ce nam brojeve generirati funkcija rand(),
               za isti seed ce nam uvijek biti generirani isti brojevi.

    seed -> argument srand() funkcije, to je cjelobrojna vrijednost o kojoj ovise nasumicno generirani brojevi,
            ovo je povrsna definicija ali dovoljna za razumjeti svrhu "seeda".

    time(NULL) -> funkcija koja vraca broj proteklih sekunda od 1.1.1970.

    srand((unsigned)time(NULL)) -> ova linija koda nam omogcuje da se svake sekunde mijenja seed jer se stalno
    mijenja povratna vrijednost od time(NULL), taj broj castamo u "unsigned" tip jer je jako velik broj.

    rand() -> vraca nasumicno generiran broj

    RAND_MAX -> predefiniran varijabla kojoj je vrijednost najveca moguca vrijednost nasumicno generiranog broja
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int slbroj(int,int);
int main()
{
    int i,a,b;
    printf("Maksimalna vrijednost nasumcino generiranog broja je %d\n", RAND_MAX);
    
    srand((unsigned)time(NULL));  //generiramo seed
    
    puts("Ispis nasumicnih brojeva");
    
    for( i = 0; i < 5; i++)           //ispisujemo nasumicno generirane brojeve bez intervala
        printf("%d\n", rand());

    puts("Unesite granice intervala unutar kojih zelite generirati nasumicne brojeve");
    
    puts("Unesite donju granicu");
    scanf("%d", &a);
    puts("Unesite gornju granicu");
    scanf("%d", &b);
    
    puts("Ispis nasumicnih brojeva");
    
    for(i = 0; i < 5; i++)
        printf("%d\n", slbroj(a,b));

    return 0;  
}

int slbroj(int min, int max)
{
    int br_mogucih = max - min + 1;
    int nova_granica = RAND_MAX - (RAND_MAX % br_mogucih);
    int sluc_broj = rand();

    while(sluc_broj > nova_granica)
        sluc_broj = rand();
    return sluc_broj % br_mogucih + min;
}
