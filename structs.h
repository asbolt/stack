#ifndef STRUCTS_H_
#define STRUCTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Stack 
{
    const int startCanary = -154;
    int *data = NULL;
    int size = 0;
    int capasity = 0;
    int hash = 0;
    const int endCanary = -154;
};

enum Status
{
    SUCCESS = 0,
    ERROR = 1
};

enum Errors
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
