// Guía 8 - Ej 3: herencia Persona -> Empleado -> Docente / NoDocente (C++)
// Constructores encadenados con :Padre(args). La versión en Java queda pendiente.
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
    e.presentarse();
    NoDocente n("Luis","UNDEF","Maestranza");
    n.presentarse();
    Docente d("Mati","UNDEF","Docente");
    d.presentarse();
    return 0;
}
