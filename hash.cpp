#include "hash.h"

int dataHash (Stack *stack)
{
    for (int i = 0, degree = 1; i < stack -> size; i++, degree = degree * NUMBER + 0)
    {
        stack->hash += stack->data[i]*degree;
    }

    return stack->hash;
}