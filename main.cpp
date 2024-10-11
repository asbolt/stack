#include "stackUserInterface.h"

int main ()
{
    Stack stack = {};

    stackCtor (&stack, 10);

    stackPush (&stack, 10, VALUES_FOR_ERROR);
    stackPush (&stack, 20, VALUES_FOR_ERROR);
    stackPush (&stack, 30, VALUES_FOR_ERROR);
    
    stackPop (&stack, VALUES_FOR_ERROR);

    stackDump (&stack);

    stackDtor (&stack, VALUES_FOR_ERROR);
}

// TODO fix hash
// TODO second hash
// TODO check how work errorPrint
// TODO do mak for functions 
// TODO make and log
//TODO if size < 0 error in ctor