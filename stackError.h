#ifndef ERROR_H_
#define ERROR_H_

#include "stack.h"

#define STACK_CHECK(stack) do { \
    if (stackCheckForError (stack) != STACK_GOOD)\
        {\
            stackPrintError (stack);\
            assert (0);\
        }\
  } while(0)

StackErrors stackCheckForError (Stack *stack);
int stackPrintError (Stack *stack);

#endif