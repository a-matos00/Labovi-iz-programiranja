/*  STRUKTURE OBJASNJENJE

    strukturu mozemo deklarirati unutar ili van main() funkcije. 

    struct "ime_funkcije"{
        "tip podatka" "ime elementa";
        ...
        ...
    };

    U main() funkciji moramo ovu strukturu dodijelit nekoj varijabli:

    struct "ime strukture" "ime varijable"; //sada smo inicijalizirali varijablu tipa struktura

    Vrijednosti elementa strukture pristupamo sa:  "ime_varijable"."ime_element" (npr.  "podaci.ime")

*/


#include<stdio.h>

struct podaci{  //deklaracija strukture
    char ime[50];
    int mb;
    int pisp; //broj polozenih ispita
    float prosjek;
};

void upis(int, struct podaci[]); //inicijalziacija funkcija
void ispis(struct podaci);

int main()
{
    struct podaci stud[50];  //inicijalizacija varijable tipa struktura (ovo je niz varijabli tipa "struktura")
    int n, i;

    printf("Koliko studenata ima: "); //odredujemo velicinu niza stud[]
    scanf("%d", &n);
    upis(n, stud);   //poziv funkcije za upis
    
    for(i = 0; i < n; i++) //ispisujemo podatke svih studenata
        ispis(stud[i]);
    
    return 0;
}

void upis(int n, struct podaci s[])
{
    int i;
    for( i = 0; i < n; i++){
        printf("Unos %d. clana strukure:\n", i + 1);
        printf("Unesite ime i prezime: ");
        scanf(" %[^\n]", s[i].ime); // %[^\n] ==> sprema sto je korisnik upisao sve dok se ne stisne "enter"
        printf("MB: ");
        scanf("%d", &s[i].mb); // ime_varijable.element_strukture ==> u ovom slucaju dodajemo i indeks jer se radi o nizu
        printf("Broj polozenih ispita, najvise 6:");
        scanf("%d", &s[i].pisp);
        puts("");
        s[i].prosjek = (float)s[i].pisp / 6 * 100;
    }
    return;
}

void ispis(struct podaci s)
{
    printf("\nIme i prezime (MB): %s(%d)",s.ime, s.mb);
    printf("\nPolozeno ispita %d/6, uspjesnost %.2f%%\n", s.pisp, s.prosjek);
    return;
    
}
