#include<stdio.h>
#define kvad(x) ((x)*(x))      //definiramo makronaredbu da dobit kvadrat broja

int main()
{
    int i,brojevi[10],kvadrati[10];  //inicijaliziramo nizove koji ce sadrzavati brojeve i njihove kvadrate
    

    for( i = 0; i < 10; i++){
        brojevi[i] = i+1;         //krecemo od 1 brojat do 10 pa moramo stavit "i+1"
        kvadrati[i] = kvad(i+1);
        
    }

    for( i = 0; i < 10; i++)                                      //ispis
        printf("broj: %d \tkvadrat: %d\n",brojevi[i],kvadrati[i]);
        
    return 0;
}
