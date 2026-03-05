#include <stdio.h>
#include <stdint.h>
#include "instrucciones.h"
#include "ISA.h"

void tipo_R(uint32_t codigo)
{
    printf("Forma R:\t");
    uint32_t rd = (codigo >> 7) & 0x1F;
    uint32_t funct3 = (codigo >> 12) & 0x7;
    uint32_t rs1 = (codigo >> 15) & 0x1F;
    uint32_t rs2 = (codigo >> 20) & 0x1F;
    uint32_t funct7 = (codigo >> 25) & 0X7F;

    for (int i = 0; i < sizeR; ++i)
    {
        if (R[i].funct7 == funct7 && R[i].funct3 == funct3)
        {
            printf("%s x%d x%d x%d\n", R[i].instruccion, rd, rs1, rs2);
            return;
        }
    }
    printf("(Sin funcion definida en el sistema)\n");
    printf("x%d x%d x%d x%d x%d\n", funct7, funct3, rd, rs1, rs2);
}

void tipo_I(uint32_t codigo, uint32_t opcode)
{
    printf("Forma I:\t");
    uint32_t rd = (codigo >> 7) & 0x1F;
    uint32_t funct3 = (codigo >> 12) & 0x7;
    uint32_t rs1 = (codigo >> 15) & 0x1F;

    int32_t imm = (int32_t)codigo >> 20;
    if (opcode == 0x13)
    {
        for (int i = 0; i < sizeI; ++i)
        {
            if (I[i].funct3 == funct3)
            {
                printf("%s x%d, x%d, %d\n", I[i].instruccion, rd, rs1, imm);
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < sizeIl; ++i)
        {
            if (Il[i].funct3 == funct3)
            {
                printf("%s x%d, x%d, %d\n", Il[i].instruccion, rd, rs1, imm);
                return;
            }
        }
    }

    printf("(Sin funcion definida en el sistema)\n");
    printf("%s x%d, x%d, %d\n", funct3, rd, rs1, imm);
}

void tipo_S(uint32_t codigo)
{
    printf("Forma S:\t");
    uint32_t rs1 = (codigo >> 15) & 0x1F;
    uint32_t rs2 = (codigo >> 20) & 0x1F;
    uint32_t funct3 = (codigo >> 12) & 0x7;

    int32_t imm = ((codigo >> 25) << 5) | ((codigo >> 7) & 0x1F);

    if (imm & 0x800)
    {
        imm |= 0xFFFFF000;
    }

    for (int i = 0; i < sizeS; i++)
    {
        if (S[i].funct3 == funct3)
        {
            printf("%s x%d, %d(x%d)\n", S[i].instruccion, rs2, imm, rs1);
            return;
        }
    }
    printf("(Sin funcion definida en el sistema)\n");
    printf("x%d x%d, %d(x%d)\n", funct3, rs2, imm, rs1);
}

void tipo_B(uint32_t codigo)
{
    printf("Forma B:\t");
    uint32_t rs1 = (codigo >> 15) & 0x1F;
    uint32_t rs2 = (codigo >> 20) & 0x1F;
    uint32_t funct3 = (codigo >> 12) & 0x7;

    int32_t imm =
        ((codigo >> 31) << 12) |
        (((codigo >> 25) & 0x3F) << 5) |
        (((codigo >> 8) & 0xF) << 1) |
        (((codigo >> 7) & 0x1) << 11);

    if (imm & 0x1000)
    {
        imm |= 0xFFFFE000;
    }

    for (int i = 0; i < sizeB; i++)
    {
        if (B[i].funct3 == funct3)
        {
            printf("%s x%d, x%d, %d\n", B[i].instruccion, rs1, rs2, imm);
            return;
        }
    }
    printf("(Sin funcion definida en el sistema)\n");
    printf("%s x%d, x%d, %d\n", funct3, rs1, rs2, imm);
}

void tipo_U(uint32_t codigo)
{
    printf("Forma U:\t");
    uint32_t rd = (codigo >> 7) & 0x1F;
    int32_t imm = codigo & 0xFFFFF000;

    uint32_t opcode = codigo & 0x7F;

    if (opcode == 0x37)
    {
        printf("lui x%d, %d\n", rd, imm);
    }
    else if (opcode == 0x17)
    {
        printf("auipc x%d, %d\n", rd, imm);
    }
}

void tipo_J(uint32_t codigo)
{
    printf("Forma J:\t");
    uint32_t rd = (codigo >> 7) & 0x1F;

    int32_t imm = 0;
    imm = (((codigo >> 31) << 20) | (((codigo >> 21) & 0x3FF) << 1) | (((codigo >> 20) & 0x1) << 11) | ((codigo >> 12) & 0xFF) << 12);

    if (imm & 0x100000)
    {
        imm |= 0xFFE00000;
    }

    printf("jal x%d, %d\n", rd, imm);
}

void decodificar(uint32_t codigo)
{
    printf("\n");
    uint32_t opcode = codigo & 0x7F;
    printf("opcode: x%d:\t", opcode);
    switch (opcode)
    {
    case 0x33:
        tipo_R(codigo);
        break;
    case 0x13:
    case 0x3:
        tipo_I(codigo, opcode);
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
