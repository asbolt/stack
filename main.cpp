#include "elements.h"

int main ()
{
    Stack stack = {};
    ctor (&stack, 10);
    dump (stack);

    push (&stack, 1);
    push (&stack, 2);
    push (&stack, 3);

    dump (stack);

    return 0;
}