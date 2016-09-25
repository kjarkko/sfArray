/*
 * File:   check_sa_stringutils.c
 * Author: jarkko
 *
 * Created on Sep 25, 2016, 2:57:57 PM
 */

#include <stdio.h>
#include <stdlib.h>

static int failures;

#define BEGIN(TESTNAME) printf("\tSTARTING TEST: %s\n", TESTNAME);
#define END(RET_VAL) \
    if(RET_VAL == EXIT_SUCCESS){\
        printf("\tTEST SUCCESSFUL\n\n");\
        return;\
    }else{\
        printf("\tTEST FAILED\n\n");\
        failures++;return;}

void sa_strlen_test()
{
    BEGIN ("sa_strlen_test")
    
    END(EXIT_FAILURE)
}

void sa_strcmp_test()
{
    BEGIN("sa_strcmp_test")
    
    END (EXIT_FAILURE)
}

void sa_contains_test()
{
    BEGIN ("sa_contains_test")
    
    END(EXIT_FAILURE)
}

void sa_locate_test()
{
    BEGIN ("sa_locate_test")
    
    END (EXIT_FAILURE)
}

void sa_longest_common_test()
{
    BEGIN ("sa_longest_common_test")
    
    END (EXIT_FAILURE)
}

void sa_longest_repeated_test()
{
    BEGIN ("sa_longest_repeated_test")
    
    END(EXIT_FAILURE)
}

void sa_longest_palindrome_test()
{
    BEGIN ("sa_longest_palindrome_test")
    
    END (EXIT_FAILURE)
}


int main(int argc, char** argv) 
{
    printf("\nSTARTING TESTS: check_sa_stringutils\n");
    failures = 0;
    
    sa_strlen_test();
    sa_strcmp_test();
    sa_contains_test();
    sa_locate_test();
    sa_longest_common_test();
    sa_longest_repeated_test();
    sa_longest_palindrome_test();
    
    printf("TESTS FINISHED: check_sa_stringutils, FAILURES: %d\n\n", failures);
    
    return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
