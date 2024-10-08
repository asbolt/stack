#include "stackInsideFunctoins.h"

int stackExtend (Stack *stack)
{
    STACK_CHECK(stack);

    stack->data = (stackElementType*)realloc (stack->data, (stack->capacity) * sizeof(stackElementType) * EXTEND_NUMBER + SPACE_FOR_CANARIES);
    if (stack->data == NULL)
        return false;
    
    stack->capacity = (stack->capacity) * EXTEND_NUMBER;

    for (int i = stack->size; i < stack->capacity - 1; i++)
    {
        stack->data[i+1] = stack->poisonValue;
    }

    return true;
}

int stackReduce (Stack *stack)
{
    STACK_CHECK(stack);

    stack->data = (stackElementType*)realloc (stack->data, (stack->capacity) * sizeof(stackElementType) / 4 + SPACE_FOR_CANARIES);
    if (stack->data == NULL)
        return false;

    stack->capacity = (stack->capacity) / 2;

    return true;
}

int dataHash (stackElementType *array, int arraySize)
{
    long long int hash = 0;

    for (int numberElement = 0, degree = 1; numberElement < arraySize - 1; numberElement++, degree = degree * NUMBER_FOR_CALCULATION_HASH)
    {
        hash += (int)array[numberElement + 1]*degree;
    }

    return hash;
}
