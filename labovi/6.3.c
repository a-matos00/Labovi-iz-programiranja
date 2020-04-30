#include<stdio.h>
#include<malloc.h>

int minmax(int *, int, int (*)(int,int)); //pokazivac na funkciju zapisemo kao: "int (*)(argumenti funkcije)"
int manjiod(int,int);
int veciod(int,int);
int main()
{
    int n,i;
    int *niz;
    char c; //varijabla kojom cemo odredit koju funkciju pozvat
    
    puts("Unesite broj clanova niza");
    scanf("%d", &n);
    
    niz = (int *)malloc(sizeof(int) * n); //alociramo memoriju za niz
     
    for( i = 0; i < n; i++){                        //unos brojeva u niz
        printf("Unesite %d. clan niza\n", i + 1);
        scanf("%d", niz + i);
    } 

    puts("Ispis niza");
    
    for( i = 0; i < n; i++){       //ispis
        printf("%d",*( niz + i));
    }
    puts("");
    
    puts("Unesite 'v' za ispis najveceg clana a 'm' za ispis najmanjeg");
    scanf(" %c", &c);
    
    switch(c){         //uneseni znak utjece na posljednji argument funkcije minmax, a to su funkcija "veciod" ili"manjiod"
        case 'v':
        case 'V':
           printf("Najveci broj je %d\n",minmax( niz, n, veciod));
            break;
        case 'm':
        case 'M':
            printf("Najmanji broj je %d\n",minmax( niz, n, manjiod));
            break;
        default:
            puts("Greska");
    }
    
    return 0;
}

int minmax( int *niz, int n, int (*op)(int, int)) // 1. adresa prvog clana niza, broj clanova, pokazivac na funkciju
{                                                
    int i,temp;
    temp = *niz; //varijabla sadrzi trenutni najveci/najmanji znak

    for(i = 1; i < n; i++)
        if(op(*(niz + i), temp)) // poziva se funkcija manjiod/veciod. Ako funkcija vraca 1 onda je izraz istinit, i obrnuto...
            temp = *(niz + i);
      
    return temp; //funkcija vraca najveci/najmanji znak niza
}

int manjiod(int a, int b)
{
 return ( a < b) ? 1 : 0; //***prijevod: "ako vrijedi (a<b) onda vrati 1, ako ne onda 0;
}

/*** moze se zapisati kao 
    if(a < b)
        return 1;
    else
        return 0;
*/
    

int veciod(int a, int b)
{
 return ( a > b) ? 1 : 0;
}

