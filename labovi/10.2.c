/*
    Inicijalizacija pokazivaca na strukturu:

    struct "ime_strukture" *"ime pokazivaca"; npr. struct podaci *p;

    Podacima strukture pristupamo na nacin:

    (*"ime_pokazivaca")."ime_elementa";  npr. (*p).ime;
    ili
    "ime_pokazivaca"->"ime_elementa";  npr. p->ime;

    Treba razumjeti da pokazivac pokazuje na varijablu tipa struktura te da on zauzima dovoljno mjesta za sve
    elemente vec definirane strukture.

    1. DEFINIRAMO STRUKTURU ( Odredujemo elemente koje ce sadrzavati ); -- moze se obaviti van main() funkcije
    2. INICIJALIZIRAMO VARIJABLU TIPA STRUKTURA ( obavlja se unutar main() )
    3. INICIJALIZIRAMO POKAZIVAC na varijablu tipa struktura 
    
    
*/



#include<stdio.h>

struct podaci{
    char ime[50];
    int mb;
    int pisp;
    float prosjek;
};

void upis(int, struct podaci*);
void ispis(struct podaci*);

int main()
{
    struct podaci stud[50];
    int n, i;

    printf("Koliko studenata ima: ");
    scanf("%d", &n);
    upis(n, stud);
    
    for(i = 0; i < n; i++)
        ispis(stud + i); 
    
    return 0;
}

void upis(int n, struct podaci *s)
{
    int i;
    for( i = 0; i < n; i++){
        printf("Unos %d. clana strukure:\n", i + 1);
        printf("Unesite ime i prezime: ");
        scanf(" %[^\n]", s[i].ime);
        printf("MB: ");
        scanf("%d", &s[i].mb);
        printf("Broj polozenih ispita, najvise 6:");
        scanf("%d", &s[i].pisp);
        puts("");
        s[i].prosjek = (float)s[i].pisp / 6 * 100;
    }
    return;
}

void ispis(struct podaci *s)
{
    printf("\nIme i prezime (MB): %s(%d)",s->ime, s->mb);
    printf("\nPolozeno ispita %d/6, uspjesnost %.2f%%\n", s->pisp, s->prosjek);
    return;
    
}
