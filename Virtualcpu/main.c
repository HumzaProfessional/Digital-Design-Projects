#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

int main()
{
    CPU cpu;

    initCPU(&cpu);

cpu.memory[0] = 1;   // LOAD A
cpu.memory[1] = 6;   // A = 6

cpu.memory[2] = 6;   // JMP
cpu.memory[3] = 6;   // jump to address 6

cpu.memory[4] = 1;   // (should be skipped)
cpu.memory[5] = 99;  // (should be skipped)

cpu.memory[6] = 1;   // LOAD A
cpu.memory[7] = 9;   // A = 9

cpu.memory[8] = 0;   // HALT

    runCPU(&cpu);
    printCPU(&cpu);

    return 0;
}
