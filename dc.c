#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "strutil.h"
#include "operaciones.h"
#include <stdlib.h>

#define CANT_OPERADORES 8


/* RECORDAR: Destruir vector, destruir pila, destruir desapilados */
void print_error() {
    printf("ERROR\n");
}

void rstrip(char* cadena, char caracter) {
  size_t tam = strlen(cadena);
    printf("rstrip: '%c'\n", cadena[tam - 1]);
    if (cadena[tam - 1] == caracter) cadena[tam - 1] = '\0';
}

bool is_digit(char* cadena) {
  for (int i = 0; cadena[i] != '\0'; i++) {
    if ('0' > cadena[i] || cadena[i] > '9') return false;
  }
  return true;
}


bool aplicar_operador(int* op_1, int* op_2, int* ternario, char* operador, int* resultado) {
    if (strcmp(operador, "+") == 0) return suma(op_1, op_2, resultado);
    if (strcmp(operador, "-") == 0) return resta(op_1, op_2, resultado);
    if (strcmp(operador, "*") == 0) return mult(op_1, op_2, resultado);
    if (strcmp(operador, "/") == 0) return division(op_1, op_2, resultado);
    if (strcmp(operador, "^") == 0) return pot(op_1, op_2, resultado);
    if (strcmp(operador, "sqrt") == 0) return squareroot(op_1, resultado);
    if (strcmp(operador, "log") == 0) return logaritmo(op_1, op_2, resultado);
    if (strcmp(operador, "?") == 0) return ter(op_1, op_2, ternario, resultado);
    return false;
}

void calcular(char* linea) {
    char* operadores[CANT_OPERADORES] = {"+", "-", "*", "/", "^", "sqrt", "log", "?"};
    pila_t* pila = pila_crear();
    char** ecuacion = split(linea, ' ');
    int aux[sizeof(ecuacion)]; // Donde guardo los punteros a los números.
    int* operando_1 = NULL;
    int* operando_2 = NULL;
    int* ternario = NULL;
    int resultado = 0;
    for (int i = 0; ecuacion[i]; i++) {
        printf("elemento: %s\n", ecuacion[i]);
        if (se_encuentra(ecuacion[i], operadores, CANT_OPERADORES)) {
            printf("Es operador\n");
            operando_1 = pila_desapilar(pila);
            printf("operando 1: %i\n", *operando_1);
            operando_2 = pila_desapilar(pila);
            printf("operando 2: %i\n", *operando_2);
            ternario = pila_desapilar(pila);
            bool coherencia = aplicar_operador(operando_1, operando_2, ternario, ecuacion[i], &resultado);
            if (coherencia == false) {
                printf("No coherencia\n");
                print_error();
                return;
            }
            if (ternario && strcmp(ecuacion[i], "?") != 0) pila_apilar(pila, ternario); // Apilo las variables que no usé
            if (operando_2 && strcmp(ecuacion[i], "sqrt") == 0) pila_apilar(pila, operando_2);
            pila_apilar(pila, &resultado);

        } else if (is_digit(ecuacion[i])) {
            printf("Es digito\n");
            aux[i] = atoi(ecuacion[i]);
            pila_apilar(pila, &aux[i]);

        } else {
            printf("No es ni digito ni operador\n");
            print_error();
            return;
        }
        printf("resultado*: %i\n", resultado);
    }
    printf("resultado: %i\n", resultado);
    pila_desapilar(pila);
    free_strv(ecuacion);
    pila_destruir(pila);
}

void evaluar_lineas() {
    char* linea = NULL;
    size_t tam = 0;
    while (getline(&linea, &tam, stdin) > 0) {
        rstrip(linea, '\n');
        calcular(linea);
    }
    free(linea);
}

int main() {
    evaluar_lineas();
    return 0;
}