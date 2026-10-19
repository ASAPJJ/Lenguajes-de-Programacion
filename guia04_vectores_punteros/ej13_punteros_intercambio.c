// Guía 4 - Ej 13: Intercambio de valores con punteros
#include <stdio.h>
int main() {
    int a, b;
    printf("Ingrese el valor de a: ");
    scanf("%d", &a);
    printf("Ingrese el valor de b: ");
    scanf("%d", &b);
    printf("Antes del intercambio: a=%d, b=%d\n", a, b);
    int *pa = &a;
    int *pb = &b;
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("Despues del intercambio: a=%d, b=%d\n", a, b);
    return 0;
}
