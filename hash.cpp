#include "hash.h"

// TODO data hash should be able to compute hash of anything. So, it would be better to pass char * and array size
int dataHash (Stack *stack)
{
    // TODO asserts
    for (int i = 0, degree = 1; i < stack -> size; i++, degree = degree * NUMBER + 0) // TODO i - bad naming
    {
        stack->hash += stack->data[i]*degree;
    }

    return stack->hash;
}
