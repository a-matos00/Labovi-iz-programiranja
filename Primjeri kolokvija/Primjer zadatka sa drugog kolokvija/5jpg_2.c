#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int prebroj(char *, int*);
int main()
{
    int i;
    
    int br = 0; //brojac brojeva ascii vrijednosti

    char *pa, *pb; //pokazivac za prvi niz, drugi niz

    pa = malloc( sizeof(char) * 50); // alociramo mjesta za 50 znakova niza
    
    
    fgets( pa, 50, stdin); //upisujemo znakove u prvi niz ==> mozda nece radit na ispitu zbog nekih tehnickih stvari, pa bi bilo dobro nac neki drugi nacin za upisat znakove
    
    br = prebroj(pa, &br); // funkcija nam vraca broj znakova za drugi niz
    pb = malloc(sizeof(char) * br);
    
    for(i = 0; i < strlen(pa); i++){ // i manje od duljine niza
        if( (int)*(pa + i) < 83)  //castamo u int da bi usporedili
            *(pb + i) = *( pa + i); //znakove koji ispunjavaju uvjet upisujemo u niz
    }

    puts("Znakovi manji od 83 u ascci-u");

    for( i = 0; i < br; i++){  //ispis znakova
        printf("%c", *(pb + i));
    }
    puts("");
}

int prebroj(char *pa, int *br) //int *br == int &br adresa vrijednosti varijable "br"
{
    int i;
    for(i = 0; i < strlen(pa); i++){ //trazimo znakove koji zadovoljavaju uvjet
        if( (int)*(pa + i) < 83)
            (*br)++; //vrijednost pokazivaca br
    }

    return *br; //vracamo vrijednost pokazivaca br
}
