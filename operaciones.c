#include "operaciones.h"

bool suma(int* sumando_1, int* sumando_2, int* resultado) {
    if (!sumando_1 || !sumando_2) return false;
    *resultado = *sumando_2 + *sumando_2;
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

bool div(int* dividendo, int* divisor, int* resultado) {
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