#include<stdio.h>

int main()
{
    int a,b;
    int *pb,*pa; //pri incijalizaciji stavljamo zvijezdicu
    
    pa = &a; //pokazivacu pridruzujemo adresu varijable (ne stavljamo zvijezdicu)
    pb = &b;

    printf("Unesi cijeli broj a\n");
    scanf("%d",&a);
    printf("Unesi cijeli broj b\n");
    scanf("%d",&b);

    printf("Vrijednost a == %d na adresi %p\n",a,pa); //pri ispisu kod pokazivača ne stavljamo zvijezdicu jer tad predstavlja adresu
    printf("Vrijednost b == %d na adresi %p\n",b,pb); //pokazivač sa  zvijezdicom predstavlja vrijednost ==> a = *pa;
                                                      //to znaci da umisto var "a" mozemo stavljati *pa i dobit cemo isto.
    b = *pa; //Prevedeno: varijabli "b" je pridruzena vrijednost na adresi pa; (alternativno mozemo pisat *pb = a)

    printf("Izvršena je zamjena (varijabli b je pridruzena vrijednost od a)\n");

    printf("Vrijednost a == %d na adresi %p\n",a,pa);
    printf("Nova vrijednost b == %d na adresi %p\n",b,pb);
    
    
    return 0;
}
