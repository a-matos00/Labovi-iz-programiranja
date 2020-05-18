/*  
    1. Argumetnti funkcije main:
        a) int argc --> ovaj argument ne upisujemo u terminalu vec ga racunalo samo odreduje, on nam govori koliko
           argumenata smo upisali ukljucujuci i "./a.out". npr. za "./a.out 1 2 3" ==> argc == 4
        b) char *argv[] je niz pokazivaca na nizove znakova jer se argumenti zapisuju kao znakovi, odnosno
           stringovi. To znaci da ako za argument upisemo cjelobrojni broj on ce biti spremljen kao "char", a ne "int".
           Argumentima pristupamo sa argv["cijeli broj"] npr. argv[3]. U niz znakova se takoder sprema i "./a.out" pa 
           zauzme mjesto argv[0].

    2. fopen("<ime datoteke>","<operacija koju zelimo ciniti s datotekom>");
       a) npr. fopen( "datoteka.c", "w");
       b) operacije --> vidi 10. predavanje
       c) ovu funkciju koristimo da bi pokazivacu na datoteku dodijelili datoteku.
    
    3. feof() --> "end of file"
       a) funkcija vraca "0" kada dodemo do kraja datoteke

    4. U terminalu prvo kompajliramo: "gcc primjer.c"
       Zatim: "./a.out tekst.txt nova_datoteka.txt"s
*/


#include<stdio.h>

int main(int argc, char *argv[])
{
    char znak;
    FILE *in, *out; // "FILE *" pokazivac na datoteku

    in = fopen( argv[1], "r"); // prvi argument ce nam biti datoteka iz koje prepisujemo tekst
    out = fopen( argv[2], "w"); // drugi argument je datoteka u koju cemo upisati tekst, "w" znaci da ce se napraviti
                               // nova datoteka ili prebrisati vec postojeca

    if( in == NULL || out == NULL) //ovaj uvjet nije obavezan, on provjerava jesmo li uspijeli pristupiti datotekama,
    {                              // ako nismo, pokazivacka varijabla ce imati vrijednost "NULL"
        puts("Greska");
    }

    while( !feof(in))       
    {
        znak = fgetc(in);   //uzimamo jedan znak iz prve datoteke
    
        if(!feof(in)) //sve dok ne dodemo do kraja datoeke
            fputc( znak, out);   //upisujemo znak u drugu datoteku sve dok ne dodemo do kraja datoeke
    }
}
