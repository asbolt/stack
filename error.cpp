#include "error.h"
#include "hash.h"

Errors error (Stack stack)
{
    if (&stack == NULL)
    {
        printf ("&stask = NULL\n");
        return STACKNULL;

    } else if (squeak (&stack) != SUCCESS) {
        return STACKBADCANARY;

    } else if (stack.data == NULL)
    {
        printf ("&data = NULL\n");
        return STACKDATANULL;

    } else if (stack.size < 0)
    {
        printf ("size < 0\n");
        return STACKBADSIZE;

    } else if (stack.capasity < 0)
    {
        printf ("capasity < 0\n");
        return STACKBADCAPASITY;
    }

    for (int i = 0; i < stack.size; i++)
    {
        if (stack.data[i] == -666)
        {
            printf ("data[%d] = -666", i);
            return STACKBADELEMENT;
        }
    }

    return GOODSTACK;
}

Status squeak (Stack *stack)
{
    if (stack -> startCanary != -154 || stack -> endCanary != -154)
    {
        printf ("Данные повреждены");
        return ERROR;
    }

    return SUCCESS;
}
