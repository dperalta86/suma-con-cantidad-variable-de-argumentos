# suma_x_parametros: Función de Suma con Parámetros Variables en C
### 📚 Contexto Académico

Este proyecto surgió como una exploración práctica durante la clase de Sintaxis y Semántica de Lenguajes, específicamente al estudiar:

    Declaraciones vs. Definiciones.

    Manejo de argumentos variables (como en printf).

    Tipos de datos y conversiones implícitas (casteo de int a float).

La función imita el comportamiento de printf pero sumando números en lugar de formatearlos, combinando literales ("23.5") y marcadores dinámicos (%d, %f).
🔍 Cómo Funciona
1. Análisis del Formato

    Divide el string en tokens usando espacios como separadores.
    Ejemplo: "10 %d 20.5" → ["10", "%d", "20.5"].

    Clasifica cada token:

        %d o %f: Reemplazado por un argumento variable.

        Literal numérico: Convertido a int o float según su formato.

2. Suma por Separado

    Enteros (int): Acumulados en una suma aparte (ej: 10 + %d).

    Flotantes (float): Sumados en otra variable (ej: 20.5 + %f).

3. Unificación de Resultados

    Los enteros se convierten a float y se suman al total flotante.

    Precisión: Se evita pérdida de datos al castear después de sumar enteros.

🛠 Ejecución y Pruebas
Compilación
sh

make        # Compila el programa
./suma_x_parametros  # Ejecuta los ejemplos
make clean  # Elimina el binario

Ejemplos de Uso
c

// Ejemplo 1: Literales + argumentos variables
float r1 = suma_x_parametros("5 %d 10.5 %f", 3, 2.5f);
// 5 + 3 + 10.5 + 2.5 = 21.0

// Ejemplo 2: Solo enteros
float r2 = suma_x_parametros("100 %d", 50);
// 100 + 50 = 150.0

// Ejemplo 3: Entrada manual (usando scanf)
int x; float y;
scanf("%d %f", &x, &y);
float r3 = suma_x_parametros("%d %f", x, y);

📝 Detalles Técnicos Clave

    Manejo de memoria: Libera tokens dinámicos para evitar leaks.

    Seguridad: Verifica que los literales sean números válidos.

    Flexibilidad: Acepta cualquier combinación de literales y marcadores.

🌟 ¿Por Qué Es Interesante?

    Demuestra cómo C maneja argumentos variables con <stdarg.h>.

    Combina análisis de strings, conversión de tipos y aritmética.

    Útil para entender funciones como printf o scanf desde adentro.


🚀 Cómo Contribuir
Cloná el repo:
```
sh

git clone https://github.com/dperalta86/suma-con-cantidad-variable-de-argumentos.git
```
Explora el codigo y comentame mejoras o consultas!