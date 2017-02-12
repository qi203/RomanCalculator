#include <stdio.h>
#include <string.h>

#include "calc.h"

typedef struct _MappingStructure {
    char romanLiterals[2];
    int  decimalValue;
} MappingStructure;

MappingStructure myStruct[3];

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
    return decimalValueOfArgument;

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

void defineMapIntegerToRomanString(void)
{
    strcpy(myStruct[0].romanLiterals, "V");
    myStruct[0].decimalValue = 5;
    strcpy(myStruct[1].romanLiterals, "IV");
    myStruct[1].decimalValue = 4;
    strcpy(myStruct[2].romanLiterals, "I");
    myStruct[2].decimalValue = 1;
    
//    if(arg)
}

int addRomanLiterals(char *arg1, char *arg2, char *resultRomanString)
{
    if(testWhetherArgumentsAreValid(arg1, arg2) == FAILURE) {
        return FAILURE;
    }
    defineMapIntegerToRomanString();
    int resultDecimalValue;
    int indexMyStructArray = 0;
    resultDecimalValue = convertRomanStringToDecimalValue(arg1) + convertRomanStringToDecimalValue(arg2);
    while(resultDecimalValue != 0) {
        while(resultDecimalValue >= myStruct[indexMyStructArray].decimalValue) {
            strcat(resultRomanString, myStruct[indexMyStructArray].romanLiterals);
            resultDecimalValue = resultDecimalValue - myStruct[indexMyStructArray].decimalValue;
        }
        indexMyStructArray++;
    }
    return SUCCESS;
}
