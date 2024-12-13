#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#include "stackInsideFunctions.h"
#include "stack.h"

StackErrors stackPush (Stack *stack, stackElementType element, int line, const char* function, const char* file);
StackErrors stackPop (Stack *stack, int line, const char* function, const char* file);
Stack *stackCtor (stackElementType size);
StackErrors stackDtor (Stack *stack, int line, const char* function, const char* file);
StackErrors stackDump (Stack *stack);

#endif
