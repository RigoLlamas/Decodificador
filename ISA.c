#include <stdio.h>
#include <stdint.h>
#include "instrucciones.h"
#include "ISA.h"

void tipo_R(uint32_t codigo){
    uint32_t rd = (codigo >> 7) & 0x1F;
    uint32_t funct3 = (codigo >> 12) & 0x7;
    uint32_t rs1 = (codigo >> 15) & 0x1F;
    uint32_t rs2 = (codigo >> 20) & 0x1F;
    uint32_t funct7 = (codigo >> 25 ) & 0X7F;

    for (int i = 0; i < sizeR; ++i)
    {
        if (R[i].funct7 == funct7 && R[i].funct3 == funct3)
        {
            printf("Intruccion: %s\t|\trd: x%d\t|\trs1: x%d\t|\trs2: x%d",R[i].instruccion, rd, rs1, rs2);
            return;
        }
    }
    printf("func7: x%d\t|\tfunc3: x%d\t|\trd: x%d\t|\trs1: x%d\t|\trs2: x%d",funct7, funct3, rd, rs1, rs2);
}

void tipo_I(uint32_t codigo){}

void tipo_S(uint32_t codigo){}

void tipo_B(uint32_t codigo){}

void tipo_U(uint32_t codigo){}

void tipo_J(uint32_t codigo){}

void decodificar(uint32_t codigo)
{
    printf("\n");
    uint32_t opcode = codigo & 0x7F;

    switch (opcode)
    {
    case 0x33:
        tipo_R(codigo);
        break;
    case 0x13:
        tipo_I(codigo);
        break;
    case 0x23:
        tipo_S(codigo);
        break;
    case 0x63:
        tipo_B(codigo);
        break;
    case 0x17:
        tipo_U(codigo);
        break;
    case 0x6F:
        tipo_J(codigo);
        break;
    default:
        printf("Opcode no encontrado\n");
    }
}
