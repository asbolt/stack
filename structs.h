#ifndef STRUCTS_H_
#define STRUCTS_H_

// TODO structs.h is unclear name. It can be structs for literally anything. Would be better to move this into stack.h header

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// TODO read about typedefs and create a stack element type

struct Stack 
{
    const int startCanary = -154;
    int *data = NULL;
    int size = 0;
    int capasity = 0;
    int hash = 0;
    const int endCanary = -154;
};

enum Status // TODO status of what? you can use bool instead of this enum
{
    SUCCESS = 0,
    ERROR = 1
};

enum Errors // TODO StackErrors
{
    GOODSTACK,
    STACKNULL,
    STACKDATANULL,
    STACKBADSIZE,
    STACKBADCAPASITY,
    STACKBADELEMENT,
    STACKBADCANARY
};

#endif
