/**
* @brief Assignment 1
* @name Sergio Thompson
*/

#include "LittleComputer.h"
#include <algorithm>

LittleComputer::LittleComputer() {
    for (int i = 0; i < 20; i++) {
        memory[i] = 0;
    }

    accumulator = 0;
    programCounter = 0;
}

LittleComputer::LittleComputer(int instructions[], int numberOfInstructions) {
    for (int i = 0; i < numberOfInstructions; i++) {
        memory[i] = instructions[i];
    }
    for (int i = numberOfInstructions; i < 20; i++) {
        memory[i] = 0;
    }

    accumulator = 0;
    programCounter = 0;
}

int LittleComputer::getProgramCounter() {
    return programCounter;
}

int LittleComputer::getAccumulator() {
    return accumulator;
}

int LittleComputer::getMemoryAt(int location) {
    return memory[location];
}

int LittleComputer::getCurrentInstruction() {
    return memory[programCounter];
}

void LittleComputer::step() {
    int instruction = getCurrentInstruction();
    int firstDigit = instruction / 100;
    int XX = instruction % 100;

    if (firstDigit == 1) {
        accumulator += getMemoryAt(XX);
        programCounter++;
    }
    else if (firstDigit == 2) {
        accumulator -= getMemoryAt(XX);
        programCounter++;
    }
    else if (firstDigit == 3) {
        memory[XX] = accumulator;
        programCounter++;
    }
    else if (firstDigit == 5) {
        accumulator = memory[XX];
        programCounter++;
    }
    else if (firstDigit == 6) {
        programCounter = XX;
    }
    else if (firstDigit == 7) {
        if (accumulator == 0) {
            programCounter = XX;
        }
        else {
            programCounter++;
        }
    }
}

bool LittleComputer::isHalted() {
    return getCurrentInstruction() == 0;
}

void LittleComputer::restart() {
    accumulator = 0;
    programCounter = 0;
}
