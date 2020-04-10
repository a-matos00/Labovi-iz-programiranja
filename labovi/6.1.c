#include<stdio.h>
#include<math.h>
#define USE_MATH_DEFINES  // omogucuje nam da koristimo pre-definirane vrijednosti iz matematike npr. "e"

double racunaj(double, double(*)(double));
double kvadrat(double);
double sinus(double);
double kosinus(double);
double korijen(double);
double eksp_e(double);  //potenciranje baze prirodnog logaritma
int main()
{
    double x, rezultat;
    char operacija;

    puts("Unesite broj");
    scanf("%lf", &x);
    puts("Unesite operaciju");
    puts("k za kvadrat\ns za sinus\nc za kosinus\nr za korijen\ne za eksponent baze prirodnog logaritma");
    scanf(" %c", &operacija);  //!!!!!!!!!!!JAKO BITAN DETALJ!!!!!! kad koristimo scanf za upisat char onda treba ostavit jedan razmak
                              // isprid "%c"  PRIMJER => scanf(" %c", %varijabla), u protivnom ce program samo preskocit tu liniju koda
                             // Profesor Tomac je ovo objasnia u snimci 6. vjezbi na (25:06)
    switch(operacija){      // gleda koji smo znak upisali i prema tome izvrsava odredeni slucaj
        case 'k':
        case 'K':
            rezultat = racunaj(x, kvadrat);  //pozivamo funkciju racunaj koja za argumente uzima uneseni broj i odabranu funkciju
            break;
        case 's':
        case 'S':
            rezultat = racunaj(x, sinus);
            break;
        case 'c':
        case 'C':
            rezultat = racunaj(x, kosinus);
            break;
        case 'r':
        case 'R':
            rezultat = racunaj(x, korijen);
            break;
        case 'l':
        case 'L':
            rezultat = racunaj(x, eksp_e);
            break;
        case 'e':
        case 'E':
            rezultat = racunaj(x, eksp_e);
            break;
        default:            //ispisuje gresku ako nismo upisali jedan od zadanih znakova
            puts("Greska");
    }

    printf("Rezultat je %.2lf\n", rezultat);  //ispis rezultata
    return 0;
}

double racunaj(double x, double (*operacija)(double x))  //ova funkcija sluzi samo za pozivanje drugih vec definiranih funkcija
{
    return operacija(x);
}

double kvadrat(double x)
{
    return x * x;
}
    
double sinus(double x)
{
    return sin(x);
}

double kosinus(double x)
{
    return cos(x);
}

double korijen(double x)
{
    return sqrt(x);
}

double eksp_e(double x)
{
    return pow(M_E,x);  // argument "M_E" je baza prirodnog logaritma-"e", prijevod "e na x"
}




