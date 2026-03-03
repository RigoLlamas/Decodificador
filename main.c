#include <stdio.h>
#include <stdint.h>
#include "ISA.h"



int main(){
    uint32_t codigo = 0;
    printf("Ingresa instrucción en hexadecimal (ej: 002081B3): ");
    scanf("%x",&codigo);
    decodificar(codigo);
    return 0;
}