#include "stack.h"

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