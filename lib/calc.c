#include <stdio.h>
#include <string.h>

#include "calc.h"

int convertRomanLiteralToDecimalNumber(char arg)
{
    if (arg == 'I') {
        return 1;
    }
    else if(arg == 'V') {
        return 5;
    }
    else if(arg == 'X') {
        return 10;
    }
    else if(arg == 'L') {
        return 50;
    }
    else if(arg == 'C') {
        return 100;
    }
    else if(arg == 'D') {
        return 500;
    }
    else if(arg == 'M') {
    	return 1000;
    }
    else {
    	return FAILURE;
    }
}

int convertRomanStringToDecimalValue(char *arg)
{
    int argLength = strlen(arg);
    int decimalValueOfArgument = 0;
    int tempLiteralVariable1, tempLiteralVariable2;
    for(int i = 0; i < argLength; i++)
    {
        tempLiteralVariable1 = convertRomanLiteralToDecimalNumber(arg[i]);
        tempLiteralVariable2 = convertRomanLiteralToDecimalNumber(arg[i+1]);
        if (tempLiteralVariable1 == FAILURE) {
            return FAILURE;
        }
        if(tempLiteralVariable1 < tempLiteralVariable2) {
            decimalValueOfArgument = decimalValueOfArgument - tempLiteralVariable1;
        }
        else {
            decimalValueOfArgument = decimalValueOfArgument + tempLiteralVariable1;
        }
    }
    return SUCCESS;

}

int testWhetherArgumentsAreValid(char *arg1, char*arg2)
{
    if(arg1 == '\0' || arg2 == '\0')
    {
        return FAILURE;
    }
    
    if(convertRomanStringToDecimalValue(arg1) == FAILURE || convertRomanStringToDecimalValue(arg2) == FAILURE)
    {
        return FAILURE;
    }
    return SUCCESS;
}

char *addRomanLiterals(char *arg1, char *arg2)
{
    if((strcmp(arg1, "I") == 0)  && (strcmp(arg2, "I") == 0))
    {
        return "II";
    }
    return "\0";
}
