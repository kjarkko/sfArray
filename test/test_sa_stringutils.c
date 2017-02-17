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
    
    if( sa_contains(s1, str1)){
        f++;
        printf("\t\t%d %s\n", 1,str1);
    }
    if(!sa_contains(s1, str2)){
        f++;
        printf("\t\t%d %s\n", 1,str2);
    }
    if(!sa_contains(s1, str3)){
        f++;
        printf("\t\t%d %s\n", 1,str3);
    }
    if(!sa_contains(s2, str1)){
        f++;
        printf("\t\t%d %s\n", 2,str1);
    }
    if( sa_contains(s2, str2)){
        f++;
        printf("\t\t%d %s\n", 2,str2);
    }
    if(!sa_contains(s2, str3)){
        f++;
        printf("\t\t%d %s\n", 2,str3);
    }
    if( sa_contains(s3, str1)){
        f++;
        printf("\t\t%d %s\n", 3,str1);
    }
    if( sa_contains(s3, str2)){
        f++;
        printf("\t\t%d %s\n", 3,str2);
    }
    if(!sa_contains(s3, str3)){
        f++;
        printf("\t\t%d %s\n", 3,str3);
    }
    
    printf("\t\t%d\n", f);
    
    sa_free(s1);
    sa_free(s2);
    sa_free(s3);
    
    if(f)
        goto fail;
    
    
    END(EXIT_SUCCESS)
    
    fail:END(EXIT_FAILURE);
}

void sa_locate_test()
{
    BEGIN ("sa_locate_test")
    
    printf("\t\ttest not implemented yet.\n");
    
    END (EXIT_FAILURE)
}

void char_dist_test()
{
    BEGIN ("char_dist_test")
    
    char *str = "abcdefgh";
    size_t dist;
    
    dist = char_dist(&str[0], &str[1]);
    if(dist != 1)
        goto fail;
    dist = char_dist(&str[0], &str[0]);
    if(dist != 0)
        goto fail;
    dist = char_dist(&str[1], &str[0]);
    if(dist != 1)
        goto fail;
    dist = char_dist(&str[2], &str[5]);
    if(dist != 3)
        goto fail;
    
    END (EXIT_SUCCESS)
    
    fail:END (EXIT_FAILURE)
}

void sa_longest_recurring_test()
{
    BEGIN ("sa_longest_recurring_test")
            
    sa_suf_arr *s1 = sa_new("aabbbaabbb");
    char *str1 = sa_longest_recurring(s1);
    int cmp = strcmp(str1, "aabbb");
    free(str1);
    sa_free(s1);
    if(cmp != 0)
        goto fail;
    
    sa_suf_arr *s2 = sa_new("aba");
    char *str2 = sa_longest_recurring(s2);
    cmp = strcmp(str2, "a");
    free(str2);
    sa_free(s2);
    if(cmp != 0)
        goto fail;
    
    sa_suf_arr *s3 = sa_new("aaaa");
    char *str3 = sa_longest_recurring(s3);
    cmp = strcmp(str3, "aa");
    sa_free(s3);
    free(str3);
    if(cmp != 0)
        goto fail;
    
    sa_suf_arr *s4 = sa_new("abc");
    char *str4 = sa_longest_recurring(s4);
    cmp = strcmp(str4, "");
    sa_free(s4);
    free(str4);
    if(cmp != 0)
        goto fail;
    
    END (EXIT_SUCCESS)
    fail:END (EXIT_FAILURE)
}

void sa_count_occurrences_test()
{
    BEGIN ("sa_count_occurrences_test")
    
    sa_suf_arr *s = sa_new("abcdab"); 
    if(sa_count_occurrences(s, "a") != 2)
        goto fail;
    if(sa_count_occurrences(s, "ab") != 2)
        goto fail;
    if(sa_count_occurrences(s, "c") != 1)
        goto fail;
    if(sa_count_occurrences(s, "d") != 0)
        goto fail;
    sa_free(s);
    
    END (EXIT_SUCCESS)
    
    fail:sa_free(s);
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
    char_dist_test();
    sa_longest_recurring_test();
    sa_count_occurrences_test();
    printf("TESTS FINISHED: check_sa_stringutils, FAILURES: %d\n\n", failures);
    
    return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
