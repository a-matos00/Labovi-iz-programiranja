#include<stdio.h>
#include<stdlib.h> //stavljamo ga da bi radia abs();

int main()
{
    int a,b;
    
    printf("Unesi vrijednost varijable a\n");
    scanf("%d",&a);                          //ne zaboravi "&"!!!
    printf("Unesi vrijednost varijable b\n");
    scanf("%d",&b);

    printf("a + b = %d\n",a + b);
    printf("a - b = %d\n",a - b);
    printf("a * b = %d\n",a * b);
    printf("a / b = %.2f\n",(float)a / b);  // treba nam decimalni oblik pa stavljamo %f i prebacujemo rezultat (float) da bi rezultat a/b dobili u decimalnom obliku;
    printf("a %% b = %d\n",a % b); // za ispisat znak "%" treba upisat "%%";
    printf("apsolutne vrijednosti:\n |a| = %d \n |b| = %d\n",abs(a),abs(b)); //da bi radia abs() treba ukljucit <stdlib.h>

    return 0;
}
