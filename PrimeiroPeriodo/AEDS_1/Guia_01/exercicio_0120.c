/*
Exercio_0120 - 03/03/2024
Author: Ana Clara Lonczynski
*/

#include <stdio.h>
#include <math.h>

//calcular e mostrar o volume de uma esfera com três quartos do raio
//V = 4/3 π r³

int main ()
{
    float r , PI, v , f, rr, a; 
    r = 0;
    v = 0 ;
    a = 0;
    PI = 3.14159265359 ;

    printf ("%s" , "\nExercicio 0120 - Author: Ana Clara Lonczynski\n\n");
    printf ("%s", "Favor inserir um valor para o raio de uma esfera: ");
    scanf ("%f", &r);

    while (r <=0)
    {
        printf ("%s" , "\nERRO: condicao de existencia de uma esfera ferida. Favor inserir um valor positivo maior que 0.");
        printf ("%s","\nFavor inserir um valor para o raio de uma esfera: ");
        scanf ("%f", &r);
    }
    a = (3 * r) /4;
    rr = pow (a,3);
    v = (PI * rr*4)/3;
    printf (" O volume de uma esfera com tres quartos do raio e: %f", v);

    return 0;
}