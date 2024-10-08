#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define EXTEND_NUMBER 2
#define CANARY_VALUE -154
#define SPACE_FOR_CANARIES 2

#define GIVE_VALUES_FOR_CANARIES(stack) do { \
    const stackElementType firstCanary = CANARY_VALUE;\
    stack->data[0] = firstCanary;\
\
    const stackElementType secondCanary = CANARY_VALUE;\
    stack->data[stack->capacity - 1] = secondCanary;\
  } while(0)

typedef int stackElementType;

enum StackErrors
{
    STACK_GOOD,
    STACK_DATA_NULL,
    STACK_BAD_SIZE,
    STACK_BAD_CAPACITY,
    STACK_BAD_ELEMENT,
    STACK_BAD_CANARY,
    STACK_CAPACITY_LESS_THEN_SIZE
};

struct Stack 
{
    stackElementType *data             = NULL;
    int size                           = 0;
    int capacity                       = 0;
    int hash                           = 0;
    stackElementType poisonValue       = 0;
    StackErrors stackError             = STACK_GOOD;
};

#endif
