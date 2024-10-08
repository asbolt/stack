#include "error.h"
#include "hash.h" // TODO unused header

// TODO stackError.cpp

Errors error (Stack stack) // TODO at least printError()
{
    // TODO why does this function checks for errors and prints them at the same time.
    // This behaviour should be splitted into 2 separate functions

    if (&stack == NULL) // TODO this condition will never be true (think why and write me a message about it)
    {
        printf ("&stask = NULL\n");
        return STACKNULL; // TODO STACK_NULL

    } else if (squeak (&stack) != SUCCESS) {
        return STACKBADCANARY; // TODO STACK_BAD_CANARY

    } else if (stack.data == NULL)
    {
        printf ("&data = NULL\n");
        return STACKDATANULL; // TODO STACK_DATA_NULL

    } else if (stack.size < 0)
    {
        printf ("size < 0\n");
        return STACKBADSIZE; // TODO STACK_BAD_SIZE

    } else if (stack.capasity < 0)
    {
        printf ("capasity < 0\n");
        return STACKBADCAPASITY; // TODO STACK_BAD_CAPACITY (please, install a spellchecker)
    }

    for (int i = 0; i < stack.size; i++)
    {
        if (stack.data[i] == -666) // TODO magic number (-666)
        {
            printf ("data[%d] = -666", i);
            return STACKBADELEMENT; // TODO 
        }
    }

    // TODO what if size > capacity? Add more checks

    // TODO save error code in stack structure, so we can restore it anytime

    return GOODSTACK; // TODO STACK_GOOD
}

Status squeak (Stack *stack) // TODO why squeak?
{
    if (stack -> startCanary != -154 || stack -> endCanary != -154) // TODO what the f*ck is -154
    {
        printf ("Данные повреждены"); // TODO your errors are written in english up there, so "Data corrupted"
        return ERROR;
    }

    return SUCCESS;
}
