// Guía 3 - Ej 9: Promedio de notas
#include <stdio.h>
int main() {
    float nota1, nota2, promedio;
    printf("Ingrese la 1ra nota: ");
    scanf("%f", &nota1);
    printf("Ingrese la 2da nota: ");
    scanf("%f", &nota2);
    promedio = (nota1 + nota2) / 2;
    if(promedio >= 4.5){
        printf("El promedio es satisfactorio, aprobado\n");
    } else{
        printf("El promedio es insatisfactorio, desaprobado\n");
    }
    return 0;
}
