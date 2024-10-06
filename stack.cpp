#include "stack.h"

Status ctor (Stack *stack, int size)
{
    stack -> data = (int*)calloc(size, sizeof(int));
    stack -> capasity = size;

    return SUCCESS;
}

Status dtor (Stack *stack)
{
    if (error (*stack) != GOODSTACK)
    return ERROR;

    free (stack -> data);

    return SUCCESS;
}

Status extensionStack (Stack *stack)
{
    if (error (*stack) != GOODSTACK)
    return ERROR;

    stack -> data = (int*)realloc(stack -> data, (stack -> capasity)*sizeof(int)*2);
    stack -> capasity = (stack -> capasity)*2;

    for (int i = stack -> size; i < stack -> capasity; i++)
    {
        stack -> data[i] = -666;
    }

    return SUCCESS;
}

Status constrictionStack (Stack *stack)
{
    if (error (*stack) != GOODSTACK)
    return ERROR;

    stack -> data = (int*)realloc(stack -> data, (stack -> capasity)*sizeof(int)/2);
    stack -> capasity = (stack -> capasity)/2;

    return SUCCESS;
}