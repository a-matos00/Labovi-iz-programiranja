#include<stdio.h>

int naj( int[][10], int);
int main()
{
    int matrica[10][10];
    
    int n, i, j, najstup, sumd = 0; //najstup je redni broj stupca sa najvecim zbrojem,
    float aritmd;

    puts( "Unesite velicinu matrice");
    scanf("%d", &n);

    for( i = 0; i < n; i++)             //UNOS MATRICE
        for( j = 0; j < n; j++){
            printf("Unesite clan na (%d,%d)\n", i,j);
            scanf("%d", &matrica[i][j]);
        }
    
    puts("");
    
    for( i = 0; i < n; i++){           //ISPIS MATRICE
        for( j = 0; j < n; j++){
            printf("%d ", matrica[i][j]);
        }
        puts("");
    }
    
    najstup = naj(matrica, n);

    for( i = 0; i < n; i++)             //UNOS MATRICE
        for( j = 0; j < n; j++){
            if( i == j)
                sumd += matrica[i][j];
        }

    aritmd = (float)sumd / n;   //aritmetickoa sredina clanova na dijagonali
    
    printf("Aritmeticka sredina clanova na dijagonali je : %f\n", aritmd);


    printf("Stupac sa najvecom sumom je %d\n", najstup);
    puts("");

    puts("Clanovi tog stupca podijeljeni sa aritmetickom sredinom clanova na dijagonali:");

    for( i = 0; i < n; i++){
        printf("%f, ", (float)matrica[i][najstup - 1] / aritmd);
        
    }
    
    puts("");
    
   
    return 0;  
}

int naj( int matrica[][10], int n)
{
    int i, j;
    int sum = 0;
    int temp = 0;
    int br = 0;

    for( j = 0; j < n; j++){
        for( i = 0; i < n; i++){          //UNOS MATRICE
            sum += matrica[i][j];
        }
        if( sum > temp){        
            br = j + 1;
            temp = sum;
        }
    }
            
    return br;
}
