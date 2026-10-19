// Guía 7 - Persona (Java) final: getters y setter con validación
public class Main {
	public static void main(String[] args) {
		Persona perso1 = new Persona("JJ", 25,"23244325");
		perso1.cumplirAnios();
		perso1.presentarse();
		System.out.println(perso1.getNombre());
		perso1.setEdad(19);
		System.out.println(perso1.getEdad());
		System.out.println("Es mayor de edad? " + perso1.esMayorDeEdad());
	}
}

class Persona {
	private String nombre;
	private int edad;
	private String dni;

	public Persona(String nombre,int edad,String dni) {
		this.nombre = nombre;
		this.edad = edad;
		this.dni = dni;
	}

	public void presentarse() {
		System.out.println("Mi nombre es: " + nombre + " , y mi edad es: " + edad + ". Y mi DNI es: " + dni);
	}

	public int cumplirAnios() {
		edad=edad+1;
		return edad;
	}

	public boolean esMayorDeEdad() {
		return edad>=18;
	}

	public String getNombre() {
		return nombre;
	}

	public void setEdad(int edad) {
		if(edad>=0&&edad<100) {
			this.edad=edad;
		} else {
			System.out.println("Ingrese una edad valida");
		}
	}

	public int getEdad() {
		return edad;
	}
}
