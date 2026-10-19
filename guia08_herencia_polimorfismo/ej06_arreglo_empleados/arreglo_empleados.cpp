// Guía 8 - Ej 6: arreglo de Empleado* con Docente y NoDocente, mostrando el puesto de cada uno
// Sin 'new' -> no hace falta 'delete' (los objetos viven en main).
#include <iostream>
#include <string>
using namespace std;

class Persona {
    private:
        string nombre;
    public:
        void presentarse(){cout << "Hola, soy " << nombre << endl;}
        Persona (string nombre){
            this->nombre = nombre;
        }
};

class Empleado : public Persona{
    private:
        string institucion;
        string claveDeAcceso;
    protected:
        string puesto;
        float sueldo;
    public:
        Empleado(string nombre, string institucion, string puesto):Persona(nombre){
            this->institucion = institucion;
            this->puesto = puesto;
            this->sueldo= 0;
        }
        void ajustarSueldo(float cantidad){
            if(cantidad>0){
                sueldo=sueldo+cantidad;
            }else{
                cout << "Ingreso no valido" << endl;
            }
        }
        float getSueldo(){
            return sueldo;
        }
        string getPuesto(){
            return puesto;
        }
};

class NoDocente : public Empleado {
    public:
        NoDocente(string nombre, string institucion, string puesto):Empleado(nombre, institucion, puesto){
    }
};

class Docente : public Empleado{
    public:
        Docente(string nombre, string institucion, string puesto):Empleado(nombre, institucion, puesto){}
};

int main(){
    Empleado e("Ana","UNDEF","Administrativo");
    NoDocente n("Luis","UNDEF","Maestranza");
    Docente d("Mati","UNDEF","Docente");

    Empleado* trabajo[3];
    trabajo[0] = &e;
    trabajo[1] = &n;
    trabajo[2] = &d;

    for (int i = 0; i < 3; i++){
        cout << trabajo[i]->getPuesto() << endl;
    }
    return 0;
}
