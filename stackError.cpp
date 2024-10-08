#include "stackError.h"
#include "stack.h"

StackErrors stackCheckForError (Stack *stack)
{
    if (stack->data[0] != CANARY_VALUE || stack->data[stack->capacity - 1] != CANARY_VALUE) {
        return STACK_BAD_CANARY;

    } else if (stack->data == NULL)
    {
        return STACK_DATA_NULL;

    } else if (stack->size < 0)
    {
        return STACK_BAD_SIZE;

    } else if (stack->capacity < 0)
    {
        return STACK_BAD_CAPACITY;
    } else 
    if (stack->size > stack->capacity)
    {
        return STACK_CAPACITY_LESS_THEN_SIZE;
    }

    for (int i = 0; i < stack->size; i++)
    {
        if (stack->data[i+1] == stack->poisonValue)
        {
            return STACK_BAD_ELEMENT;
        }
    }

    return STACK_GOOD;
}

int stackPrintError (Stack *stack)
{
    switch (stack->stackError)
    {
    case STACK_DATA_NULL:
        printf ("Data = NULL");
        break;

    case STACK_BAD_SIZE:
        printf ("Size < 0");
        break;

    case STACK_BAD_CAPACITY:
        printf ("Capacity < 0");
        break;

    case STACK_BAD_ELEMENT:
        printf ("Element = poison value");
        break;

    case STACK_BAD_CANARY:
        printf ("Data corrupted");
        break;

    case STACK_CAPACITY_LESS_THEN_SIZE:
        printf ("Capacity < size");
        break;

    case STACK_GOOD:
        break;
    
    default:
        break;
    }

    return true;
}
