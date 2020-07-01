/* kod se 98% podudara sa ovim pod a) 
   pod a) smo prvo izracunali broj klubova pa sa mallocom alocirali memoriju za niz
   pod b) cemo cim izbrojimo jos jedan klub odmah alocirat memorije za njega u nizu, ali caka je sta moramo prvo
   alocirat memoriju za prvi clan niza sa mallocom da bi mogli koristit realloc().
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
       char ime[50];
       int GF;
       int GA;
}_klub; //tip ove strukture je _klub

void func( _klub*, int);
int main()
{
    FILE *tablica; //pokazivac na datoteku

    _klub *klubovi; //pokazivat ce na niz struktura klubova
    int br = 0;    
    int i ,br_klubova = 0; //brojac klubova
    
    tablica = fopen ("tablica.txt", "r"); //otvaramo datoteku za citanje
    
    klubovi = malloc( sizeof(_klub));   //alociramo memoriju za prvi clan nizas
    
    fseek(tablica, 18, SEEK_SET); //preskocimo prvu liniju
    
    while(!feof(tablica)) {  //sve dok ne dodemo do kraja datoteke
        if( fgetc(tablica) == '\n' )    //ako naletimo na '\n'
            br_klubova++;
    klubovi = realloc( klubovi, sizeof(_klub) * br_klubova);  //velicina niza je broj klubova
    }
   
    fseek(tablica, 18, SEEK_SET);   //opet preskacemo prvu crtu jer moramo unijeti podatke u strukture

    for( i = 0; i < br_klubova; i++){   //spremamo imena i postignute i primljene golove
        fscanf(tablica, "%s %d %d", klubovi[i].ime, &klubovi[i].GF, &klubovi[i].GA);
    }

    for( i = 0; i < br_klubova; i++)    //ispis tablice cisto radi provjere
        printf("%s %d %d\n", klubovi[i].ime, klubovi[i].GF, klubovi[i].GA);
    
    
    func(klubovi, br_klubova); //pozivamo funkciju koja ce ispisati ime kluba sa najvecom gol razlikom

    #include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
       char ime[50];
       int GF;
       int GA;
}_klub; //tip ove strukture je _klub

void func( _klub*, int);
int main()
{
    FILE *tablica; //pokazivac na datoteku

    _klub *klubovi; //pokazivat ce na niz struktura klubova
    int br = 0;    
    int i ,br_klubova = 0; //brojac klubova
    
    tablica = fopen ("tablica.txt", "r"); //otvaramo datoteku za citanje
   
    fseek(tablica, 18, SEEK_SET); //preskocimo prvu liniju
    
    while(!feof(tablica))   //sve dok ne dodemo do kraja datoteke
        if( fgetc(tablica) == '\n' )    //ako naletimo na '\n'
            br_klubova++;

    klubovi = malloc( sizeof(_klub) * br_klubova);  //velicina niza je broj klubova

    fseek(tablica, 18, SEEK_SET);   //opet preskacemo prvu crtu

    for( i = 0; i < br_klubova; i++){   //spremamo imena i postignute i primljene golove
        fscanf(tablica, "%s %d %d", klubovi[i].ime, &klubovi[i].GF, &klubovi[i].GA);
    }

    for( i = 0; i < br_klubova; i++)    //ispis tablice cisto radi provjere
        printf("%s %d %d\n", klubovi[i].ime, klubovi[i].GF, klubovi[i].GA);
    
    
    func(klubovi, br_klubova); //pozivamo funkciju koja ce ispisati ime kluba sa najvecom gol razlikom

    fclose(tablica);
 
    return 0;
}

void func( _klub *klubovi, int br_klubova) //trazimo indeks kluba s najvecom gol razlikom
{
    int i;
    int indeks = 0;
    int max = 0;
    for( i = 0; i < br_klubova; i++){
        if( (klubovi[i].GF - klubovi[i].GA) > max){
                max = klubovi[i].GF - klubovi[i].GA;
                indeks = i;
        }   
    }
    printf("%s\n", klubovi[indeks].ime); //ispis rezultata
    return;
}
    
    return 0;
}

void func( _klub *klubovi, int br_klubova) //trazimo indeks kluba s najvecom gol razlikom
{
    int i;
    int indeks = 0;
    int max = 0;
    for( i = 0; i < br_klubova; i++){
        if( (klubovi[i].GF - klubovi[i].GA) > max){
                max = klubovi[i].GF - klubovi[i].GA;
                indeks = i;
        }   
    }
    printf("%s\n", klubovi[indeks].ime); //ispis rezultata
    return;
}


