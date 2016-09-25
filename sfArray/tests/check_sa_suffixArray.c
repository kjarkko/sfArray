/*
 * File:   check_sa_suffixArray.c
 * Author: jarkko
 *
 * Created on Sep 25, 2016, 12:51:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "sa_suffixArray.h"

static int failures;

#define BEGIN(TESTNAME) printf("\tSTARTING TEST: %s\n", TESTNAME);
#define END(RET_VAL) \
    if(RET_VAL == EXIT_SUCCESS){\
        printf("\tTEST SUCCESSFUL\n\n");\
        return;\
    }else{\
        printf("\tTEST FAILED\n\n");\
        failures++;return;}

void new_and_free_test()
{
    BEGIN ("new_and_free_test")
    
    END (EXIT_FAILURE)
}

void longest_equ_prefix_len_test()
{
    BEGIN ("longest_equ_prefix_len_test")
    
    char *str1, *str2;
    unsigned int ans, ret;
    
    str1 = "";
    str2 = "";
    ans = 0;
    ret = longest_equ_prefix_len(str1, str2);
    if(ret != ans) goto failure;
    str1 = "a";
    str2 = "";
    ans = 0;
    ret = longest_equ_prefix_len(str1, str2);
    if(ret != ans) goto failure;
    str1 = "";
    str2 = "a";
    ans = 0;
    ret = longest_equ_prefix_len(str1, str2);
    if(ret != ans) goto failure;
    str1 = "banana";
    str2 = "baba";
    ans = 2;
    ret = longest_equ_prefix_len(str1, str2);
    if(ret != ans) goto failure;
    str1 = "aaa";
    str2 = "baaa";
    ans = 0;
    ret = longest_equ_prefix_len(str1, str2);
    if(ret != ans) goto failure;
    str1 = "aaaaa";
    str2 = "aaaaa";
    ans = 5;
    ret = longest_equ_prefix_len(str1, str2);
    if(ret != ans) goto failure;
    
    END (EXIT_SUCCESS)
    
    failure: printf(
        "\t\tstrings <%s>, <%s> expected <%d>, was <%d>\n",
        str1 , str2, ans, ret
    );
    
    END (EXIT_FAILURE)
}

void create_lcpA_test()
{
    BEGIN ("create_lcpA_test")
    
    char *strings[] = {
        "",
        "a",
        "aa",
        "aaa",
        "aaaa",
        "aaaaa"
    };
    int *lcpa = create_lcpA(&strings[0], 6);
    int ans[6] = {0, 0, 1, 2, 3, 4, 5};
    int i = 6;
    while(i > 0){
        i--;
        if(lcpa[i] != ans[i]){
            END (EXIT_FAILURE)
        }
    }
    
    END (EXIT_SUCCESS)
}

void locate_test()
{
    BEGIN ("locate_test")
    
    END (EXIT_FAILURE)
}



int main(int argc, char** argv) 
{
    printf("\nSTARTING TESTS: check_sa_suffixArray\n");
    failures = 0;
    
    new_and_free_test();
    longest_equ_prefix_len_test();
    create_lcpA_test();
    locate_test();
    
    printf("TESTS FINISHED: check_sa_suffixArray, FAILURES: %d\n\n", failures);
    
    return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
