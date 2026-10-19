#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>

using namespace std;

// Formatea un float como lo hace Java (ej: 90000 -> "90000.0")
string fmt(float valor) {
    ostringstream oss;
    oss << valor;
    string s = oss.str();
    if (s.find('.') == string::npos && s.find('e') == string::npos) {
        s += ".0";
    }
    return s;
}

class Producto {
private:
    int id;
    string nombre;
    float precio;

public:
    Producto(int id, const string& nombre, float precio)
        : id(id), nombre(nombre), precio(precio) {}

    virtual ~Producto() = default;

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    virtual float getPeso() const { return 0; }

    void setPrecio(float precio) { this->precio = precio; }
    void setNombre(const string& nombre) { this->nombre = nombre; }

    virtual void mostrarProducto() const {
        cout << "Producto: " << nombre << ", Precio: $" << fmt(precio) << endl;
    }
};

class ProductoFisico : public Producto {
private:
    float peso = 0;
    int stock = 0;

public:
    ProductoFisico(int id, const string& nombre, float precio, float peso, int stock)
        : Producto(id, nombre, precio) {
        setPeso(peso);
        setStock(stock);
    }

    void setPeso(float peso) {
        if (peso > 0) {
            this->peso = peso;
        } else {
            cout << "Peso invalido" << endl;
        }
    }

    void setStock(int stock) {
        if (stock >= 0) {
            this->stock = stock;
        } else {
            cout << "Stock invalido" << endl;
        }
    }

    int getStock() const { return stock; }
    float getPeso() const override { return peso; }

    void mostrarProducto() const override {
        Producto::mostrarProducto();
        cout << "Peso: " << fmt(peso) << "kg Stock: " << stock << endl;
    }
};

class ProductoDigital : public Producto {
private:
    string url;
    string licencia;

public:
    ProductoDigital(int id, const string& nombre, float precio,
                    const string& url, const string& licencia)
        : Producto(id, nombre, precio), url(url), licencia(licencia) {}

    void setUrl(const string& url) { this->url = url; }
    void setLicencia(const string& licencia) { this->licencia = licencia; }

    string getUrl() const { return url; }
    string getLicencia() const { return licencia; }

    void mostrarProducto() const override {
        Producto::mostrarProducto();
        cout << "Url: " << url << "Licencia: " << licencia << endl;
    }
};

class ItemCarrito {
private:
    const Producto* producto;  // no es dueño del producto
    int cantidad = 0;
    float subtotal = 0;
    float pesoTotal = 0;

    float calcularSubtotal() const { return producto->getPrecio() * cantidad; }
    float calcularPesoTotal() const { return producto->getPeso() * cantidad; }

public:
    ItemCarrito(const Producto* producto, int cantidad) : producto(producto) {
        setCantidad(cantidad);
        subtotal = calcularSubtotal();
        pesoTotal = calcularPesoTotal();
    }

    float getPesoTotal() const { return pesoTotal; }
    float getSubtotal() const { return subtotal; }
    int getCantidad() const { return cantidad; }
    string getProducto() const { return producto->getNombre(); }

    void incrementarCantidad(int cantidadAgregada) {
        if (cantidadAgregada <= 0) {
            cout << "Cantidad invalida" << endl;
        } else {
            setCantidad(cantidad + cantidadAgregada);
        }
    }

    void setCantidad(int cantidad) {
        if (cantidad > 0) {
            this->cantidad = cantidad;
            pesoTotal = calcularPesoTotal();
            subtotal = calcularSubtotal();
        } else {
            cout << "Cantidad invalida" << endl;
        }
    }

    void mostrarItem() const {
        cout << "- " << producto->getNombre() << " x" << cantidad
             << " -Peso: " << fmt(pesoTotal) << "kg -> $" << fmt(subtotal) << endl;
    }
};

class Carrito {
private:
    vector<ItemCarrito> items;

public:
    void agregarProducto(const Producto* producto, int cantidad) {
        if (cantidad > 0) {
            for (auto& item : items) {
                if (item.getProducto() == producto->getNombre()) {
                    // Si ya está, incrementa cantidad
                    item.incrementarCantidad(cantidad);
                    return;
                }
            }
            items.emplace_back(producto, cantidad);
        } else {
            cout << "Producto no agregado - Revisar cantidad" << endl;
        }
    }

