// Guía 8 - Ej 8: Forma_Geometrica -> Circulo / Rectangulo / Cuadrado (polimorfismo + encapsulamiento, C++)
#include <iostream>
#include <string>
using namespace std;

class FormaGeometrica{
    protected:
    float area;
    public:
        virtual float calcularArea(){
            return 0;
        }
};

class Circulo : public FormaGeometrica{
    private:
        float radio;
    public:
        Circulo(float radio){
            this->radio = radio;
        }
        float calcularArea(){
            area = 3.141 * (radio*radio);
            return area;
        }
};

class Rectangulo : public FormaGeometrica{
    private:
        float base;
        float altura;
    public:
        Rectangulo(float base, float altura){
            this->base=base;
            this->altura=altura;
        }
        float calcularArea(){
            area = (base * altura);
            return area;
        }

};

class Cuadrado : public FormaGeometrica{
    private:
        float lado;
    public:
        Cuadrado (float lado){
            this-> lado=lado;
        }
        float calcularArea(){
            area= lado*lado;
            return area;
        }
};

int main(){
    Circulo c1(1);
    Circulo c2(2);
    Rectangulo r1(2, 3);
    Rectangulo r2(4, 5);
    Cuadrado q1(4);
    Cuadrado q2(3);

    FormaGeometrica* figuras[6] = {&c1, &c2, &r1, &r2, &q1, &q2};

    for(int i = 0; i < 6; i++){
        cout << "Area de la figura " << i + 1 << ": " << figuras[i]->calcularArea() << endl;
    }
    return 0;
}
