#include "forUser.h"

int main ()
{
    Stack stack = {};

    ctor (&stack, 10);

    push (&stack, 10);
    push (&stack, 20);
    push (&stack, 30);

    pop (&stack);

    dump (stack);

    dtor (&stack);

    return 0;
}