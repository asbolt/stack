#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#include "stack.h"

Status push (Stack *stack, int element);
Status pop (Stack *stack);
Status ctor(Stack *stack, int size);
Status dtor (Stack *stack);
Status dump (Stack stack);

#endif
