// Guía 4 - Ej 1: Suma de los elementos de un vector
#include <stdio.h>
int main() {
    int numeros[10];
    int suma = 0;
    for (int i=0; i<10;i++){
        printf("Ingrese un valor para el vector: \n");
        scanf("%d", &numeros[i]);
        printf("[%d]\n", numeros[i]);
    }
    for (int i=0;i<10;i++){
        suma = suma + numeros[i];
    }
    printf("La suma de los componentes del vector: %d\n", suma);
    return 0;
}
