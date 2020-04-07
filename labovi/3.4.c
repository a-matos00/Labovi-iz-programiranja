#include<stdio.h>
#include<ctype.h>  //treba nam za koristit sizeof()

void analiza( char[], int *, int *, int *, int *); // tip funkcije je void pa koristimo pokazivace
int main()
{
    char redak[80];        // max 80 znakova smimo upisat
    int suglasnici=0, samoglasnici=0, brojevi=0, ostali=0; //brojaci vrsta znakova, jako je bitno da im pridruzimo nulu
    

    printf("Unesite redak teksta\n");

    fgets( redak, sizeof(redak), stdin); // fgets( ime niza, velicina niza, ulaz na koji cemo upisat string)

    analiza(redak, &samoglasnici, &suglasnici, &brojevi, &ostali); // u funkciju saljemo adrese brojaca


    printf("Redak sadrzi %d samoglasnika\n", samoglasnici);  // ispis
    printf("Redak sadrzi %d suglasnika\n", suglasnici);
    printf("Redak sadrzi %d brojeva\n", brojevi);
    printf("Redak sadrzi %d ostalih znakova\n", ostali);
    
    return 0;
}

void analiza( char redak[], int *samoglasnici, int *suglasnici, int *brojevi, int *ostali)
{
    
    char z;  // pomocna varijabla, oznacava znak u nizu na mjestu redak[i]
    int i = 0;
   
    //idemo kroz niz sve dok ne dodemo do kraja retka 
    while( (z = toupper(redak[i])) != '\n'){     //prebacujemo sva slova u velika da ne moramo posebno provjeravat mala i velika
        if( (z == 'A') || (z == 'E') || (z == 'I') || (z == 'O') || (z == 'U'))
            ++*samoglasnici;
        
        else if( ( z >= 'A') && ( z <= 'Z'))
            ++*suglasnici;
        
        else if( (z >= '0') && (z <= '9'))
            ++*brojevi;

        else
           ++*ostali;
        
            i++;  // kad prodemo kroz uvjete prelazimo na sljedeci element niza 
        }
    return;
}
