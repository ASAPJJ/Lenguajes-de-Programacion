// Guía 7 - Clase Persona (C++)
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
	string nombre,dni;
	int edad;

public:
	Persona(string nombre,int edad,string dni) {
	    this->nombre=nombre;
	    this->edad=edad;
	    this->dni=dni;
	}

	void presentarse() {
	    cout <<"Hola! Mi nombre es " << nombre <<", mi edad es: "<< edad << ". Y mi DNI es: " << dni <<endl;
	}
};

int main()
{
	Persona perso1("Ernesto", 25, "43253123");
	perso1.presentarse();
	return 0;
}
