# Lenguajes de Programación

Ejercicios de las guías prácticas de la materia **Lenguajes de Programación**
(Licenciatura en Ciberdefensa, 1.er año). Los resolví yo, paso a paso, como
práctica para construir una base sólida de lógica y programación.


## Contenido

| Carpeta | Tema | Lenguaje |
|---|---|---|
| `guia03_c_basico` | Entrada/salida, condicionales, bucles, `math.h` | C |
| `guia04_vectores_punteros` | Vectores, ordenamiento, búsqueda, punteros | C |
| `guia05_funciones` | Funciones, `void`, recursión, paso por referencia | C |
| `guia06_c_pascal_basic` | Comparativa de lenguajes (Hola Mundo y suma) | Pascal, BASIC |
| `guia07_poo_intro` | Clases, objetos, constructor, `this`, encapsulamiento | C, C++, Java |
| `guia08_herencia_polimorfismo` | Herencia, polimorfismo (`virtual`), arreglos de punteros al padre y diagramas UML | C++, UML |

## Cómo compilar

```bash
# C (agregar -lm si usa math.h)
gcc archivo.c -o programa -lm && ./programa

# C++
g++ archivo.cpp -o programa && ./programa

# Java (el archivo se llama Main.java)
javac Main.java && java Main
```

Pascal y BASIC se probaron en OneCompiler (Free Pascal / FreeBASIC).

## Notas

- Cada archivo tiene en la primera línea el nombre del ejercicio.
- `guia08_herencia_polimorfismo/` tiene un archivo por ejercicio (Ej 1 y 2 son los UML):
  Ej 3 (herencia y constructores), Ej 5 (`ajustarSueldo`), Ej 6 (arreglo de `Empleado*`),
  Ej 7 (animales) y Ej 8 (figuras). Todo en C++.
- Pendiente: Ej 4 (validar acceso a clave y sueldo) y las versiones en Java de los Ej 3, 7 y 8.
- Herramientas: OnlineGDB, OneCompiler, Lucidchart (UML).
# Lenguajes-de-Programacion
