#include "stack.h"

Status extensionStack (Stack *stack) // TODO extendStack()
{
    // TODO asserts
    if (error (*stack) != GOODSTACK) // TODO STACK_GOOD
    return ERROR; // TODO you forgot tab


    // TODO 2 - magic number
    // TODO it's not really good to write stack -> data with these whitespaces. stack->data would be much greater
    stack -> data = (int*)realloc(stack -> data, (stack -> capasity)*sizeof(int)*2); // TODO please, use more whitespaces in arythmetic expressions 
                                                                                     // for example stack->capacity_*_sizeof(int)_*_2 ('_' sign represents a whitespace)
    
    // TODO check realloc result
    
    // TODO 2 - magic number
    stack -> capasity = (stack -> capasity)*2; // TODO stack->capacity * 2 

    for (int i = stack -> size; i < stack -> capasity; i++)
    {
        stack -> data[i] = -666; // TODO magic numberc
    }

    return SUCCESS;
}

Status constrictionStack (Stack *stack) // TODO reduceStack()
{
    // TODO asserts

    if (error (*stack) != GOODSTACK)
    return ERROR;

    // TODO check realloc result
    stack -> data = (int*)realloc(stack -> data, (stack -> capasity)*sizeof(int)/2); // TODO more whitespaces
    stack -> capasity = (stack -> capasity)/2; // TODO more whitespaces

    return SUCCESS;
}
