#include <stdlib.h>
#include <stdio.h>
#include <check.h>

#include "calc.h"

/* Define Tests to Validate Arguments */

START_TEST(passingInvalidArgumentReturnsTestFailure)
{
    int testStatus;
    char *arg1 = '\0', *arg2 = '\0';
    testStatus = testWhetherArgumentsAreValid(arg1, arg2);
    ck_assert_int_eq(testStatus, FAILURE);
}
END_TEST

Suite *romanCalculatorSuite(void)
{
    Suite *testSuite;
    testSuite = suite_create("Calculator");
    
    TCase *validateInputArgumentsTestCase;
    validateInputArgumentsTestCase = tcase_create("Validate Input Arguments");
    
    /* Validation of Input Arguments - Test Cases */
    tcase_add_test(validateInputArgumentsTestCase, passingInvalidArgumentReturnsTestFailure);
    
    suite_add_tcase(testSuite, validateInputArgumentsTestCase);

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
