#ifndef STACK_H_
#define STACK_H_

#include "error.h"

Status ctor(Stack *stack, int size);
Status dtor (Stack *stack);
Status extensionStack (Stack *stack);
Status constrictionStack (Stack *stack);

#endif