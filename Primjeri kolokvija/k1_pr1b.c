//Logika zadatka je ista kao pod a) ali umjesto inicijalizacije niza koristimo pokazivace

/* Posto moramo koristit aritmetiku pokazivaca koristimo
    "X = (char*)malloc(sizeof(char) * n)" umjesto "char X[N]" za odredivanje velicine niza
    "*(X + i)" umjesto "X[i]" pri iteriranju kroz vrijednosti niza (npr. kod ispisa)
    "(X + i)" umjesto "&X[i]" kod pristupanja adresa clanova niza (npr. kod upisa)
    "char *" umjesto "char[]" kod argumenata funkcija (npr. upis(char *,int))
*/
#include<stdio.h>
#include<malloc.h>

void upis(char *,int);
void ispis_niza(char *,int);
void ispis_ascii(char *,int);
int main()
{
    char *X; //incijalizacija pokazivaca koji cemo koristit za inicijalizirat niz
    int n;
    
    do{                                                        //ponavlja se ako korisnik upise veci broj od 50
        puts("Koliko znakova zelite upisati u niz (MAX 50)");
        scanf("%u", &n);
    }while( n > 50);
    
    X = (char*)malloc(sizeof(char) * n);  //alociramo memoriju

    upis(X, n);
    ispis_niza(X, n);
    ispis_ascii(X, n);
    
   
    return 0;
}

void ispis_ascii(char *X, int n)
{
    int i;
    int brojac = 0;    //brojac clanova koji imaju parne ascii vrijednosti
    puts("Ispis znakova sa parnim ascii vrijednostima");
    for( i = 0; i < n; i++){
        if( ((int)(*(X + i))) % 2 == 0){ //cast-amo clan niza iz char u int da bi mogli racunat s njim
            brojac++;
            printf("%c == %d na adresi %p", *(X + i), *(X + i), X + i);
            puts("");
        }
    }
    printf("Niz sadrzi %d broja/brojeva sa parnim ASCII vrijednostima:\n", brojac);
    return;  
}

void upis(char *X, int n)
{
    int i;
    for( i = 0; i < n; i++){
        printf("Unesite %d. clan niza\n", i + 1);
        scanf(" %c", X + i); //bitan je razmak ispred "%c"
    }
    return;  
}

void ispis_niza(char *X, int n)
{
    int i;
    puts("Ispis niza nakon upisa");
    for( i = 0; i < n; i++){
        printf("%c, ", *(X + i));
    }
    puts("");
    return; 
}
