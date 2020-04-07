//Treba imat ASCII tablicu za risti ovo

#include <stdio.h>
int main()
{
    char znak;

    printf("Unesi znak\n");
    scanf("%c",&znak);

    if(znak >= 'a' && znak <= 'z'){             //uvjet je ispunjen ako je znak u ascii tablici izmedu 'a' i 'z'
        printf("Uneseni znak je malo slovo\n");
    }
    
    else if(znak >= 'A' && znak <= 'Z'){       //isti princip ko i za malo slovo
        printf("Uneseni znak je veliko slovo\n");
    }

    else{                                     //ako broj nije ni malo ni veliko slovo
        printf("Uneseni znak nije slovo\n");
    }

    return 0;

}
