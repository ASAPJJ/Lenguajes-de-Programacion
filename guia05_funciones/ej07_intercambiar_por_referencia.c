// Guía 5 - Ej 7: Intercambio por referencia
#include <stdio.h>
void intercambiar(int *a, int *b);
int main() {
    int x, y;
    printf("Ingrese el valor de x: ");
    scanf("%d", &x);
    printf("Ingrese el valor de y: ");
    scanf("%d", &y);
    printf("Antes: x=%d, y=%d\n", x, y);
    intercambiar(&x, &y);
    printf("Despues: x=%d, y=%d\n", x, y);
    return 0;
}
void intercambiar(int *a, int *b) {
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}
