#include "stack.h"
#include "hash.h"

Status push (Stack *stack, int element)
{
    if (error (*stack) != GOODSTACK)
        return ERROR;

    if (element == -666)
    {
        printf ("bad value\n");
        return ERROR;
    }

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

Status dump (Stack stack)
{
    if (error (stack) != GOODSTACK)
    return ERROR;

    printf ("Adress data: %p\n", stack.data);

    printf ("Data: ");
    for (int i = 0; i < stack.size; i++)
    {
        printf ("%d ", stack.data[i]);
    }
    printf ("\n");

    printf ("Size: %d\n", stack.size);
    printf ("Capasity: %d\n", stack.capasity);
    printf ("Hash: %d", dataHash (&stack));

    printf ("\n\n\n");

    return SUCCESS;
}