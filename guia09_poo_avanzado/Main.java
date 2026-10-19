public class Main {
    public static void main(String[] args) {
        ProductoFisico mouse = new ProductoFisico(1, "Mouse", 45000f, 0.2f, 10);
        ProductoFisico teclado = new ProductoFisico(2, "Teclado", 80000f, 0.9f, 5);
        ProductoDigital antivirus = new ProductoDigital(3, "Antivirus", 30000f,
                "https://ejemplo.com/descarga", "XXXX-XXXX-1234");
 
        Usuario usuario = new Usuario("Brunelli", "brunelli@ejemplo.com");
        usuario.iniciarCarrito();
 
        System.out.println("\n--- 1) Carrito mixto (fisicos + digital) ---");
        usuario.agregarAlCarrito(mouse, 2);
        usuario.agregarAlCarrito(teclado, 1);
        usuario.agregarAlCarrito(antivirus, 1);
        usuario.verCarrito();
        // Esperado: Mouse x2 0.4kg, Teclado x1 0.9kg, Antivirus 0.0kg -> peso total 1.3
 
        System.out.println("\n--- 2) Sumar a un producto existente ---");
        usuario.agregarAlCarrito(mouse, 3);
        usuario.verCarrito();
        // Esperado: Mouse x5 -> 1.0kg ; peso total 1.9
 
        System.out.println("\n--- 3) Cantidades invalidas (no deben cambiar nada) ---");
        usuario.agregarAlCarrito(mouse, -10);
        usuario.agregarAlCarrito(mouse, 0);
        usuario.agregarAlCarrito(teclado, -1);
        usuario.verCarrito();
        // Esperado: mismo carrito que en el paso 2
 
        System.out.println("\n--- 4) Producto nuevo con cantidad invalida ---");
        ProductoFisico monitor = new ProductoFisico(4, "Monitor", 250000f, 3.5f, 2);
        usuario.agregarAlCarrito(monitor, 0);
        usuario.agregarAlCarrito(monitor, -5);
        usuario.verCarrito();
        // Esperado: el Monitor NO aparece
 
        System.out.println("\n--- 5) Mostrar productos (polimorfismo) ---");
        Producto[] catalogo = { mouse, antivirus };
        for (Producto p : catalogo) {
            p.mostrarProducto();
        }
 
        System.out.println("\n--- 6) Finalizar compra ---");
        usuario.finalizarCompra();
        usuario.verCarrito();
    }
}