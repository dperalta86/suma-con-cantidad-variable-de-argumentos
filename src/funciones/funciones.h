#ifndef FUNCIONES_H  
#define FUNCIONES_H

void mensajeBienvenida();
float suma_x_variables (char[]);
int split_string(const char *, char **, int);
int is_float(const char *);
int is_integer(const char *);
// Funcion con cantidad variable de argumentos
float suma_x_parametros(const char *format, ...);

#endif