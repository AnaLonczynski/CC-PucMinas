/*
Exercio_0117 - 02/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>
#include <math.h>

//calcular e mostrar o volume do sólido com cinco vezes a medida do lado.

int main()
{
    float l = 0, v = 0;
  
    printf ("%s" , "\nExercicio 0117 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s", "Favor insira o valor para um lado de um cubo: ");
    scanf ("%f", &l);
    
    while (l <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de um cubo ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor insira o valor para um lado de um cubo: ");
        scanf ("%f", &l);
    }

    l = l*5;
    v = pow (l,3);
    printf ("\nO valor do volume de um cubo com o lado cinco vezes maior e: %10.2f\n", v);

    return 0;
}