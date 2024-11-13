/*
Exercio_0112 - 01/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>

int main()
{
int lado = 0 , area = 0 , per = 0; 

printf ("%s" , "\nExercicio 0112 - Author: Ana Clara Lonczynski\n");
printf ("%s" , "\nInsira um valor para o lado de um quadrado: ");
scanf ("%d" , &lado);
while (lado <=0)
{
    printf ("%s" , "\nERRO: condicao de existencia de um quadrado ferida. Favor inserir um valor positivo maior que 0.");
    printf ("%s" , "\nInsira um valor para o lado de um quadrado: ");
    scanf ("%d" , &lado);   
}
area = (lado/2)*(lado/2);
per = (lado/2)*4;
printf ("\nA area desse quadrado com metade do lado e: %d \n", area);
printf ("\nO perimetro de um quadrado com metade do lado e: %d \n", per);
return 0;
}
// calcular e mostrar a área e o perímetro de um quadrado com a metade do tamanho do lado.