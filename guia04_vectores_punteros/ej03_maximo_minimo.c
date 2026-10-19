// Guía 4 - Ej 3: Máximo y mínimo con su posición
#include <stdio.h>
int main() {
    int numeros[20];
    int posicion = 0;
    int posicionMin = 0;
    for (int i=0; i<20;i++){
        printf("Ingrese los valores del vector: ");
        scanf("%d", &numeros[i]);
    }
    int maximo = numeros[0];
    for (int i = 1; i < 20; i++) {
        if (maximo < numeros[i]) { maximo = numeros[i]; posicion = i; }
    }
    int min = numeros[0];
    for (int i = 1; i < 20; i++) {
        if (min > numeros[i]) { min = numeros[i]; posicionMin = i; }
    }
    for (int i=0; i<20;i++){ printf("[%d]", numeros[i]); }
    printf("El maximo es: %d\n En la posicion: %d\n", maximo, posicion);
    printf("El minimo es: %d\n En la posicion: %d\n", min, posicionMin);
    return 0;
}
