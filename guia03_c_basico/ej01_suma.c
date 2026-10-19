// Guía 3 - Ej 1: Suma de dos números
#include <stdio.h>
int main() {
    int a, b, suma;
    printf("Ingrese el valor a: ");
    scanf("%d", &a);
    printf("Ingrese el valor b: ");
    scanf("%d", &b);
    suma = a + b;
    printf("La suma de %d + %d es = %d\n", a, b, suma);
    return 0;
}
