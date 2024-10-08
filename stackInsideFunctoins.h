#ifndef STACK_H_
#define STACK_H_

#include "stackError.h"
#include "stack.h"

#define NUMBER_FOR_CALCULATION_HASH 2

int stackExtend (Stack *stack);
int stackReduce (Stack *stack);
int dataHash (int *array, int arraySize);

#endif