#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "ISA.h"

int main()
{
    char option = ' ';
    uint32_t codigo = 0;
    printf("Ingrese una opcion:\n[M] Manual \n[A] Archivo \n: ");
    scanf("%c", &option);
    switch (option)
    {
    case 'M':           // Entrada manual para datos hexadecimal
    {
        printf("Ingresa instrucciOn en hexadecimal (Ejemplo: 002081B3): ");
        scanf("%x", &codigo);
        printf("\n");
        decodificar(codigo);
    }
    break;

    case 'A':           // Entrada automatica mediante el archivo codigos.txt con datos en binario
    {
        FILE *archivo = fopen("codigos.txt", "r");
        char instruccion[40] = " "; 
        if (archivo == NULL)
        {
            printf("Error al abrir el archivo\n");
            return 1;
        }

        while (fgets(instruccion, sizeof(instruccion), archivo))
        {   
            codigo = (uint32_t)strtoul(instruccion,NULL, 2);
            decodificar(codigo);
        }
        fclose(archivo);
    }
    break;

    default:
        printf("Opcion invalida");
        break;
    }

    return 0;
}