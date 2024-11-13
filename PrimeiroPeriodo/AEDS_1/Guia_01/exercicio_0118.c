/*
Exercio_0118 - 02/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>

//calcular e mostrar o volume do sólido com um oitavo desses valores.

int main()
{
    float c = 0, l = 0, a = 0, v = 0;
    printf ("%s" , "\nExercicio 0118 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s", "Favor insira um valor para o comprimento de um paralelepipedo: ");
    scanf ("%f", &c);
    while (c <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de um paralelepipedo ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor insira um valor para o comprimento de um paralelepipedo: ");
        scanf ("%f", &c);
    }
    printf ("%s", "\nFavor insira um valor para a largura de um paralelepipedo: ");
    scanf ("%f", &l);
    while (l <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de um paralelepipedo ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor insira um valor para a largura de um paralelepipedo: ");
        scanf ("%f", &l);
    }
    printf ("%s", "\nFavor insira um valor para a altura de um paralelepipedo: ");
    scanf ("%f", &a);
    while (a <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de um paralelepipedo ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor insira um valor para a altura de um paralelepipedo: ");
        scanf ("%f", &a);
    }
    c = c/8;
    l = l/8;
    a = a/8;
    v = c*l*a;
    printf ("\nO valor do volume de um paralelepipedo com um oitavo desses valores e: %10.2f",v );

    return 0;
}