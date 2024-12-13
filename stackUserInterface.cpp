#include "stackUserInterface.h"

StackErrors stackPush (Stack *stack, stackElementType element, int line, const char* function, const char* file)
{
    STACK_CHECK(stack, line, function, file);

    if (element == stack->poisonValue)
    {
        printf ("bad value\n");
        return STACK_BAD_ELEMENT;
    }

    (stack->size)++;

    if (stack->size >= stack->capacity - ONE_CANARY)
    {
        stackExtend (stack, line, function, file);
        GIVE_VALUES_FOR_CANARIES(stack);
    }

    stack->data[stack->size] = element;

    stack->hash = dataHash (stack->data, stack->size);

    STACK_CHECK(stack, line, function, file);

    return STACK_GOOD;
}

StackErrors stackPop (Stack *stack, int line, const char* function, const char* file)
{
    STACK_CHECK(stack, line, function, file);

    stack->data[stack->size] = stack->poisonValue;
    (stack->size)--;

    if (stack->size < (stack->capacity) / 4) 
    {
        stackReduce (stack, line, function, file);
        GIVE_VALUES_FOR_CANARIES(stack);
    }

    stack->hash = dataHash ((stack->data), stack->size);

    STACK_CHECK(stack, line, function, file);

    return STACK_GOOD;
}

Stack *stackCtor (stackElementType size)
{
    Stack *stack = (Stack *)calloc (1, sizeof(Stack *));
    if (stack == NULL)
        return NULL;

    stack->data = (stackElementType *) calloc(size + SPACE_FOR_CANARIES, sizeof(stackElementType));
    if (stack->data == NULL)
        return NULL;

    stack->capacity = size;

    stack->data[0] = CANARY_VALUE;
    stack->data[stack->capacity - ONE_CANARY] = CANARY_VALUE;

    stack->hash = dataHash ((stack->data), stack->size);
    stack->poisonValue = POISON_VALUE;
    stack->startCanary = CANARY_VALUE;
    stack->endCanary = CANARY_VALUE;

    return stack;
}

StackErrors stackDtor (Stack *stack, int line, const char* function, const char* file)
{
    STACK_CHECK(stack, line, function, file);

    free (stack);
    stack = NULL;

    return STACK_GOOD;
}

StackErrors stackDump (Stack *stack)
{
    if (stack->data == NULL)
        printf ("Address data: NULL");
    else 
    {
        printf ("Address data: %p\n", stack->data);
        printf ("Data: ");
        for (int i = 1; i <= stack->size; i++)
        {
            printf ("%d ", stack->data[i]);
        }
        printf ("\n");
    }

    printf ("Size: %d\n", stack->size);
    printf ("Capacity: %d\n", stack->capacity);
    printf ("Poison value: %d\n", stack->poisonValue);
    printf ("Hash: %d\n", stack->hash);
    printf ("First canary: %d\n", stack->data[0]);
    printf ("Second canary: %d\n", stack->data[stack->capacity - ONE_CANARY]);

    printf ("\n\n\n");

    return STACK_GOOD;
}
