/* Objasnjenje "do-while" petlje u main() funkciji

    1. Petlja se izvrsava sve dok ne unesemo prazni redak tj. da je broj znakova retka "0".
    2. Unosimo redak teksta u niz rec[80]
    3. Pomocu funkcije strlen() spremamo broj redaka u varijablu, ali moramo oduzeti jedan jer ta funkcija kao dio retka ubraja '\n'
    4. Ako smo unijeli prazni niz petlja se prekida
    5. Ako smo unijeli valjani redak teksta brojac redaka se povecava
    6. Realociramo niz koristeci funkciju realloc()
        a) Koristimo ovu funkciju jer se povecala velicina niza
        b) Argumenti su redom: ("niz koji realociramo", "velicina niza")
        c) Bitno je cast-at povratnu vrijednost funckije jer je "rniz" pokazivac na pokazivac. (char **rniz)
    7. Dobra praksa je stavit "osigurac", u slucaju da realokacija memorije ne uspije (jer nema mjesta u memoriji). Ako se to dogodi
       funkcija automatski vraca "NULL". Imajuci to na umu koristimo if petlju: ako je "rniz == NULL" onda se prekida program(return 1)
    8. Alociramo dovoljno memorije u pokazivacu (koji se nalazi u nizu pokazivaca**rniz) za pohranu upisanog retka teksta
        a) Koristimo malloc() jer znamo konacnu velicinu retka a to je varijabla broj_znakova.
        b) Radi se o nizu pa od rednog broja retka oduzmemo "1". "Prvi clan niza ima index [0]"
        c) U "while" petlji upisujemo 1 po 1 znak iz rec[] u rniz[][]
    !!!!UNOS NIZOVA JE ZAVRSEN!!!!!
    9. Pozivamo funkciju brzn() koja za argumente prima (pokazivac na niz redaka, broj redaka, odabrano slovo)
        a)    Funkcija vraca niz u kojem se najvise puta pojavljuje zadani znak
*/






#include<stdio.h>
#include<stdlib.h> //sadrzi fgets(), realloc, itd..
#include<string.h> //sadrzi strlen()

int brzn(char **, int, char);
int main()
{
    char z, rec[80], **rniz = NULL;
    int i,j,broj_znakova,red;
    int broj_redaka = 0;
    
    do{
        printf("Unesite %d. recenicu\n", broj_redaka + 1);
    
        fgets(rec, sizeof(rec), stdin); //unos retka teksta u niz rec[80]
        broj_znakova = strlen(rec) - 1; // "-1" jer "strlen" broji "\n" kao znak a on nam ne treba
        
        if(broj_znakova == 0) //petlja se prekida ako smo unijeli prazni niz
            break;
    
        broj_redaka++; //brojac redaka

        rniz = (char **)realloc(rniz, broj_redaka * sizeof(char *)); //povecavamo niz za 1 koristeci realokaciju

        if(rniz == NULL){  //kad funkcija realloc ne uspije alocirati memoriju onda automatski pokaze na NULL(na nista) da
            return 1;          //nebi napravili veliku stetu ili prebrisali bitnu memoriju
        }
        
        rniz[broj_redaka - 1] = (char *)malloc((broj_znakova + 1) *  sizeof(char));  // U rijesenju pise brz + 1, ali je profesor na
                                                                      //na vjezbama reka da moze bit i "-1", a moze bit i samo brz.
        j = 0;     //iterator while petlje ispod   
                                                                
        while(rec[j] != '\n'){              // petlja upisuje znakove iz niza rec[] u nizove niza "rniz"
        rniz[broj_redaka - 1][j] = rec[j];  // rniz[redni broj pokazivaca u nizu pokazivaca][redni broj znaka tog niza]   
        j++;
        }
    
    }while( broj_znakova != 0); //dok ne upisemo prazni redak

    puts("Unesite jedno slovo"); //upisujemo slovo koje zelimo provjeriti
    scanf(" %c", &z);
        
    red = brzn(rniz, broj_redaka, z); //niz u kojem se najvise puta pojavljuje trazeni znak
    
    printf("U znakovnom nizu (%s) ima najvise pojavljivanja trazenog znaka\n", *(rniz + red)); //ispis trazenog niza
    return 0;
}

int brzn( char **niz, int n, char c)
{
    int i, j, brojac, bmax = 0, imax;
    
    for( i = 0; i < n; i++){
        brojac = 0; //brojac trazenog znaka
        j = 0; //redno mjesto znaka u retku
        while(*(*(niz + i) + j) != '\0'){ //dok ne dodemo do kraja retka
            if(*(*(niz + i) + j) == c){  //ako znak u retku odgovara zadanom znaku
                brojac++;
            }
            j++; //prebacujemo se na sljedeci znak u retku
        }
        if(bmax < brojac){ //ako je trenutni maksimalni broj pojavljivanja trazenog znaka u retku manji od onog iz trenutnog retka
            bmax = brojac;  
            imax = i;   //indeksni broj retka s najvecim pojavljivanjem zadanog znaka
        }
    }
    return imax; //vraca indeksni broj retka u kojem se najvise puta pojavljuje trazeni znak
}   
