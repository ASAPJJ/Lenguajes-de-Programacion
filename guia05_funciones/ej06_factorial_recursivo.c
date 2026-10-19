// Guía 5 - Ej 6: Factorial recursivo
#include <stdio.h>
int factorial(int n);
int main() {
    int a, resultado;
    printf("Ingrese un número: \n");
    scanf("%d", &a);
    resultado = factorial(a);
    printf("El factorial es: %d\n", resultado);
    return 0;
}
int factorial(int n) {
    if (n==0) { return 1; }
    else { return n * factorial(n-1); }
}
