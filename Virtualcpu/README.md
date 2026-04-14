# Virtual CPU Simulator in C

A simple "virtual CPU" written in C that demonstrates how a processor works:

- stores registers
- executes instructions
- updates flags
- reads memory
- performs jumps
- halts execution



---

## How Program Output Shows Execution

The CPU follows this cycle:

`FETCH -> DECODE -> EXECUTE -> REPEAT`


### Debug and verification:

 The follow code inside `runCPU()`: and `runCPU()`

 ``` c
void printCPU(CPU *cpu)
{
    printf("A: %u\n", cpu->A);
    printf("B: %u\n", cpu->B);
    printf("Z: %u\n", cpu->Z);
     printf("C: %u\n", cpu->C);
    printf("PC: %u\n", cpu->PC);
}
```

``` c
 printf("PC=%u OPCODE=%u\n", cpu->PC - 1, opcode);
```
Can produce an output such as this:

```c
PC=0 OPCODE=1
PC=2 OPCODE=6
PC=6 OPCODE=1
PC=8 OPCODE=0
A: 9
B: 0
Z: 0
PC: 9
