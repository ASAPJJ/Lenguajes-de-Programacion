// Guía 3 - Ej 17: Tabla de multiplicar
#include <stdio.h>
int main() {
    int a, multi;
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    for(int i = 1; i <= 10; i++){
        multi = a * i;
        printf("%d x %d = %d \n", a, i, multi);
    }
    return 0;
}
