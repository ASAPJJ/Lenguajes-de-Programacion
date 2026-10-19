// Guía 8 - Ej 5: ajustarSueldo() es la única forma de modificar el sueldo (valida cantidad > 0)
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
    e.ajustarSueldo(100);
    cout << e.getSueldo() << endl;

    NoDocente n("Luis","UNDEF","Maestranza");
    n.ajustarSueldo(-50);          // inválido: se rechaza
    cout << n.getSueldo() << endl;

    Docente d("Mati","UNDEF","Docente");
    d.ajustarSueldo(300);
    cout << d.getSueldo() << endl;
    return 0;
}
