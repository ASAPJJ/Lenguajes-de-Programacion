// Guía 3 - Ej 4: Par o impar (operador módulo)
#include <stdio.h>
int main() {
    int a;
    printf("Ingrese el valor a evaluar: ");
    scanf("%d", &a);
    if(a % 2 == 0){
        printf("El valor %d es par!\n", a);
    } else{
        printf("El valor %d es impar!\n", a);
    }
    return 0;
}
