import java.util.ArrayList;

class Producto {
    private int id;
    private String nombre;
    private float precio;

    public Producto(int id, String nombre, float precio) {
        this.id = id;
        this.nombre = nombre;
        this.precio = precio;
    }

    public int getId() { return id; }
    public String getNombre() { return nombre; }
    public float getPrecio() { return precio; }
    public float getPeso() { return 0;}

    public void setPrecio(float precio) { this.precio = precio; }
    public void setNombre(String nombre) { this.nombre = nombre; }


    public void mostrarProducto() {
        System.out.println("Producto: " + nombre + ", Precio: $" + precio);
    }
}

class ProductoFisico extends Producto{
    private float peso = 0;
    private int stock;

    public ProductoFisico(int id, String nombre, float precio, float peso, int stock){
        super(id,nombre, precio);
        setPeso(peso);
        setStock(stock);
    }

    public void setPeso(float peso){
        if(peso>0){
            this.peso = peso;
        }else{
            System.out.println("Peso invalido");
        }}
    public void setStock(int stock) {
        if(stock>=0){
            this.stock = stock;
        }else{
            System.out.println("Stock invalido");
        }}

    public int getStock() { return stock; }
    @Override
    public float getPeso() { return peso; }

    @Override
    public void mostrarProducto(){
        super.mostrarProducto();
        System.out.println("Peso: " + peso + "kg Stock: " + stock );
    }
}

class ProductoDigital extends Producto{
    private String url;
    private String licencia;

    public ProductoDigital(int id, String nombre, float precio, String url,String licencia){
        super(id, nombre, precio);
        this.url = url;
        this.licencia = licencia;
    }
    public void setUrl(String url){this.url = url;}
    public void setLicencia(String licencia) { this.licencia = licencia; }

    public String getUrl() { return url ; }
    public String getLicencia() { return licencia; }

    @Override
    public void mostrarProducto(){
        super.mostrarProducto();
        System.out.println("Url: " + url + "Licencia: " + licencia );
    }
}

class ItemCarrito {
    private Producto producto;
    private int cantidad;
    private float subtotal;
    private float pesoTotal;

    public ItemCarrito(Producto producto, int cantidad) {
        this.producto = producto;
        setCantidad(cantidad);
        this.subtotal = calcularSubtotal();
        this.pesoTotal= calcularPesoTotal();
    }

    private float calcularSubtotal() {
        return producto.getPrecio() * cantidad;
    }
    private float calcularPesoTotal(){
        return producto.getPeso()*cantidad;
    }

    public float getPesoTotal(){return pesoTotal;}
    public float getSubtotal() { return subtotal; }
    public void incrementarCantidad(int cantidadAgregada) {
        if(cantidadAgregada<=0){
            System.out.println("Cantidad invalida");
        }else{
            setCantidad(cantidad+cantidadAgregada);
        }
    }

    public int getCantidad() { return cantidad; }
    public String getProducto() { return producto.getNombre(); }

    public void setCantidad(int cantidad){
        if(cantidad>0){
            this.cantidad=cantidad;
            pesoTotal=calcularPesoTotal();
            subtotal = calcularSubtotal();
        }else{
            System.out.println("Cantidad invalida");
        }
    }
    public void mostrarItem() {
        System.out.println("- " + producto.getNombre() + " x" + cantidad + " -Peso: "+ pesoTotal + "kg -> $" + subtotal);
    }
}


class Carrito {
    private ArrayList<ItemCarrito> items;

    public Carrito() {
        items = new ArrayList<>();
    }

    public void agregarProducto(Producto producto, int cantidad) {
        if(cantidad>0){
            for (ItemCarrito item : items) {
                if (item.getProducto().equals(producto.getNombre())) {
                    // Si ya está, incrementa cantidad
                    item.incrementarCantidad(cantidad);
                    return;
                }
            }
            items.add(new ItemCarrito(producto, cantidad));
        }else{
            System.out.println("Producto no agregado - Revisar cantidad");
        }
    }

    public void eliminarProducto(Producto producto) {
        items.removeIf(item -> item.getProducto().equals(producto.getNombre()));
    }

    public void vaciarCarrito() {
        items.clear();
    }

    public float total() {
        float total = 0;
        for (ItemCarrito item : items) {
            total += item.getSubtotal();
        }
        return total;
    }

    public float pesoTotal(){
        float pesoSumado = 0;
        for(ItemCarrito item : items){
            pesoSumado +=item.getPesoTotal();
        }
        return pesoSumado;
    }

    public void mostrarCarrito() {
        System.out.println("🛒 Carrito de compras:");
        if (items.isEmpty()) {
            System.out.println("Carrito vacío.");
        } else {
            for (ItemCarrito item : items) {
                item.mostrarItem();
            }
            System.out.println("Total: $" + total());
            System.out.println("Peso total: "+ pesoTotal());
        }
    }
}

class Usuario {
    private String nombre;
    private String email;
    private Carrito carrito;

    public Usuario(String nombre, String email) {
        this.nombre = nombre;
        this.email = email;
        this.carrito = null; // No tiene carrito al inicio
    }

    public void iniciarCarrito() {
        if (carrito == null) {
            carrito = new Carrito();
            System.out.println("🛒 Carrito iniciado para " + nombre);
        } else {
            System.out.println("Ya tienes un carrito activo.");
        }
    }

    public void agregarAlCarrito(Producto producto, int cantidad) {
        if (carrito == null) {
            System.out.println("Debes iniciar tu carrito primero.");
        } else {
            carrito.agregarProducto(producto, cantidad);
        }
    }

    public void verCarrito() {
        if (carrito != null) {
            carrito.mostrarCarrito();
        } else {
            System.out.println("No tienes un carrito activo.");
        }
    }

    public void finalizarCompra() {
        if (carrito != null) {
            System.out.println("Compra finalizada. Total a pagar: $" + carrito.total());
            carrito.vaciarCarrito();
        } else {
            System.out.println("No se puede finalizar una compra sin carrito.");
        }
    }
}
