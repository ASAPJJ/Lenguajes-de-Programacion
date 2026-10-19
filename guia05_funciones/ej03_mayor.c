// Guía 5 - Ej 3: Mayor de dos números
#include <stdio.h>
int mayor(int a, int b);
int main() {
    int x, y, resultado;
    printf("Ingrese dos numeros: \n");
    scanf("%d %d", &x, &y);
    resultado = mayor(x, y);
    printf("El mayor es: %d\n", resultado);
    return 0;
}
int mayor(int a, int b) {
    if(a>b){ return a; } else { return b; }
}
