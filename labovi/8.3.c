#include<stdio.h>

char *mjesec(int);
int main()
{
    int dan,mj,god;

    puts("Unesite datum u obliku DD.MM.GGGG");
    scanf("%d.%d.%d", &dan, &mj, &god);
    
    puts("Datum u obliku DD.MMMM.GGGG glasi:");
    printf("%d.%s.%d\n", dan, mjesec(mj), god);
}

char *mjesec(int n)
{
    char *gr[] = {"GRESKA"};     //ovo se zove literalna konstanta, ona se sprema kao globalna varijabla ili konstanta
    char *mj[] = {"sijecanj", "veljaca","ozujak","travanj","svibanj","lipanj","srpanj","kolovoz","rujan","listopad","studeni","prosinac"};

    if( n < 0 || n > 12 ) 
        return *gr;
    return*(mj + n - 1);

}
