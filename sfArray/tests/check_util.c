/*
 * File:   check_util.c
 * Author: jarkko
 *
 * Created on Sep 25, 2016, 2:52:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"


static int failures;

#define BEGIN(TESTNAME) printf("\tSTARTING TEST: %s\n", TESTNAME);
#define END(RET_VAL) \
    if(RET_VAL == EXIT_SUCCESS){\
        printf("\tTEST SUCCESSFUL\n\n");\
        return;\
    }else{\
        printf("\tTEST FAILED\n\n");\
        failures++;return;}


void radix_sort_test()
{
    BEGIN ("radix_sort_test")
    
    END(EXIT_FAILURE)
}

/* tries to check for memory leaks, I suppose.
 */
void str_arr_new_and_free_test()
{
    BEGIN ("str_arr_new_and_free_test")
    str_arr *sa = str_arr_new();
    
    
    str_arr_free(sa);
    END(EXIT_FAILURE)
}

void get_array_test()
{
    BEGIN ("get_array_test")
    str_arr *sa = str_arr_new();
    char *strings[] = {
        "",
        "a",
        "aa",
        "aaa",
        "aaaa",
        "aaaaa"
    };
    unsigned int i;
    // START TEST
    {
        str_arr *empty_vec = str_arr_new(); 
        char **empty_arr = get_array(empty_vec);
        if(empty_arr[0] != NULL){
            printf("\t\tfirst member of empty array not null");
            END (EXIT_FAILURE)
        }
        free(empty_arr);
        str_arr_free(empty_vec);
    }
    
    i = 0;
    while(i < 6){
        str_arr_add(sa, strings[i]);
        i++;
    }
    
    char **arr = get_array(sa);
    
    i = 0;
    while(i < 6){
        if(strcmp(strings[i], arr[i]) != 0){
            printf("\t\tstrings not equal: <%s> <%s>", strings[i], arr[i]);
            END (EXIT_FAILURE)
        }
        i++;
    }
    
    if(arr[6] != NULL){
        printf("\t\tfinal array member not null");
        END (EXIT_FAILURE)
    }
    
    
    // END TEST
    
    free(arr);
    str_arr_free(sa);
    END(EXIT_SUCCESS)
}

void str_arr_add_test()
{
    BEGIN ("str_arr_add_test")
    str_arr *sa = str_arr_new();
    if(str_arr_size(sa) != 0) goto failure;
    str_arr_add(sa, "");
    if(str_arr_size(sa) != 1) goto failure;
    str_arr_add(sa, "a");
    if(str_arr_size(sa) != 2) goto failure;
    str_arr_add(sa, "aa");
    if(str_arr_size(sa) != 3) goto failure;
    str_arr_add(sa, "a");
    if(str_arr_size(sa) != 4) goto failure;
    
    str_arr_free(sa);
    END (EXIT_SUCCESS)
    failure:printf("\t\tincorrect size");
    str_arr_free(sa);
    END (EXIT_FAILURE)
}

void str_arr_get_test()
{
    BEGIN ("str_arr_get_test")
    str_arr *sa = str_arr_new();
    
    str_arr_add(sa, "");
    str_arr_add(sa, "a");
    str_arr_add(sa, "aa");
    str_arr_add(sa, "a");
    
    if(strcmp(str_arr_get(sa,0), "") != 0)
        goto failure;
    if(strcmp(str_arr_get(sa,1), "a") != 0)
        goto failure;
    if(strcmp(str_arr_get(sa,2), "aa") != 0)
        goto failure;
    if(strcmp(str_arr_get(sa,3), "a") != 0)
        goto failure;
    
    str_arr_free(sa);
    END (EXIT_SUCCESS)
    failure:str_arr_free(sa);
    END(EXIT_FAILURE)
}

void str_arr_find_test()
{
    BEGIN ("str_arr_find_test")
    str_arr *sa = str_arr_new();
    
    
    str_arr_free(sa);
    END(EXIT_FAILURE)
}

void inc_len_test()
{
    BEGIN ("inc_len_test")
    str_arr *sa = str_arr_new();
    
    
    str_arr_free(sa);
    END(EXIT_FAILURE)
}

int main(int argc, char** argv) {
    printf("\nSTARTING TESTS: check_util\n");
    failures = 0;
    
    radix_sort_test();
    str_arr_new_and_free_test();
    get_array_test();
    str_arr_add_test();
    str_arr_get_test();
    str_arr_find_test();
    inc_len_test();
    
    printf("TESTS FINISHED: check_util, FAILURES: %d\n\n", failures);
    
    return (failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
