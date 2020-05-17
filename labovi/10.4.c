/*
   *stavljena je samo funkcija za zbarajanje jer nema smisla sve ih sad listat da bi se razumio zadatak
*/

#include <stdio.h>

 typedef struct{    //definiramo vrstu strukture koju cemo koristit kroz zadataka
        int brojnik;
        int nazivnik;
    } _razl;   //dajemo naziv vrsti strukture

_razl razlomci(_razl, _razl, _razl(*)(_razl, _razl)); //funkcije koje vracaju i za argumente primaju strukture
_razl zbroji(_razl, _razl);
_razl skrati(_razl);
int nzd(int, int); //funkcija za pronalazenje najveceg zajednickog djeljitelja

int main()
{
    _razl a[2], rez;     // razlomke inicijaliziramo kao clanove niza struktura jer nam je tako lakse upisivat vrijednosti
    int i,zajednicki;
    char op;   //varijabla koja sprema kratice za imena operacija

    for ( i = 0; i < 2; i++){                           //unos
        printf("Unesite brojnik %d. razlomka\n", i + 1);
        scanf("%d", &a[i].brojnik);
        printf("Unesite nazvnik %d. razlomka\n", i + 1);
        scanf("%d", &a[i].nazivnik);
        
        a[i] = skrati(a[i]);    // skracujemo razlomak nakon upisa
    
        printf("Unijeli ste %d/%d\n", a[i].brojnik, a[i].nazivnik); //ispis skracenog razlomka kojeg smo unijeli
    
        }

        puts("Odaberite operaciju:\n \"z\" - zbrajanje\n");
        scanf(" %c", &op); //biramo operaciju

        switch(op){  //na temelju opisa poziva se pripadajuci "case"
            case 'z':
            case 'Z': rez = razlomci(a[0], a[1], zbroji); //funkcija prima razlomke i pokazivac na funkciju(njeno ime)
                      printf("Rezultat zbrajanja je %d/%d", rez.brojnik, rez.nazivnik); //ispis rezultata operacije
                     break;
            default: puts("GRESKA"); //ako smo unijeli znak koji ne odgovara ni jednom slucaju
        }

        return 0;
}

_razl razlomci(_razl a, _razl b , _razl(*op)(_razl a, _razl b)) 
{
    return skrati(op(a, b)); // "op" predstavlja funkciju iz argumenta u main(), a njeni argumenti su prva 2 argumenta
                            //funkcije razlomci
}

_razl zbroji( _razl a, _razl b)
{
    _razl c;  //inicijaliziramo razlomak koji ce bit rezultat operacije

    c.brojnik = a.brojnik * b.nazivnik + b.brojnik * a.nazivnik;
    c.nazivnik = a.nazivnik * b.nazivnik;
    
    c = skrati(c);
    
    return c;
}

_razl skrati(_razl x)  //nalazimo najveci zajednicki djeljitelj i kratimo brojnik i razlomak
{
    int z;

    z = nzd( x.brojnik, x.nazivnik );
    
    x.brojnik /= z;
    x.nazivnik /= z;
    
    return x; //vracamo istu strukturu koju smo doveli u funkciju samo sto smo je promjenili skrativsi razlomak
}

int nzd( int m, int n)  //EUKLIDOV ALGORITAM za pronalazenje najveceg zajednickog djeljitelja
{
    int r, temp;
    
    if( m < n){ 
        temp = m;
        m = n;
        n = temp;
    }
    
    r = m % n;
    
    while( (r = m % n) != 0 ){
         m = n;
         n = r;
    }

   
    return n; //vraca najveci zajednicki djeljitelj
}
