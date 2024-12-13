#include "stackInsideFunctions.h"

StackErrors stackExtend (Stack *stack, int line, const char* function, const char* file)
{
    STACK_CHECK(stack, line, function, file);

    stack->data = (stackElementType*)realloc (stack->data, (stack->capacity) * sizeof(stackElementType) * EXTEND_NUMBER + SPACE_FOR_CANARIES);
    if (stack->data == NULL)
        return STACK_DATA_NULL;
    
    stack->capacity = (stack->capacity) * EXTEND_NUMBER;

    for (int i = stack->size; i < stack->capacity - ONE_CANARY; i++)
    {
        stack->data[i+1] = stack->poisonValue;
    }

    return STACK_GOOD;
}

StackErrors stackReduce (Stack *stack, int line, const char* function, const char* file)
{
    STACK_CHECK(stack, line, function, file);

    stack->data = (stackElementType*)realloc (stack->data, (stack->capacity) * sizeof(stackElementType) / REDUCE_NUMBER + SPACE_FOR_CANARIES);
    if (stack->data == NULL)
        return STACK_DATA_NULL;

    stack->capacity = (stack->capacity) / REDUCE_NUMBER;

    return STACK_GOOD;
}

int dataHash (stackElementType *array, int arraySize)
{
    int hash = 0;

    for (int numberElement = 1; numberElement <= arraySize; numberElement++)
    {
        hash += array[numberElement];
    }

    return hash;
}
