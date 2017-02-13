#include <stdlib.h>
#include <stdio.h>
#include <check.h>

#include "calc.h"

/* Define Tests to Validate Arguments */

START_TEST(passingNullArgumentReturnsTestFailure)
{
    int testStatus;
    char *arg1 = '\0', *arg2 = '\0';
    testStatus = testWhetherArgumentsAreValid(arg1, arg2);
    ck_assert_int_eq(testStatus, FAILURE);
    printf("Test 1 - Null Arguments Returned Test Failure\n");
}
END_TEST

START_TEST(passingInvalidArgumentReturnsTestFailure)
{
    int testStatus;
    char *arg1 = "A", *arg2 = "L";
    testStatus = testWhetherArgumentsAreValid(arg1, arg2);
    ck_assert_int_eq(testStatus, FAILURE);
    printf("Test 2 - Invalid Arguments Returned Test Failure\n");
}
END_TEST

START_TEST(passingValidArgumentReturnsTestSuccess)
{
    int testStatus;
    char *arg1 = "MDCXL", *arg2 = "MV";
    testStatus = testWhetherArgumentsAreValid(arg1, arg2);
    ck_assert_int_eq(testStatus, SUCCESS);
    printf("Test 3 - Valid Arguments Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_I_And_I_Returns_II)
{
    char *arg1 = "I", *arg2 = "I";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"II");
    printf("Test 4 - Addition Sample Input 1 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_I_And_II_Returns_III)
{
    char *arg1 = "I", *arg2 = "II";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"III");
    printf("Test 5 - Addition Sample Input 2 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_II_And_I_Returns_III)
{
    char *arg1 = "II", *arg2 = "I";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"III");
    printf("Test 6 - Addition Sample Input 3 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_II_And_II_Returns_IV)
{
    char *arg1 = "II", *arg2 = "II";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"IV");
    printf("Test 7 - Addition Sample Input 4 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_II_And_III_Returns_V)
{
    char *arg1 = "II", *arg2 = "III";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"V");
    printf("Test 8 - Addition Sample Input 5 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_I_And_IV_Returns_V)
{
    char *arg1 = "I", *arg2 = "IV";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"V");
    printf("Test 9 - Addition Sample Input 6 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_V_And_I_Returns_VI)
{
    char *arg1 = "V", *arg2 = "I";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"VI");
    printf("Test 10 - Addition Sample Input 7 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_V_And_III_Returns_VIII)
{
    char *arg1 = "V", *arg2 = "III";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"VIII");
    printf("Test 11 - Addition Sample Input 8 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_V_And_IIII_Returns_IX)
{
    char *arg1 = "V", *arg2 = "IIII";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"IX");
    printf("Test 12 - Addition Sample Input 9 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_V_And_V_Returns_X)
{
    char *arg1 = "V", *arg2 = "V";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"X");
    printf("Test 13 - Addition Sample Input 10 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_X_And_XXX_Returns_XL)
{
    char *arg1 = "X", *arg2 = "XXX";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"XL");
    printf("Test 14 - Addition Sample Input 11 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_XX_And_XXX_Returns_L)
{
    char *arg1 = "XX", *arg2 = "XXX";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"L");
    printf("Test 15 - Addition Sample Input 12 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_C_And_C_Returns_CC)
{
    char *arg1 = "C", *arg2 = "C";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"CC");
    printf("Test 16 - Addition Sample Input 13 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_D_And_CD_Returns_CM)
{
    char *arg1 = "D", *arg2 = "CD";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"CM");
    printf("Test 17 - Addition Sample Input 14 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_D_And_D_Returns_M)
{
    char *arg1 = "D", *arg2 = "D";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"M");
    printf("Test 18 - Addition Sample Input 15 Returned Test Success\n");
}
END_TEST

START_TEST(subtractionOfEqualRomanStringsReturnsFailure)
{
    char *arg1 = "D", *arg2 = "D";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_int_eq(testStatus,FAILURE);
    printf("Test 21 - Subtraction Result of Zero Is Invalid Number in Roman - Returned Test Failure\n");
}
END_TEST

START_TEST(subtractionResultEqualToNegativeValuesReturnsFailure)
{
    char *arg1 = "D", *arg2 = "M";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_int_eq(testStatus,FAILURE);
    printf("Test 22 - Subtraction Result Equal To Negative Is Invalid Number in Roman - Returned Test Failure\n");
}
END_TEST

START_TEST(subtractionOf_I_From_I_ReturnsFailure)
{
    char *arg1 = "I", *arg2 = "I";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_int_eq(testStatus,FAILURE);
    printf("Test 23 - Subtraction Sample Input 1 Returned Test Failure\n");
}
END_TEST

START_TEST(subtractionOf_I_From_X_Returns_IX)
{
    char *arg1 = "X", *arg2 = "I";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"IX");
    printf("Test 24 - Subtraction Sample Input 2 Returned Test Success\n");
}
END_TEST

START_TEST(subtractionOf_V_From_C_Returns_XCV)
{
    char *arg1 = "C", *arg2 = "V";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"XCV");
    printf("Test 25 - Subtraction Sample Input 3 Returned Test Success\n");
}
END_TEST

START_TEST(subtractionOf_C_From_M_Returns_CM)
{
    char *arg1 = "M", *arg2 = "C";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"CM");
    printf("Test 26 - Subtraction Sample Input 4 Returned Test Success\n");
}
END_TEST

START_TEST(subtractionOf_XII_From_LXVIII_Returns_CM)
{
    char *arg1 = "LXVIII", *arg2 = "XII";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"LVI");
    printf("Test 27 - Subtraction Sample Input 5 Returned Test Success\n");
}
END_TEST

START_TEST(subtractionOf_XLIII_From_CXXIX_Returns_LXXXVI)
{
    char *arg1 = "CXXIX", *arg2 = "XLIII";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"LXXXVI");
    printf("Test 28 - Subtraction Sample Input 6 Returned Test Success\n");
}
END_TEST

START_TEST(subtractionOf_CD_From_CM_Returns_D)
{
    char *arg1 = "CM", *arg2 = "CD";
    char resultRomanString[50] = {'\0'};
    int testStatus = subtractRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"D");
    printf("Test 29 - Subtraction Sample Input 7 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_CXXII_And_LXI_Returns_CLXXXIII)
{
    char *arg1 = "CXXII", *arg2 = "LXI";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"CLXXXIII");
    printf("Test 19 - Addition Sample Input 16 Returned Test Success\n");
}
END_TEST

START_TEST(additionOf_CCCLXVIIII_And_DCCCXXXXV_Returns_MCCXIV)
{
    char *arg1 = "CCCLXVIIII", *arg2 = "DCCCXXXXV";
    char resultRomanString[50] = {'\0'};
    int testStatus = addRomanLiterals(arg1, arg2, resultRomanString);
    ck_assert_str_eq(resultRomanString,"MCCXIV");
    printf("Test 20 - Addition Sample Input 17 Returned Test Success\n");
}
END_TEST

Suite *romanCalculatorSuite(void)
{
    Suite *testSuite;
    testSuite = suite_create("Calculator");
    
    TCase *validateInputArgumentsTestCase, *additionTestCase, *subtractionTestCase;
    validateInputArgumentsTestCase = tcase_create("Validate Input Arguments");
    additionTestCase = tcase_create("Addition Of Roman Literals");
    subtractionTestCase = tcase_create("Subtraction Of Roman Literals");
    
    /* Validation of Input Arguments - Test Cases */
    tcase_add_test(validateInputArgumentsTestCase, passingNullArgumentReturnsTestFailure);
    tcase_add_test(validateInputArgumentsTestCase, passingInvalidArgumentReturnsTestFailure);
    tcase_add_test(validateInputArgumentsTestCase, passingValidArgumentReturnsTestSuccess);
    
    /* Addition of Roman Literals - Test Cases */
    tcase_add_test(additionTestCase, additionOf_I_And_I_Returns_II);
    tcase_add_test(additionTestCase, additionOf_I_And_II_Returns_III);
    tcase_add_test(additionTestCase, additionOf_II_And_I_Returns_III);
    tcase_add_test(additionTestCase, additionOf_II_And_II_Returns_IV);
    tcase_add_test(additionTestCase, additionOf_II_And_III_Returns_V);
    tcase_add_test(additionTestCase, additionOf_I_And_IV_Returns_V);
    tcase_add_test(additionTestCase, additionOf_V_And_I_Returns_VI);
    tcase_add_test(additionTestCase, additionOf_V_And_III_Returns_VIII);
    tcase_add_test(additionTestCase, additionOf_V_And_IIII_Returns_IX);
    tcase_add_test(additionTestCase, additionOf_V_And_V_Returns_X);
    tcase_add_test(additionTestCase, additionOf_X_And_XXX_Returns_XL);
    tcase_add_test(additionTestCase, additionOf_XX_And_XXX_Returns_L);
    tcase_add_test(additionTestCase, additionOf_C_And_C_Returns_CC);
    tcase_add_test(additionTestCase, additionOf_D_And_CD_Returns_CM);
    tcase_add_test(additionTestCase, additionOf_D_And_D_Returns_M);
    tcase_add_test(additionTestCase, additionOf_CXXII_And_LXI_Returns_CLXXXIII);
    tcase_add_test(additionTestCase, additionOf_CCCLXVIIII_And_DCCCXXXXV_Returns_MCCXIV);
    
    /* Subtraction of Roman Literals - Test Cases */
    tcase_add_test(subtractionTestCase, subtractionOfEqualRomanStringsReturnsFailure);
    tcase_add_test(subtractionTestCase, subtractionResultEqualToNegativeValuesReturnsFailure);
    tcase_add_test(subtractionTestCase, subtractionOf_I_From_I_ReturnsFailure);
    tcase_add_test(subtractionTestCase, subtractionOf_I_From_X_Returns_IX);
    tcase_add_test(subtractionTestCase, subtractionOf_V_From_C_Returns_XCV);
    tcase_add_test(subtractionTestCase, subtractionOf_C_From_M_Returns_CM);
    tcase_add_test(subtractionTestCase, subtractionOf_XII_From_LXVIII_Returns_CM);
    tcase_add_test(subtractionTestCase, subtractionOf_XLIII_From_CXXIX_Returns_LXXXVI);
    tcase_add_test(subtractionTestCase, subtractionOf_CD_From_CM_Returns_D);


    suite_add_tcase(testSuite, validateInputArgumentsTestCase);
    suite_add_tcase(testSuite, additionTestCase);
    suite_add_tcase(testSuite, subtractionTestCase);

    return testSuite;
}

int main (int argc, char *argv[])
{
    int number_failed;
    Suite *testSuite;
    SRunner *suiteRunner;
    
    testSuite = romanCalculatorSuite();
    suiteRunner = srunner_create(testSuite);
    
    printf("--------------------\n");
    printf("***STARTING TESTS***\n");

    srunner_run_all(suiteRunner, CK_NORMAL);
    number_failed = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);


    printf("***ENDING TESTS***\n");
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
