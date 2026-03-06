# Traductor y Decodificador de Instrucciones

## Descripción del Proyecto

Este proyecto implementa un **traductor y decodificador de instrucciones en código máquina**.  
El programa recibe instrucciones en **formato hexadecimal**, las convierte a **binario** y posteriormente **identifica el tipo de instrucción** para extraer sus campos correspondientes al formato segun instrucciones **RISC-V**.

El sistema es capaz de interpretar diferentes **formatos de instrucción**, reconstruir sus campos y mostrar la información de manera legible para el usuario.

---

## Objetivo

Desarrollar un programa que:

- Lea instrucciones en **código máquina hexadecimal**.
- Convierta las instrucciones a **representación binaria**.
- Identifique el **tipo de instrucción** a partir del opcode.
- Decodifique los campos de la instrucción.
- Calcule el **valor inmediato (imm)** cuando sea necesario.
- Permita leer instrucciones **desde terminal o desde un archivo**.

---

## Tipos de Instrucción Implementados

El programa soporta los siguientes formatos de instrucción:

- **Tipo R**
- **Tipo I**
- **Tipo S**
- **Tipo B**
- **Tipo U**
- **Tipo J**

Cada tipo tiene una estructura diferente de campos dentro de la instrucción de 32 bits.

---

## Estructura General del Programa

El programa está organizado en diferentes módulos:

```bash
Decodificador
│
├── main.c
├── instrucciones.c
├── instrucciones.h
├── codigos.txt
└── README.md
```


### Archivos principales

**main.c**

Contiene el flujo principal del programa:

- Lectura de instrucciones
- Menú de interacción
- Llamada a funciones de decodificación

**instrucciones.c**

Implementa las estructuras necesarias para:

- Diciconario de instrucciones segun su tipo


**instrucciones.h**

Define:

- Estructuras
- Constantes utilizadas en el decodificador

**ISA.c**

Implementa las funciones de decodificacion para:

- Identificar el tipo de instrucción
- Interpretar las instrucciones

**ISA.h**
Define:

- Prototipo de la funcion de decompilacion

**codigos.txt**

Archivo opcional que permite cargar múltiples instrucciones automáticamente en formato binario.

---

## Flujo de Funcionamiento

1. El programa inicia mostrando un **menú de opciones**.
2. El usuario selecciona si desea:
   - Ingresar instrucciones manualmente.
   - Leer instrucciones desde un archivo.
3. La instrucción hexadecimal se **convierte a binario**.
4. Se extrae el **opcode**.
5. Con el opcode se determina el **tipo de instrucción**.
6. Dependiendo del tipo, se **extraen los campos correspondientes**.
7. Si la instrucción utiliza un **inmediato (imm)**, este se reconstruye usando los bits correspondientes.
8. Finalmente se muestra la **decodificación completa de la instrucción**.

---

## Requisitos

Para ejecutar el proyecto se requiere:

- Compilador de C (GCC recomendado)
- Sistema operativo Linux, macOS o Windows con terminal

---

## Manejo del Proyecto

Para clonar el repositorio y compilarlo usaremos:

```bash
https://github.com/RigoLlamas/Decodificador.git
cd Decodificador
gcc main.c instrucciones.c ISA.c -o riscv
./decodificador
```
Uso con Archivo de Instrucciones

Si se desea ejecutar el programa con múltiples instrucciones, se pueden colocar en el archivo:
```bash
codigos.txt
```
Cada línea debe contener una instrucción en formato binario.
<br>Ejemplo:
<br>00001111110000010000101000010111
<br>00000000010010100000101000010011
<br>00001111110000010000101010010111

El programa leerá cada instrucción y mostrará su decodificación.

---

## Autores

Proyecto desarrollado por RigoLlamas y documentacion RISC-V

---

## Nota

Codigo abierto (open source)
