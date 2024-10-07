#include "stack.h"
#include "hash.h"

// TODO forUser.cpp? I do not understand this name. At least name it stackUserInterface.h

Status push (Stack *stack, int element)
{
    // TODO asserts
    if (error (*stack) != GOODSTACK) // TODO GOOD_STACK and please, pass pointer (not value)
        return ERROR;

    if (element == -666) // TODO magic number
    {
        printf ("bad value\n");
        return ERROR;
    }

    if (stack -> size >= stack -> capasity)
    {
        extensionStack (stack); // TODO poor naming. Function name must be a verb in infinitive form (extendStack() for example)
    }

    stack -> data[stack -> size] = element;
    (stack -> size)++;

    if (error (*stack) != GOODSTACK)
    return ERROR; // TODO you forgot one tab before return

    return SUCCESS;
}

Status pop (Stack *stack)
{
    // TODO asserts
    if (error (*stack) != GOODSTACK) // TODO these two lines repeat many times in your code. You can wrap it into functional macro
    return ERROR; // TODO again, you forgot tab

    stack -> data[stack -> size] = -666; // TODO magic number
    (stack -> size)--;

    // TODO think about hysteresis
    if (stack -> size < (stack -> capasity)/2)
    {
        constrictionStack (stack);
    }

    if (error (*stack) != GOODSTACK)
    return ERROR; // TODO tab

    return SUCCESS;
}

Status ctor (Stack *stack, int size) // TODO what does this function constructs? It must be understandable from its name
{
    // TODO asserts
    stack -> data = (int*)calloc(size, sizeof(int)); // TODO check calloc result
    stack -> capasity = size;

    return SUCCESS;
}

Status dtor (Stack *stack) // TODO stackDtor()
{
    // TODO asserts
    if (error (*stack) != GOODSTACK)
    return ERROR; // TODO tab

    free (stack -> data);

    return SUCCESS;
}

// TODO pass stack by pointer
Status dump (Stack stack) // TODO this is very poor naming. Please, use representative names for functions (for example dumpStack)
{
    // TODO asserts
    if (error (stack) != GOODSTACK)
    return ERROR; // TODO tab

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
