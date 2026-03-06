#include "instrucciones.h"

InstruccionesR R[] = {                          // Diccionario de instrucciones del tipo R
    {0x00, 0x0, "add"},
    {0x20, 0x0, "sub"},
    {0x00, 0x4, "xor"},
    {0x00, 0x6, "or"},
    {0x00, 0x7, "and"},
    {0x00, 0x1, "sll"},
    {0x00, 0x5, "srl"},
    {0x20, 0x5, "sra"},
    {0x00, 0x2, "slt"},
    {0x00, 0x3, "slu"},
};

int sizeR = sizeof(R)/sizeof(InstruccionesR);   // Definicion de tamaño del diccionario tipo R

InstruccionesI I[] = {                          // Diccionario de instrucciones del tipo I con opcode 0x13
    {0x0, "addi"},
    {0x7, "andi"},
    {0x6, "ori"},
};

InstruccionesI Il[] = {                         // Diccionario de instrucciones del tipo I con opcode 0x3
    {0x0, "lb"},
    {0x1, "lh"},
    {0x2, "lw"},
    {0x4, "lbu"},
    {0x5, "lhu"},
};


int sizeI = sizeof(I)/sizeof(InstruccionesI);   // Definicion de tamaño del diccionario tipo I con opcode 0x13
int sizeIl = sizeof(I)/sizeof(InstruccionesI);  // Definicion de tamaño del diccionario tipo I con opocede 0x3

InstruccionesS S[] = {                          // Diccionario de instrucciones del tipo S
    {0x0, "sb"},
    {0x1, "sh"},
    {0x2, "sw"},
};

int sizeS = sizeof(S)/sizeof(InstruccionesS);   // Definicion de tamaño del diccionario tipo S

InstruccionesB B[] = {                          // Diccionario de instrucciones del tipo B
    {0x0, "beq"},
    {0x1, "bne"},
    {0x4, "blt"},
    {0x5, "bge"},
};

int sizeB = sizeof(B)/sizeof(InstruccionesB);   // Definicion de tamaño del diccionario tipo B

