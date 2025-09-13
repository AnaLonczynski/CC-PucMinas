/*
Exercio_0119 - 02/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>
#include <math.h>

//supor que esse valor represente o raio de um círculo
//calcular e mostrar a área de um semicírculo com um sexto do raio
// PIr^2.

int main ()
{
    float r = 0, rr = 0, a = 0, PI = 3.1415;

    printf ("%s" , "\nExercicio 0119 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s", "Favor inserir um valor para o raio de um semicirculo: ");
    scanf ("%f", &r);
    while (r <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de um semicirculo ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor inserir um valor para o raio de um semicirculo: ");
        scanf ("%f", &r);
    }
    r = r/6;
    rr = pow(r,2);
    a = (PI * rr)/2;
    printf ("\nA area de um semicirculo com um sexto do raio e: %f\n", a);

    return 0;
}
