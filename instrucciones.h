#ifndef INSTRUCCIONES_H     //  Definicio de structuras para diccionarios
#define INSTRUCCIONES_H

#include <stdint.h>

typedef struct {
    uint8_t funct7;
    uint8_t funct3;
    char *instruccion;
} InstruccionesR;

extern InstruccionesR R[];
extern int sizeR;

typedef struct {
    uint8_t funct3;
    char *instruccion;
} InstruccionesI;

extern InstruccionesI I[];
extern InstruccionesI Il[];
extern int sizeI;
extern int sizeIl;

typedef struct {
    uint8_t funct3;
    char *instruccion;
} InstruccionesS;

extern InstruccionesS S[];
extern int sizeS;

typedef struct {
    uint8_t funct3;
    char *instruccion;
} InstruccionesB;

extern InstruccionesB B[];
extern int sizeB;


#endif
