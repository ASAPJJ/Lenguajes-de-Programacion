// Guía 5 - Ej 1: Funciones suma y resta
#include <stdio.h>
int sumar(int a, int b);
int restar(int a, int b);
int main() {
    int x, y, resultadoSuma, resultadoResta;
    printf("Ingrese dos numeros: \n");
    scanf("%d %d", &x, &y);
    resultadoSuma = sumar(x,y);
    resultadoResta = restar(x,y);
    printf("Este es el resultado de la SUMA: %d \n", resultadoSuma);
    printf("Este es el resultado de la RESTA: %d \n", resultadoResta);
    return 0;
}
int sumar(int a, int b){ return a+b; }
int restar(int a, int b){ return a-b; }
