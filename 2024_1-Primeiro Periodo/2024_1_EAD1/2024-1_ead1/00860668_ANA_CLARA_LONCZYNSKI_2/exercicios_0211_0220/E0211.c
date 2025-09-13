//1529723 - Ana Clara Lonczynski

/* ler um valor inteiro do teclado e 
- dizer se é par ou ímpar.
 DICA: Considerar o zero como par.
Exemplos: { -6, -3, 0, 3, 6, 9 }
*/

#include <stdio.h>
#include <stdlib.h>

int main ( )
{
    int x = 0;
    printf  ("\n%s\n", "Exemplo0211 - Ana Clara Lonczynski");
    printf  ("%s", "Inserir um valor: "                    );
    scanf   ("%d", &x);
    getchar (        );

    if (x % 2 == 0 )
    {
        while (x % 2 == 0)
       {
        printf  ("\nO valor %d e par, favor inserir novamente: ", x);
        scanf   ("%d", &x);
        getchar (        );
        if (x % 2 != 0)
        {
            printf  ("O valor %d e impar", x);
            getchar ( );
        }
        
       }

    }
    else
    {
        printf  ("O valor %d e impar", x);
        getchar ( ); 
    }

    
    return 0;
}