#include "stackUserInterface.h"

int main ()
{
    Stack stack = {};

    stackCtor (&stack, 10, -666);

    stackPush (&stack, 10);
    stackPush (&stack, 20);
    stackPush (&stack, 30);
    
    stackPop (&stack);

    stackDump (&stack);

    stackDtor (&stack);

    return 0;
}