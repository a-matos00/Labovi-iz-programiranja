#include <stdio.h>

int main(){

    int n,i;

    int fakt = 1;     //ima vrijednost 1 jer poslije mnozimo s njim
    
    printf("Unesi jedan prirodni broj\n");
    scanf("%d",&n);
    
    fakt = 1;

    if( n < 0 ){      //prvo provjeravamo jeli unesen prirodan broj
        printf("Uneseni broj nije prirodan\n");

        return 1;
    }

    else if( n == 0) //jako bitan uvjet jer for petlja ispod ne daje tocan rezultat sa nulom
        printf("Faktorijel od %d je %d\n", n, fakt);
    
    
    else{                       //povecavamo i sve dok ne dobije vrijednost unesenog broja
        for( i = 1; i <= n; i++)
        fakt *= i;
        
        printf("Faktorijel od %d je %d\n", n, fakt);
    }
           
    return 0;
}
