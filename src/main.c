#include <stdio.h>
#include "funciones/funciones.h"

int main() {
    int user_int;
    float user_float;
    // Ejemplos de uso de la funcion.

    // Ejemplo con enteros literales y %d
    float resultado1 = suma_x_parametros("10 20 %d 30", 40); 
    printf("Resultado 1: (10 + 20 + 40 + 30) = %.2f\n", resultado1); // Debería dar 100.00

    // Ejemplo con enteros, float y literales %d y %f
    float resultado2 = suma_x_parametros("23 5 %d 23.6 4 %f", 10, 5.4f);
    printf("Resultado 2 = %.2f\n", resultado2);

    // Acá se pone interesante....
    printf("\nIngrese un entero: ");
    scanf("%d", &user_int);

    printf("Ingrese un float: ");
    scanf("%f", &user_float);
    // Pasamos los valores ingresados como %d y %f
    float resultado3 = suma_x_parametros("5.5 %d 10.5 %f", user_int, user_float);
    printf("Resultado 3: (5.5 + %d + 10.5 + %.2f) = %.2f\n", user_int, user_float, resultado3);


    return 0;
}
