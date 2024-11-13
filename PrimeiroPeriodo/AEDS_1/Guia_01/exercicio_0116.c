/*
Exercio_0116 - 02/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>
#include <math.h>

//supor que esse valor represente o lado de um triângulo equilátero,
//calcular e mostrar a altura, área e o perímetro do triângulo com o triplo do lado.
//altura:h = l√3 / 2.
//area: b*h/2
//per: l*3

int main ( )
{
    float l = 0, h = 0, a = 0, p = 0;

    printf ("%s" , "\nExercicio 0116 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s", "Favor inserir o valor para um triangulo equilatero: ");
    scanf ("%f", &l);
    while (l <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de um triangulo ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor insira o valor para um triangulo equilatero: ");
        scanf ("%f", &l);
    }
    l = l*3;
    h = (sqrt(3)*l)/2;
    a = l*h;
    p = l*3;
    printf ("\nA altura de um triangulo equilatero com o triplo do lado e: %f\n", h);
    printf ("\nA area de um triangulo equilater com o triplo do lado e: %f\n", a);
    printf ("\nO perimetro de um triangulo equilatero com o triplo do lado e: %f\n", p);

    return 0;
}