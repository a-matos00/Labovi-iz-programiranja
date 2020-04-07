#include <stdio.h>

int main(){

    char i; 

    for(i = 'a'; i <= 'z'; i++)         // iteratoru dodjeljujemo vrijednost 'a'(ASCII:97), svakom iteracijom ce se povecati njegova -
        printf("%c\tASCII:%d\n",i,i);   // ASCII vrijednost sto znaci da ce se ispisati drugi znak
                                        //za ispis ASCII vrijednosti koristimo varijablu "i" u obliku %d
    printf("\n");

    return 0;
}
