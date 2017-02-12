#include <stdio.h>
#include <string.h>

#include "calc.h"

int testWhetherArgumentsAreValid(char *arg1, char*arg2)
{
    if(arg1 == '\0' || arg2 == '\0')
    {
        return FAILURE;
    }
}

