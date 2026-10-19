// Guía 3 - Ej 13: ¿Es un triángulo válido?
#include <stdio.h>
int main() {
    float a, b, c;
    printf("Ingrese el 1er lado: ");
    scanf("%f", &a);
    printf("Ingrese el 2do lado: ");
    scanf("%f", &b);
    printf("Ingrese el 3er lado: ");
    scanf("%f", &c);
    if( a+b>c && b+c>a && a+c>b ){
        printf("El triangulo es valido\n");
    }else{
        printf("El triangulo es invalido\n");
    }
    return 0;
}
