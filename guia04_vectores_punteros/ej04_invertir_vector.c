// Guía 4 - Ej 4: Invertir un vector (in-place)
#include <stdio.h>
int main() {
    int numeros[10];
    for (int i=0; i<10;i++){
        printf("Ingrese los valores del vector:  \n");
        scanf("%d", &numeros[i]);
    }
    for (int inicio = 0, fin= 9; inicio<fin ; inicio++, fin-- ) {
        int temp;
        temp = numeros[inicio];
        numeros[inicio] = numeros[fin];
        numeros[fin] = temp;
    }
    for (int i=0; i<10;i++){ printf("[%d]", numeros[i]); }
    return 0;
}
