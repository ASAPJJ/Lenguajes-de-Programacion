// Guía 7 - Clase Rectangulo (Java)
public class Main {
    public static void main(String[] args) {
        Rectangulo rec1 = new Rectangulo(5, 3);   
        System.out.println("El area es: " + rec1.calcularArea());                       
    }
}

class Rectangulo {
    private float base;
    private float altura;


    public Rectangulo(float base, float altura) {
        this.base = base;
        this.altura = altura;
    }


    public float calcularArea() {
        float area;
        area = base * altura;
        return area;
    }
}