    void eliminarProducto(const Producto* producto) {
        items.erase(
            remove_if(items.begin(), items.end(),
                      [&](const ItemCarrito& item) {
                          return item.getProducto() == producto->getNombre();
                      }),
            items.end());
    }

    void vaciarCarrito() { items.clear(); }

    float total() const {
        float total = 0;
        for (const auto& item : items) {
            total += item.getSubtotal();
        }
        return total;
    }

    float pesoTotal() const {
        float pesoSumado = 0;
        for (const auto& item : items) {
            pesoSumado += item.getPesoTotal();
        }
        return pesoSumado;
    }

    void mostrarCarrito() const {
        cout << "🛒 Carrito de compras:" << endl;
        if (items.empty()) {
            cout << "Carrito vacío." << endl;
        } else {
            for (const auto& item : items) {
                item.mostrarItem();
            }
            cout << "Total: $" << fmt(total()) << endl;
            cout << "Peso total: " << fmt(pesoTotal()) << endl;
        }
    }
};

class Usuario {
private:
    string nombre;
    string email;
    unique_ptr<Carrito> carrito;  // nullptr = sin carrito

public:
    Usuario(const string& nombre, const string& email)
        : nombre(nombre), email(email), carrito(nullptr) {}

    void iniciarCarrito() {
        if (!carrito) {
            carrito = make_unique<Carrito>();
            cout << "🛒 Carrito iniciado para " << nombre << endl;
        } else {
            cout << "Ya tienes un carrito activo." << endl;
        }
    }

    void agregarAlCarrito(const Producto* producto, int cantidad) {
        if (!carrito) {
            cout << "Debes iniciar tu carrito primero." << endl;
        } else {
            carrito->agregarProducto(producto, cantidad);
        }
    }

    void verCarrito() const {
        if (carrito) {
            carrito->mostrarCarrito();
        } else {
            cout << "No tienes un carrito activo." << endl;
        }
    }

    void finalizarCompra() {
        if (carrito) {
            cout << "Compra finalizada. Total a pagar: $" << fmt(carrito->total()) << endl;
            carrito->vaciarCarrito();
        } else {
            cout << "No se puede finalizar una compra sin carrito." << endl;
        }
    }
};

int main() {
    ProductoFisico mouse(1, "Mouse", 45000.0f, 0.2f, 10);
    ProductoFisico teclado(2, "Teclado", 80000.0f, 0.9f, 5);
    ProductoDigital antivirus(3, "Antivirus", 30000.0f,
                              "https://ejemplo.com/descarga", "XXXX-XXXX-1234");

    Usuario usuario("Brunelli", "brunelli@ejemplo.com");
    usuario.iniciarCarrito();

    cout << "\n--- 1) Carrito mixto (fisicos + digital) ---" << endl;
    usuario.agregarAlCarrito(&mouse, 2);
    usuario.agregarAlCarrito(&teclado, 1);
    usuario.agregarAlCarrito(&antivirus, 1);
    usuario.verCarrito();
    // Esperado: Mouse x2 0.4kg, Teclado x1 0.9kg, Antivirus 0.0kg -> peso total 1.3

    cout << "\n--- 2) Sumar a un producto existente ---" << endl;
    usuario.agregarAlCarrito(&mouse, 3);
    usuario.verCarrito();
    // Esperado: Mouse x5 -> 1.0kg ; peso total 1.9

    cout << "\n--- 3) Cantidades invalidas (no deben cambiar nada) ---" << endl;
    usuario.agregarAlCarrito(&mouse, -10);
    usuario.agregarAlCarrito(&mouse, 0);
    usuario.agregarAlCarrito(&teclado, -1);
    usuario.verCarrito();
    // Esperado: mismo carrito que en el paso 2

    cout << "\n--- 4) Producto nuevo con cantidad invalida ---" << endl;
    ProductoFisico monitor(4, "Monitor", 250000.0f, 3.5f, 2);
    usuario.agregarAlCarrito(&monitor, 0);
    usuario.agregarAlCarrito(&monitor, -5);
    usuario.verCarrito();
    // Esperado: el Monitor NO aparece

    cout << "\n--- 5) Mostrar productos (polimorfismo) ---" << endl;
    Producto* catalogo[] = { &mouse, &antivirus };
    for (Producto* p : catalogo) {
        p->mostrarProducto();
    }

    cout << "\n--- 6) Finalizar compra ---" << endl;
    usuario.finalizarCompra();
    usuario.verCarrito();

    return 0;
}