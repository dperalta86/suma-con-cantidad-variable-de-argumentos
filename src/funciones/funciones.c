#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "funciones.h"

void mensajeBienvenida()
{
    printf("Formatear mensaje de bienvenida");
}

// Función para extraer los tokens del string (separados por espacios)
int split_string(const char *str, char **tokens, int max_tokens) {
    int count = 0;
    char *copy = strdup(str); // Copia el string para no modificar el original
    char *token = strtok(copy, " ");

    while (token != NULL && count < max_tokens) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, " ");
    }

    free(copy);
    return count;
}

// Función para verificar si un string es un entero
int is_integer(const char *str) {
    if (*str == '-' || *str == '+') str++;
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Función para verificar si un string es un flotante
int is_float(const char *str) {
    int has_decimal = 0;
    if (*str == '-' || *str == '+') str++;
    while (*str) {
        if (*str == '.') {
            if (has_decimal) return 0;
            has_decimal = 1;
        } else if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return has_decimal;
}

/* **********************************************************

    FUNCIÓN PRINCIPAL CON CANTIDAD VARIABLE DE ARGUMENTOS

************************************************************ */
float suma_x_parametros(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char *tokens[100]; // Máximo 100 tokens
    int num_tokens = split_string(format, tokens, 100);

    float sum_float = 0.0f;
    int sum_int = 0;

    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "%d") == 0) {
            int val = va_arg(args, int);
            sum_int += val;
        } else if (strcmp(tokens[i], "%f") == 0) {
            float val = (float)va_arg(args, double); // Los floats se promocionan a double en va_arg
            sum_float += val;
        } else if (is_integer(tokens[i])) {
            int val = atoi(tokens[i]);
            sum_int += val;
        } else if (is_float(tokens[i])) {
            float val = atof(tokens[i]);
            sum_float += val;
        } else {
            printf("Token desconocido: %s\n", tokens[i]);
        }
        free(tokens[i]); // Liberar memoria del token
    }

    va_end(args);
    return sum_float + (float)sum_int;
}