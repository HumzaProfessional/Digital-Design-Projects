#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct
{
    uint8_t A; // register A
    uint8_t B; // Register B
    uint8_t Z; 
    uint16_t PC; // Progrma counter
    uint8_t memory[256]; // memory
} CPU;

void initCPU(CPU *cpu);
void runCPU(CPU *cpu);
void printCPU(CPU *cpu);

#endif
