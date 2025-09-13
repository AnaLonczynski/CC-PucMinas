/*
Exercio_0113 - 01/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>

int main ()
{
    int x = 0, y = 0 , z = 0;

    printf ("%s" , "\nExercicio 0113 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s" , "Insira o valor para o lado de um retangulo qualquer: ");
    scanf ("%d", &x);
    while (x <=0)
    {
    printf ("%s" , "\nERRO: condicao de existencia de um retangulo ferida. Favor inserir um valor positivo maior que 0.");
    printf ("%s" , "\nInsira o valor para o lado de um retangulo qualquer: ");
    scanf ("%d", &x);
    }
    printf ("%s" , "\nInsira um valor para o outro lado desse retangulo: ");
    scanf ("%d", &y);
    while (y<=0)
    {
    printf ("%s" , "\nERRO: condicao de existencia de um retangulo ferida. Favor inserir um valor positivo maior que 0.");
    printf ("%s" , "\nInsira um valor para o outro lado desse retangulo: ");
    scanf ("%d", &y);
    }
    z = (x * y)*6;
    printf ("\nO valor de uma area seis vezes maior e: %d\n", z);
    return 0;
}