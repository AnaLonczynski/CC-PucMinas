/*
Exercio_0115 - 01/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>

//calcular e mostrar a área de um triângulo com o dobro da altura do mesmo.

int main()
{
    int x=0,y=0,z=0,a=0;

    printf ("%s" , "\nExercicio 0115 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s","Favor insira um valor para a base de um triangulo: ");
    scanf ("%d", &x);
    while (x <= 0)
    {
      printf ("%s" , "\nERRO: condicao de existencia de um triangulo ferida. Favor inserir um valor positivo maior que 0.");
      printf ("%s","\nFavor insira um valor para a base de um triangulo: ");
      scanf ("%d", &x);
    }
    printf ("%s","\nFavor insira um valor para a altura de um triangulo: ");
    scanf ("%d", &y);
    while (y <= 0)
    {
      printf ("%s" , "\nERRO: condicao de existencia de um triangulo ferida. Favor inserir um valor positivo maior que 0.");
      printf ("%s","\nFavor insira um valor para a altura de um triangulo: ");
      scanf ("%d", &y);
    }
    z = y*2;
    a = (z*x)/2;
    printf ("\nO valor da area desse triangulo com o dobro da altura e: %d", a);
    return 0;
}