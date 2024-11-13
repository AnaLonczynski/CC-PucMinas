//1529723 - Ana Clara Lonczynski
/*
- ler um valor inteiro do teclado e 
- dizer se é ímpar e menor que -25, ou par e maior que 25.
Exemplos: { -60, -13, 0, 13, 26, 39 }
*/

#include <stdio.h>

int main ( )
{

    int x = 0;
    printf  ("\n%s\n", "Exemplo0212 - Ana Clara Lonczynski");
    printf  ("%s", "\nFavor, inserir um valor para o programa dizer se e impar e menor que -25 ou par e maior que 25 : "                    );
    scanf   ("%d", &x);
    getchar (        );

    if ( (x % 2 !=0 && x < -25) || (x % 2 == 00 && x > 25))
    { 
        if(x % 2 !=0 && x < -25)
        {
            printf ("\nO valor inserido %d e impar e menor que -25, logo e valido\n", x);
        }
        if(x % 2 == 00 && x > 25)
            printf ("\nO valor inserido %d e par e maior que -25, logo e valido\n", x);
    }
    else 
    {   
        printf("%s", "\nO valor inserido nao e valido, pois e diferente de impar e menor que -25, ou de par e maior que 25\n");
    }


    return 0;
}