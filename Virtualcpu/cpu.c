#include <stdio.h>
#include "cpu.h"

void initCPU(CPU *cpu) // ininate cpu
{
    int i;

    cpu->A = 0;
    cpu->B = 0;
    cpu->Z = 0;
    cpu->PC = 0;

    for(i = 0; i < 256; i++) // set memory = 0
    {
        cpu->memory[i] = 0;
    }
}

void runCPU(CPU *cpu)
{
    // Holds the current instruction byte
    uint8_t opcode;

    // Controls whether the CPU keeps running
    int running = 1;

    // Main execution loop
    while(running == 1)
    {
        // FETCH STEP:
        // Read instruction from memory at address PC
        opcode = cpu->memory[cpu->PC];

        // Move PC forward to the next byte
        cpu->PC++;
        
        // Debug print to verify opcode
        printf("PC=%u OPCODE=%u\n", cpu->PC - 1, opcode);

        // DECODE + EXECUTE STEP:

        // Opcode 1:
        // LOAD A with immediate value (next memory byte)
        if(opcode == 1)
        {
            cpu->A = cpu->memory[cpu->PC];
            cpu->PC++;   // move past the immediate value
        }

        // Opcode 2:
        // ADD immediate value (next memory byte) to register A
        else if(opcode == 2)
        {
            cpu->A = cpu->A + cpu->memory[cpu->PC];
            cpu->PC++;

            // Update zero flag depending on result
            if(cpu->A == 0)
            {
                cpu->Z = 1;   // result was zero
            }
            else
            {
                cpu->Z = 0;   // result was not zero
            }
        }

        // Opcode 3:
        // LOAD B with immediate value (next memory byte)
        else if(opcode == 3)
        {
            cpu->B = cpu->memory[cpu->PC];
            cpu->PC++;
        }

        // Opcode 4:
        // ADD register B to register A
        else if(opcode == 4)
        {
            cpu->A = cpu->A + cpu->B;

            // Update zero flag after addition
            if(cpu->A == 0)
            {
                cpu->Z = 1;
            }
            else
            {
                cpu->Z = 0;
            }
        }

        // Opcode 5:
        // COPY register A into register B
        // (MOV B, A instruction)
        else if(opcode == 5)
        {
            cpu->B = cpu->A;
        }
        // opcode 6:
        // JUMP to insstruction
        else if(opcode == 6){

        cpu->PC = cpu->memory[cpu->PC];
    }

        // opcode 6:
        else if (opcode == 7){
           if(cpu->Z = 1){
            cpu->PC = cpu->memory[cpu->PC];
           }
            else{
                cpu->PC++;
            }
        }
        // Opcode 0:
        // HALT instruction
        // Stops execution loop
        else if(opcode == 0)
        {
            running = 0;
        }

        // Any unknown instruction
        // Print error and stop CPU
        else
        {
            printf("Unknown opcode: %u\n", opcode);
            running = 0;
        }
    }

}
void printCPU(CPU *cpu)
{
    printf("A: %u\n", cpu->A);
    printf("B: %u\n", cpu->B);
    printf("Z: %u\n", cpu->Z);
    printf("PC: %u\n", cpu->PC);
}
