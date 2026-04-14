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

When debug tracing is enabled inside `runCPU()`, output can look like this:

```c
PC=0 OPCODE=1
PC=2 OPCODE=6
PC=6 OPCODE=1
PC=8 OPCODE=0
A: 9
B: 0
Z: 0
PC: 9
