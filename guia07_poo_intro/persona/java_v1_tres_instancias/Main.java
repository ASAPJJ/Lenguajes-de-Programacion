// Guía 7 - Persona (Java): 3 instancias, cumplirAnios() y esMayorDeEdad()
public class Main {
    public static void main(String[] args) {
        Persona perso1 = new Persona("JJ", 25 ,"23244325");
        perso1.cumplirAnios();
        perso1.presentarse();
        
        Persona perso2 = new Persona("Aegis", 22 ,"23444325");
        perso2.cumplirAnios();
        perso2.presentarse();
        
        Persona perso3 = new Persona("Israel", 15 ,"63544325");
        perso3.cumplirAnios();
        perso3.presentarse(); 
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
    
    public boolean esMayorDeEdad(){
        return edad>=18;
    }
}
