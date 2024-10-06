#include "stack.h"

Status push (Stack *stack, int element)
{
    if (error (*stack) != GOODSTACK)
    return ERROR;

    if (stack -> size >= stack -> capasity)
    {
        extensionStack (stack);
    }

    stack -> data[stack -> size] = element;
    (stack -> size)++;

    if (error (*stack) != GOODSTACK)
    return ERROR;

    return SUCCESS;
}

Status pop (Stack *stack)
{
    if (error (*stack) != GOODSTACK)
    return ERROR;

    stack -> data[stack -> size] = -666;
    (stack -> size)--;

    if (stack -> size < (stack -> capasity)/2)
    {
        constrictionStack (stack);
    }

    if (error (*stack) != GOODSTACK)
    return ERROR;

    return SUCCESS;
}