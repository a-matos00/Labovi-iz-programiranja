#include<stdio.h>

void zam1(int, int);
void zam2(int*, int*);

int main()
{
    int a,b;
    
    printf("Unesi prvi broj\n");
    scanf("%d",&a);
    printf("Unesi drugi broj\n");
    scanf("%d",&b);

    zam1(a,b);
    
    printf("Izvrsena je prva zamjena\n");
    printf("Vrijednost prvog broja je %d\n",a);
    printf("Vrijednost drugog broja je %d\n\n",b);

    zam2(&a,&b);
    
    printf("Izvrsena je druga zamjena\n");
    printf("Vrijednost prvog broja je %d\n",a);
    printf("Vrijednost drugog broja je %d\n",b);

    
    return 0;
}

void zam1(int a, int b)  //ova zamjena nista ne mijenja kad se kod kompajlira jer kod void funkcija moramo koristit pokazivace
{
    int pom; // pomocna varijabla za zamjenu

    pom = a;
    a = b;
    b = pom;

    return;
}

void zam2(int *a, int *b)
{
    int pom = *a;   // vrijednost na adresi *a spremimo kao varijablu "pom"
    
    *a = *b;  //vrijednost na adresi *b pohranimo u adresu *a
    *b = pom; //adresi *b dodjelimo vrijednost varijable pom
    
    return;
}
