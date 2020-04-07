#include<stdio.h>

int proc_red(void);

int main(){
    int br_red, n, suma; // redom: "broj redaka", "broj znakova u retku","zbroj svih znakova"
    float prosjek;       // "prosjecni broj znakova u retku"

    suma = 0;
    br_red = 0;

    while( (n = proc_red()) != 0){     // "n" je vrijednost vracena iz funkcije proc_red() 
        suma += n;                     
        br_red++;
    }

    prosjek =(float)suma/br_red;

    printf("Prosjecni broj unesenih znakova je %.2f\n",prosjek);
   
    return 0;
}

int proc_red()
{
    int br_zn = 0; // "broj znamenki"

    while( getchar() != '\n' ) // petlja racuna broj znakova sve dok ne pritisnemo "enter"
           br_zn++;

    return br_zn;   //vraca broj znamenaka retka
    
}
