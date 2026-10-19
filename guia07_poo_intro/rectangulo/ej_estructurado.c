// Guía 7 - Área de un rectángulo, versión estructurada (C)
#include <stdio.h>

int main() {
    float base,altura, area = 0;
    
    printf("Ingrese la Base y la Altura \n");
    scanf("%f %f", &base, &altura);
    
    area = (base * altura);
    
    printf("El area es: %.2f \n", area);
    return 0;
}
