#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include "pila.h"
#include "strutil.h"
#include "operaciones.h"
#include "is_digit.c"

bool aplicar_operador(int* op_1, int* op_2, int* ternario, char* operador, int* resultado) {
    switch(operador) {
        case "+":
            return suma(op_1, op_2, resultado);
            break;
        case "-":
            return resta(op_1, op_2, resultado);
            break;
        case "*":
            return mult(op_1, op_2, resultado);
            break;
        case "/":
            return div(op_1, op_2, resultado);
            break;
        case "^":
            return pot(op_1, op_2, resultado);
            break;
        case "sqrt":
            return sqrt(op_1, resultado);
            break;
        case "log":
            return log(op_1, op_2, resultado);
            break;
        case "?":
            return ter(op_1, op_2, ternario, resultado);
            break;
    }
    return false;
}

void calcular(char* linea) {
    char* operadores[8] = {"+", "-", "*", "/", "^", "sqrt", "log", "?"};
    pila_t* pila = pila_crear();
    char** ecuacion = split(linea, ' ');
    int* operando_1 = NULL;
    int* operando_2 = NULL;
    int* ternario = NULL;
    int resultado = 0;
    for (int i = 0; ecuacion[i]; i++) {
        if (se_encuentra(ecuacion[i], operadores)) {
            operando_1 = pila_desapilar(pila);
            operando_2 = pila_desapilar(pila);
            ternario = pila_desapilar(pila);
            bool aux = aplicar_operador(operando_1, operando_2, ternario, ecuacion[i], &resultado);
            if (!aux) {
                printf("Error.");
                return;
            }
            if (strcmp(ecuacion[i], "?") != 0) pila_apilar(pila, ternario);
            if (strcmp(ecuacion[i], "sqrt") == 0) pila_apilar(pila, operando_2);
            pila_apilar(pila, &resultado);
        } else if (is_digit(ecuacion[i])) {
            pila_apilar(pila, &ecuacion[i]);
        } else {
            printf("Error.");
            return;
        }
    }
    printf("%i", resultado);

}

void evaluar_lineas() {
    char* linea = NULL;
    size_t tam = 0;
    while (getline(&linea, &tam, stdin) > 0) {
        calcular(linea);
    }
}

int main() {
    evaluar_lineas();
    return 0;
}