//Datoteka izgleda malo neuredno, to se moze sredit al nije bitno to vec da radi.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char korisnik[50];
    char adresa[30];
    char broj[15];
} _osoba;

void ispis(_osoba *, int);
int main()
{
    
    int N, i, j; //broj osoba u adresaru
    _osoba temp; //privremena datoteka za zamjenu, mora biti tipa _osoba jer mijenjamo redoslijed struktura
    
    _osoba *lista; //od ovog pokazivaca cemo napraviti polje struktura 

    puts("Koliko osoba zelite unijeti");
    scanf("%d", &N);

    lista = malloc( sizeof(_osoba) * N); //stvaramo niz pokazivaca na strukture tipa _osoba
    
    for( i = 0; i < N; i++){
        printf("Unesite prezime i ime %d. korisnika\n", i + 1);
        scanf(" %[^\n]", lista[i].korisnik); //program sprema sve znakove dok ne stisnes enter
        
        printf("Unesite adresu korisnika\n");
        scanf(" %[^\n]", (lista + i)->adresa); //samo primjer alternativnog nacina zapisa lista[i]

        puts("Unesite korisnikov broj telefona");
        scanf(" %[^\n]", lista[i].broj);
    }

    puts("KRAJ UNOSA");

    for( i = 0; i < N - 1; i++)
        for( j = i + 1; j < N; j++)
            if( (int)lista[i].korisnik[0] > (int)lista[j].korisnik[0] ){ //castamo u ascii vrijednosti pa ih usporedujemo
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
    
    ispis(lista, N); //poziv funkcije za ispis
    
    return 0;
}

void ispis(_osoba *lista, int N)
{
    int i;
        
    FILE * adresar; //pokazivac na FILE

    adresar = fopen("adresar.txt", "w"); //otvaramo datoteku za pisanje

    fputs("KORISNIK\t\tADRESA\t\tTEL.BROJ\n", adresar); //upisujemo prvu crtu u datoteku

    for( i = 0; i < N; i++){            //upis podataka iz struktura u datoteku
        fprintf(adresar, "%-24s%-24s%-24s\n", lista[i].korisnik, lista[i].adresa, lista[i].broj); 
    }

    fclose(adresar); //zatvaramo datoteku
    return;
}
