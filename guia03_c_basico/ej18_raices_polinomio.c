// Guía 3 - Ej 18: Raíces de un polinomio (fórmula resolvente)
#include <stdio.h>
#include <math.h>
int main() {
    int a,b,c;
    float result, x1, x2;
    a=2; b=-1; c=-6;
    if((b*b)-(4*a*c)<0){
        printf("No se puede calcular\n");
    }else{
        result = sqrt((b*b)-(4*a*c));
        x1= ((-b) + result)/(2*a);
        x2= ((-b) - result)/(2*a);
        printf("Las raices son, x1: %.2f y x2: %.2f \n", x1, x2);
    }
    return 0;
}
