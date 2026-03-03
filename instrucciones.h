#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <stdint.h>

typedef struct {
    uint8_t funct7;
    uint8_t funct3;
    char *instruccion;
} InstruccionesR;

extern InstruccionesR R[];
int sizeR;

#endif