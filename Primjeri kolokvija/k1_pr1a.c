#include<stdio.h>

#define N 50

void upis(char[],int);
void ispis_niza(char[],int);
void ispis_ascii(char[],int);
int main()
{
    int i;
    char X[N];
    unsigned n;  //zeljeni broj znakova za unos u niz
    
    do{                                                        //ponavlja se ako korisnik upise veci broj od 50
        puts("Koliko znakova zelite upisati u niz (MAX 50)");
        scanf("%u", &n);
    }while( n > 50);
    
    upis(X, n);
    ispis_niza(X, n);
    ispis_ascii(X, n);
    
   
    return 0;
}

void ispis_ascii(char niz[], int n)
{
    int i;
    int brojac = 0;
    puts("Ispis znakova sa parnim ascii vrijednostima");
    for( i = 0; i < n; i++){
        if( ((int)(niz[i])) % 2 == 0){
            brojac++;
            printf("%c == %d na adresi %p", niz[i], niz[i], &niz[i]);
            puts("");
        }
    }
    printf("Niz sadrzi %d broja/brojeva sa parnim ASCII vrijednostima:\n", brojac);
    return;  
}

void upis(char niz[], int n)
{
    int i;
    for( i = 0; i < n; i++){
        printf("Unesite %d. clan niza\n", i+1);
        scanf(" %c", &niz[i]); //bitan je razmak ispred "%c"
    }
    return;  
}

void ispis_niza(char niz[], int n)
{
    int i;
    puts("Ispis niza nakon upisa");
    for( i = 0; i < n; i++){
        printf("%c, ", niz[i]);
    }
    puts("");
    return; 
}
