#include<stdio.h>
#include<malloc.h>
#define MAX 20

void zbroji(int *[], int*[], int *[], int,int);
void unos(int *[], int,int);
int main()
{
    int red, stup, i,j;

    int *A[MAX], *B[MAX], *C[MAX]; //inicijaliziramo niz pokazivaca


    puts("Koliko redaka zelite da imaju matrice?(MAX 20)"); //unos redaka i stupaca
    scanf("%d", &red);
    puts("Koliko stupaca zelite da imaju matrice?(MAX 20)");
    scanf("%d", &stup);

    for( i = 0; i < red; i++){                              //alokacija memorije
        A[i] = (int *)malloc(stup * sizeof(int));          // alociramo nove nizove koji sadrze stupce za svaki redak
        B[i] = (int *)malloc(stup * sizeof(int));         
        C[i] = (int *)malloc(stup * sizeof(int));
    }

    // niz pokazivaca *A[] sadrzi pokazivace na retke, a retci *A[i] pokazivace na stupce
    puts("Unos u prvu matricu");
    unos( A, red, stup);
    puts("Unos u drugu matricu");
    unos( B, red, stup);

    zbroji(A,B,C,red,stup);

    puts("Ispis matrice");
    for( i = 0; i < red; i++){   //ispis
        for( j = 0; j < stup; j++)
            printf("%d, ", *C[i][j]);
        puts("");
    }
    
    return 0;
}
void zbroji(int *A[], int *B[], int *C[], int red, int stup)
{
    int i,j;
    
    for( i = 0; i < red; i++)
        for( j = 0; j < stup; j++)
            C[i][j] = A[i][j] + B[i][j]; 
    return;    
}

void unos(int *X[], int red, int stup)
{
    int i,j;
    
    for( i = 0; i < red; i ++)
        for( j = 0; j < stup; j++){
            printf("Unos na pozicija (%d,%d)\n", i+1, j+1);
            scanf("%d", &X[i][j]);
        }
    return;
}


