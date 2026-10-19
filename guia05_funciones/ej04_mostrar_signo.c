// Guía 5 - Ej 4: Procedimiento void mostrarSigno
#include <stdio.h>
void mostrarSigno(int n);
int main() {
    int numero;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    mostrarSigno(numero);
    return 0;
}
void mostrarSigno(int n) {
    if(n<0){ printf("Es negativo \n"); }
    else if (n==0){ printf("Es nulo \n"); }
    else{ printf("Es normal vale? \n"); }
}
