// Guía 8 - Ej 7: polimorfismo con hacerSonido() (C++). La versión en Java queda pendiente.
#include <iostream>
#include <string>
using namespace std;

class Animal{
    public:
        virtual void hacerSonido(){
            cout << "Grr"<< endl;
        }
};

class Gato : public Animal{
    public:
        void hacerSonido(){
            cout << "Miau"<< endl;
        }
};

class Perro : public Animal{
    public:
        void hacerSonido(){
            cout << "Wof" << endl;
        }
};

int main(){
    Animal churro;
    Gato bigote;
    Perro thor;

    Animal* mascotas[3] = {&churro,&bigote,&thor};

    for(int i=0;i<3;i++){
        mascotas[i]->hacerSonido();
    }
    return 0;
}
