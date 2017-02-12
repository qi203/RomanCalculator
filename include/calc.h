#ifndef CALC_H
#define CALC_H

#define FAILURE -1
#define SUCCESS 0

extern int testWhetherArgumentsAreValid(char *arg1, char *arg2);
extern int addRomanLiterals(char *arg1, char *arg2, char *resultRomanString);
extern int subtractRomanLiterals(char *arg1, char *arg2, char *resultRomanString);

#endif /*CALC_H*/
