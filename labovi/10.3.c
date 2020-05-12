#include<stdio.h>
#include<stdlib.h> //malloc()

typedef struct{                 //typedef ==> definiramo tip strukture s imenom _student
    char ime[50];               //to znaci da za inicijalizaciju varijabli tip struktura ovov tipa strukture
    int mb;                     //mozemo pisati _student "ime_varijable"; bez koristenja rijeci "struct"
    int pisp;
    float prosjek;
}_student;

void upis(int, _student *);
void ispis(_student*);

int main()
{
    _student *_pstudent; // pokazivac na definiranu strukturu student, zbog typdef ne koristimo struct pri
    int n, i;           // inicijalizaciji
    
    

    printf("Koliko studenata ima: ");
    scanf("%d", &n);
    _pstudent = (_student*)malloc(sizeof(_student) * n); //alociramo dovoljno memorija za niz struktura
    upis(n, _pstudent);
    
    for(i = 0; i < n; i++)
        ispis(_pstudent + i);
    
    return 0;
}

void upis(int n, _student *s)
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

void ispis(_student *s)
{
    printf("\nIme i prezime (MB): %s(%d)",s->ime, s->mb);
    printf("\nPolozeno ispita %d/6, uspjesnost %.2f%%\n", s->pisp, s->prosjek);
    return;
    
}
