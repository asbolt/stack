#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#include "stackInsideFunctoins.h"
#include "stack.h"

int stackPush (Stack *stack, stackElementType element);
int stackPop (Stack *stack);
int stackCtor (Stack *stack, stackElementType size, stackElementType poisonValue);
int stackDtor (Stack *stack);
int stackDump (Stack *stack);

#endif
