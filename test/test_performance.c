/*
 * File:   newsimpletest.c
 * Author: jarkko
 *
 * Created on Nov 5, 2016, 5:26:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sa_suffixArray.h"
/*
#include "sa_stringutils.h"
#include "sa_suffixArray.h"
*/

#define addtime(TIMES, SP) 

float sa_new_repeat_a(size_t len)
{
    sa_suf_arr *sa;
    clock_t start, stop;
    float elapsed_time;
    
    char str[len+1];
    memset(str, 'a', len);
    str[len] = '\0';
    
    start = clock();
    sa = sa_new(str);
    elapsed_time = ((float)(clock() - start) / CLOCKS_PER_SEC);
    sa_free(sa);
    return elapsed_time;
}

// 26 different values
float sa_new_random(size_t len)
{
    sa_suf_arr *sa; 
    clock_t start, stop;
    float elapsed_time;
    char str[len+1];
    size_t i;
    for(i = 0; i < len; i++){
        str[i] = (rand() % 26) + 97;
    }
    str[len] = '\0';
    start = clock();
    sa = sa_new(str);
    elapsed_time = ((float)(clock() - start) / CLOCKS_PER_SEC);
    sa_free(sa);
    return elapsed_time;
}

void sa_new_perf_tests()
{
    puts("sa_new('a'^n)\n");
    size_t count;
    for(count = 1000; count <= 10000; count += 1000){
        printf("\t%d - %f seconds\n", count, sa_new_repeat_a(count));
    }
    
    const size_t RANDOM_STRING_LENGTH = 1000;
    float time = 0;
    for(count = 0; count < 10; count++){
        time += sa_new_random(RANDOM_STRING_LENGTH);
    }
    printf("\t10 randomized strings, length %d, time: %f\n", RANDOM_STRING_LENGTH, time / 10);
}

void sa_locate_perf_tests()
{
    // gen random, pick random substring 0..len
    // a^n, substr a^(n-m)
}

const int RUN_PERFORMANCE_TESTS = 1;
int main(int argc, char** argv) 
{
    if(!RUN_PERFORMANCE_TESTS){
        puts("performance tests set to not execute.");
        return(EXIT_FAILURE);
    }
        
    printf("STARTING PERFORMANCE TESTS\n");
    puts("\tsa_new\n");
    sa_new_perf_tests();
    puts("\tsa_locate\n");
    printf("FINISHED PERFORMANCE TESTS");
    return (EXIT_SUCCESS);
}
