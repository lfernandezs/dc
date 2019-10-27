#include "operaciones.h"
#include <stdio.h>
#include <string.h>

bool suma(int* sumando_1, int* sumando_2, int* resultado) {
    printf("SUMA: operando 1: %i - operando 2: %i\n", *sumando_1, *sumando_2);
    if (!sumando_1 || !sumando_2) return false;
    *resultado = (*sumando_1) + (*sumando_2);
    return true;
}

bool resta(int* minuendo, int* sustraendo, int* resultado) {
    if (!minuendo || !sustraendo) return false;
    *resultado = *minuendo - *sustraendo;
    return true;
}

bool mult(int* multiplicando, int* multiplicador, int* resultado) {
    if (!multiplicando || !multiplicador) return false;
    *resultado = *multiplicando * *multiplicador;
    return true;
}

bool division(int* dividendo, int* divisor, int* resultado) {
    if (!dividendo || !divisor || !*divisor) return false;
    *resultado = *dividendo / *divisor;
    return true;
}

bool pot(int* base, int* exponente, int* resultado) {
    if (!base || !exponente) return false;
    if (*exponente == 0) *resultado = 1;
    for (int i = 0; i < *exponente; i++) {
        *base *= *base;
    } 
    *resultado = *base;
    return true;
}

bool squareroot(int* radicando, int* resultado) {
    if (!radicando) return false;
    int raiz = *radicando/2;
    while (!((raiz-1)*(raiz-1) < *radicando && (raiz+1)*(raiz+1) > *radicando)) {
        if (raiz*raiz < *radicando) raiz = (raiz + *radicando) / 2;
        else if (raiz*raiz > *radicando) raiz /= 2;
    }
    *resultado = raiz;
    return true;
}

bool ter(int* condicion, int* caso_verdadero, int* caso_falso, int* resultado) {
    if (!condicion || !caso_verdadero || !caso_falso) return false;
    if (*condicion) *resultado = *caso_verdadero;
    else *resultado = *caso_falso;
    return true;
}

bool logaritmo(int* argumento, int* base, int* resultado) {
    if (!argumento || !base) return false;
    printf("operacion logaritmo\n");
    return true;
}

bool se_encuentra(char* buscado, char** vector, int largo) {
    for (int i = 0; i < largo; i++) {
        if (strcmp(buscado, vector[i]) == 0) return true;
    }
    return false;
}