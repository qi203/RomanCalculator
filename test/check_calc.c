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
    char *result;
    char *arg1 = "I", *arg2 = "I";
    result = addRomanLiterals(arg1, arg2);
    ck_assert_str_eq(result, "II");
    printf("Test 4 - Addition Sample Input 1 Returned Test Success\n");
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
    


    suite_add_tcase(testSuite, validateInputArgumentsTestCase);
    suite_add_tcase(testSuite, additionTestCase);

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
