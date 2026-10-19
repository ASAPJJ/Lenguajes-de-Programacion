// Guía 4 - Ej 7: Búsqueda lineal
#include <stdio.h>
int main() {
    int numeros[15];
    int buscado;
    for (int i=0; i<15;i++){
        printf("Ingrese los valores del vector: \n");
        scanf("%d", &numeros[i]);
    }
    printf("Ingrese el valor a buscar: \n");
    scanf("%d", &buscado);
    int posicion = -1;
    for(int i = 0;i<15;i++){
       if(numeros[i]==buscado){ posicion=i; break; }
    }
    for (int i=0; i<15;i++){ printf("[%d]", numeros[i]); }
    if (posicion != -1) {
        printf("Encontrado en la posicion: %d\n", posicion);
    } else {
        printf("No se encontro\n");
    }
    return 0;
}
