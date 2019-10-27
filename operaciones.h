#include <stdbool.h>

bool suma(int* sumando_1, int* sumando_2, int* resultado);
bool resta(int* minuendo, int* sustraendo, int* resultado);
bool mult(int* multiplicando, int* multiplicador, int* resultado);
bool division(int* dividendo, int* divisor, int* resultado);
bool pot(int* base, int* exponente, int* resultado);
bool squareroot(int* radicando, int* resultado);
bool logaritmo(int* argumento, int* base, int* resultado);
bool ter(int* condicion, int* caso_verdadero, int* caso_falso, int* resultado);
bool se_encuentra(char* buscado, char** vector, int largo);