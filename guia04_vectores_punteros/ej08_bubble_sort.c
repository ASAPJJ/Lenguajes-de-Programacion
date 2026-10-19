// Guía 4 - Ej 8: Ordenamiento burbuja
#include <stdio.h>
int main() {
    int numeros[10];
    for (int i=0; i<10;i++){
        printf("Ingrese los valores del vector: \n");
        scanf("%d", &numeros[i]);
    }
    for (int pasada = 0; pasada < 9; pasada++) {
        for (int i = 0; i < 9; i++) {
            if (numeros[i] > numeros[i+1]) {
                int temp = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = temp;
            }
        }
    }
    for (int i=0; i<10;i++){ printf("[%d]", numeros[i]); }
    return 0;
}
