#include<stdio.h>

void slozi( int*, int, int(*)(int, int));
int manjiod( int, int);
int veciod(int, int);

int main()
{
    int niz[20];
    int i,n; //n --> kolicina znakova koje korisnik želi unijeti
    int *p;  //pokazivac na prvi znak niza
    char c; // slovo koje odreduje kako sortiramo niz(unosi korisnik)

    puts("Koliko znakova zelite unijeti?");
    scanf("%d", &n);

    for( i = 0; i < n; i++){  //unos niza
        printf("Unesite %d. clan niza\n", i + 1);
        scanf("%d", &niz[i]);

    }

    p = &niz[0]; //dodjeljujemo pokazivacu p adresu prvog clana

    puts("Unesite 'm' ili 'v'");    //korisnik odabire nacin sortiranja
    scanf(" %c", &c);

    switch(c){                   // argumenti funkcije ovise o korisnikovu odabiru
        case 'm': slozi( p, n, manjiod); 
                break;
        case 'v': slozi(p, n, veciod);
    } 
    
    puts("Ispis sortiranog niza");
    
    for( i = 0; i < n; i++){    //ispis sortiranog niza
        printf("%d,", *(p + i));
    }
    
    puts("");

    return 0;
}

void slozi(int* p, int n, int (*func)(int a, int b))
{
    int i,j, temp;

    for ( i = 0; i < n - 1; i++)        //klasicni selection sort
        for( j = i + 1; j < n; j++)
            if( func( *(p + i), *(p + j))){
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
    return;
}

int manjiod( int a, int b){
    
    return (a < b) ? 1 : 0; //ako vrijedi izraz u zagradi onda vrati 1 ako ne onda vrati 0
    
}

int veciod( int a, int b){
    
    return (a > b) ? 1 : 0;
    
}
