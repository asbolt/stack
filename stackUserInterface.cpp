#include "stackInsideFunctoins.h"
#include "stackUserInterface.h"

int stackPush (Stack *stack, stackElementType element)
{
    STACK_CHECK(stack);

    if (element == stack->poisonValue)
    {
        printf ("bad value\n");
        return false;
    }

    if (stack->size >= stack->capacity - SPACE_FOR_CANARIES)
    {
        stackExtend (stack);
        GIVE_VALUES_FOR_CANARIES(stack);
    }

    stack->data[stack->size + 1] = element;
    (stack->size)++;

    stack->hash = dataHash ((stack->data), stack->size);

    STACK_CHECK(stack);

    return true;
}

int stackPop (Stack *stack)
{
    STACK_CHECK(stack);

    stack->data[stack->size] = stack->poisonValue;
    (stack->size)--;

    if (stack->size < (stack->capacity)/4)
    {
        stackReduce (stack);
        GIVE_VALUES_FOR_CANARIES(stack);
    }

    stack->hash = dataHash ((stack->data), stack->size);

    STACK_CHECK(stack);

    return true;
}

int stackCtor (Stack *stack, stackElementType size, stackElementType poisonValue)
{
    stack->data = (stackElementType*)calloc(size + SPACE_FOR_CANARIES, sizeof(stackElementType));
    if (stack->data == NULL)
        return false;

    stack->capacity = size;
    stack->poisonValue = poisonValue;

    GIVE_VALUES_FOR_CANARIES(stack);

    stack->hash = dataHash ((stack->data), stack->size);

    return true;
}

int stackDtor (Stack *stack)
{
    STACK_CHECK(stack);

    free (stack->data);
    stack->data = NULL;

    return true;
}

int stackDump (Stack *stack)
{
    STACK_CHECK(stack);

    printf ("Address data: %p\n", stack->data);

    printf ("Data: ");
    for (int i = 0; i < stack->size; i++)
    {
        printf ("%d ", stack->data[i + 1]);
    }
    printf ("\n");

    printf ("Size: %d\n", stack->size);
    printf ("Capacity: %d\n", stack->capacity);
    printf ("Poison value: %d\n", stack->poisonValue);
    printf ("Hash: %d\n", stack->hash);

    printf ("\n\n\n");

    return true;
}
