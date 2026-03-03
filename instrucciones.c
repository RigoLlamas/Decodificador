#include "instrucciones.h"

InstruccionesR R[] = {
    {0x00, 0x0, "add"},
    {0x20, 0x0, "sub"},
    {0x00, 0x4, "xor"},
    {0x00, 0x6, "or"},
    {0x00, 0x7, "and"}
};

int sizeR = sizeof(R) /sizeof(InstruccionesR);

