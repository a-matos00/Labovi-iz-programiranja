#include<stdio.h>

void obrni(char [], int);
int main()
{
    char redak[80];
    
    puts("Unesite redak teksta");
    fgets(redak, 80, stdin);

    obrni(redak,0);
    
    puts("");
    return 0;
}

void obrni(char redak[], int i)
{
    if(redak[i] == '\0')
        return;
    else{
        obrni(redak, i+1);
        printf("%c",redak[i]);
        return;
    }
}
