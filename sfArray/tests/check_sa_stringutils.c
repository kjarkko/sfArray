/*
 * File:   check_sa_stringutils.c
 * Author: jarkko
 *
 * Created on Sep 25, 2016, 2:57:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sa_suffixArray.h"
#include "sa_stringutils.h"

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
            
    char *str;
    int cmp;
    
    str = "";
    cmp = strlen(str) == sa_strlen(str);
    if(!cmp)
        END(EXIT_FAILURE)
        
    str = "a";
    cmp = strlen(str) == sa_strlen(str);
    if(!cmp)
        END(EXIT_FAILURE)
        
    str = "asdasdasd";
    cmp = strlen(str) == sa_strlen(str);
    if(!cmp)
        END(EXIT_FAILURE)
    
    END(EXIT_SUCCESS)
}

void sa_strcmp_test()
{
    BEGIN("sa_strcmp_test")
    
    char *s1, *s2;
    int ret;
    
    s1 = "";
    s2 = "";
    ret = sa_strcmp(s1,s2) == strcmp(s1,s2);
    if(!ret)
        END(EXIT_FAILURE)
        
    s1 = "a";
    s2 = "";
    ret = sa_strcmp(s1,s2) == strcmp(s1,s2);
    if(!ret)
        END(EXIT_FAILURE)
        
    s1 = "a";
    s2 = "a";
    ret = sa_strcmp(s1,s2) == strcmp(s1,s2);
    if(!ret)
        END(EXIT_FAILURE)
    
    END (EXIT_SUCCESS)
}

void sa_contains_test()
{
    BEGIN ("sa_contains_test")
    
    sa_suf_arr *s1 = sa_new("abba");
    sa_suf_arr *s2 = sa_new("baab");
    sa_suf_arr *s3 = sa_new("abab");
    
    char *str1 = "aa";
    char *str2 = "bb";
    char *str3 = "ab";
    
    int f = 0;
    
    if( sa_contains(s1, str1))
        f++;
    if(!sa_contains(s1, str2))
        f++;
    if(!sa_contains(s1, str3))
        f++;
    if(!sa_contains(s2, str1))
        f++;
    if( sa_contains(s2, str2))
        f++;
    if(!sa_contains(s2, str3))
        f++;
    if( sa_contains(s3, str1))
        f++;
    if( sa_contains(s3, str2))
        f++;
    if(!sa_contains(s3, str3))
        f++;
    
    printf("\t\t%d\n", f);
    
    if(f)
        goto fail;
    
    sa_free(s1);
    sa_free(s2);
    sa_free(s3);
    
    END(EXIT_SUCCESS)
    
    fail:END(EXIT_FAILURE);
}

void sa_locate_test()
{
    BEGIN ("sa_locate_test")
    
    printf("\t\ttest not implemented yet.\n");
    
    END (EXIT_FAILURE)
}

void sa_longest_recurring_test()
{
    BEGIN ("sa_longest_recurring_test")
    
    printf("\t\ttest not implemented yet.\n");
    
    END (EXIT_FAILURE)
}

void sa_count_occurrences_test()
{
    BEGIN ("sa_longest_recurring_test")
    
    printf("\t\ttest not implemented yet.\n");
    
    END (EXIT_FAILURE)
}

void sa_longest_common_test()
{
    BEGIN ("sa_longest_common_test")
    
    printf("\t\ttest not implemented yet.\n");
    
    END (EXIT_FAILURE)
}

void sa_longest_repeated_test()
{
    BEGIN ("sa_longest_repeated_test")
    
    printf("\t\ttest not implemented yet.\n");
    
    END(EXIT_FAILURE)
}

void sa_longest_palindrome_test()
{
    BEGIN ("sa_longest_palindrome_test")
    
    printf("\t\ttest not implemented yet.\n");
    
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
