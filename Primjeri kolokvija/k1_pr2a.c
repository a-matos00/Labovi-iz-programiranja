//ovaj zadatak mozemo rijesiti koristeci znanje iz prvog semestra. Zadatak cu rijesit koristeci funkcije ali moze se takoder rijesit
//samo u funkciji main(), taj nacin iman spremljen u repozitoriju "neki korisni programi".

#include<stdio.h>
#include<stdio.h>

void unos(char[5][5], int, int);
void ispis(char[5][5], int, int);
void glavna(char[5][5], int, int);
void sporedna(char[5][5], int, int);
int main()
{
    char znakovi[5][5];
    int m,n;
    
    
    puts("Unesite broj redaka");
    scanf("%d", &m);
    puts("Unesite broj stupaca");
    scanf("%d", &n);

    unos(znakovi, m,n);
    
    puts("Ispis matrice");
    ispis(znakovi, m,n);

    glavna(znakovi, m, n);
    puts("");
    sporedna(znakovi, m, n);
    
    return 0;
}
void sporedna(char mat[5][5], int red, int stup)
{
    int i,j;
    
    printf("Clanovi na sporednoj dijagonali: ");
    for( i = 0; i < red; i++)
        for( j = 0; j < stup; j++)
            if( (i + j) == (red - 1) ){     //zbroj koordinata clanova na sporednoj dijagonali je jednak "broju redaka - 1"
                printf("%c", mat[i][j]);
            }
      
    
    return;
}

void glavna(char mat[5][5], int red, int stup)
{
    int i,j;
    
    printf("Clanovi na glavnoj dijagonali: ");
    for( i = 0; i < red; i++)
        for( j = 0; j < stup; j++)
            if( i == j){                        //koordinate na glavnoj dijagonali su jednake jedna drugoj npr. (0,0),(1,1)...
                printf("%c", mat[i][j]);
            }
      
    
    return;
}


void ispis(char mat[5][5], int red, int stup)
{
    int i,j;

    for( i = 0; i < red; i++){
        for( j = 0; j < stup; j++){
            printf("%c,", mat[i][j]);
        }
        puts("");
    }
    
    return;
}

void unos(char mat[5][5], int red, int stup)
{
    int i,j;

    for( i = 0; i < red; i++)
        for( j = 0; j < stup; j++){
            printf("Unesi clan matrice na poziciji (%d,%d)\n", i + 1, j + 1);
            scanf(" %c", &mat[i][j]);
        }
    
    return;
}
