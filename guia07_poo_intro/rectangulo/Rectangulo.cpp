// Guía 7 - Clase Rectangulo (C++)
#include <iostream>
using namespace std;

class Rectangulo{
    private:
        float altura,base;
    
    public:
    Rectangulo(float b, float h){
        base=b;
        altura=h;
    }
    
    float calcularArea(){
        float area;
        area = base * altura;
        return area;
    }
};

int main()
{
    Rectangulo rec1(5.00, 3.00);
    cout <<"El area es: " << rec1.calcularArea();
    return 0;
}
