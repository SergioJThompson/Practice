/**
* @brief Assignment 1
* @name Sergio Thompson
*/

#ifndef LITTLECOMPUTER_H
#define LITTLECOMPUTER_H

class LittleComputer {
private:
    int memory[20];
    int accumulator;
    int programCounter;

public:
    /**
     * @brief Constructs a LittleComputer with all memory locations initialized to 0.
     */
    LittleComputer();

    /**
     * @brief Constructs a LittleComputer with the given instructions loaded into memory.
     *
     * Any unused memory locations are initialized to 0.
     *
     * @param instructions An array of integers representing the instructions to load into memory.
     * @param numberOfInstructions The number of instructions to load into memory.
     */
    LittleComputer(int instructions[], int numberOfInstructions);

    /**
     * @brief Gets the current value of the program counter.
     *
     * @return The current value of the program counter.
     */
    int getProgramCounter();

    /**
     * @brief Gets the current value of the accumulator.
     *
     * @return The current value of the accumulator.
     */
    int getAccumulator();

    /**
     * @brief Gets the value at the specified memory location.
     *
     * @param location The location in memory to retrieve the value from.
     * @return The value stored at the specified memory location.
     */
    int getMemoryAt(int location);

    /**
     * @brief Gets the instruction currently pointed to by the program counter.
     *
     * @return The instruction currently pointed to by the program counter.
     */
    int getCurrentInstruction();

    /**
     * @brief Executes the current instruction and updates the program counter.
     *
     * The LittleComputer executes the instruction currently pointed to by the program
     * counter and updates the program counter to point to the next instruction.
     */
    void step();

    /**
     * @brief Checks if the LittleComputer has reached the end of its program.
     *
     * The LittleComputer has reached the end of its program if the instruction
     * currently pointed to by the program counter is 0.
     *
     * @return True if the LittleComputer has reached the end of its program, false otherwise.
     */
    bool isHalted();

    /**
     * @brief Resets the LittleComputer to its initial state.
     *
     * This sets the accumulator and program counter to 0, and resets all memory
     * locations to 0.
     */
    void restart();
};

#endif // LITTLECOMPUTER_H
