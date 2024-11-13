/*
Exercio_0114 - 01/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>

//calcular e mostrar a área e o perímetro de um retângulo com um quarto dos tamanhos dos lados.

int main ()
{
    int lado1 = 0 , lado2 = 0 , area = 0 , per = 0;

    printf ("%s" , "\nExercicio 0113 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s" , "Insira um valor para o lado de um retangulo: ");
    scanf ("%d", &lado1);
    while (lado1 <= 0)
    {
      printf ("%s" , "\nERRO: condicao de existencia de um retangulo ferida. Favor inserir um valor positivo maior que 0.");
      printf ("%s" , "\nInsira um valor para o lado de um retangulo: ");
      scanf ("%d", &lado1);
    }
    printf ("%s" , "\nInsira um segundo valor para o outro lado desse mesmo retangulo: ");
    scanf ("%d" , &lado2);
     while (lado2 <= 0)
    {
      printf ("%s" , "\nERRO: condicao de existencia de um retangulo ferida. Favor inserir um valor positivo maior que 0.");
      printf("%s" , "\nInsira um segundo valor para o outro lado desse mesmo retangulo: ");
      scanf ("%d" , &lado2);
    }
    lado1 = lado1/4 ;
    lado2 = lado2/4 ;
    area = lado1*lado2;
    printf ("\nO valor da area de um retangulo com um quarto dos tamanhos dos lados e: %d\n", area);
    per = (lado1*2)+(lado2*2);
    printf ("\nO valor do perimetro de um retangulo com um quarto dos tamanhos dos lados e: %d\n", per);
    return 0;
}