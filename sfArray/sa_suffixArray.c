#include <stdlib.h>
#include <string.h>
#include "sa_suffixArray.h"
#include "util.h"


typedef struct {
    char *src_str;
    int *lcp;
    char **suffixes;
    unsigned int nsuffix;
} sfarr;


/* creates a new suffix array based on the string src
 */
sa_suf_arr *sa_new(const char *src) 
{
    sfarr *new = malloc(sizeof (sfarr));

    new->src_str = strdup(src);
    str_arr *substrings = str_arr_new();
    unsigned int len = strlen(src);
    unsigned int i = 0;
    while(i < len){
        str_arr_add(substrings, &new->src_str[len]);
        i++;
    }
    
    char **arr = get_array(substrings);
    
    qsort(arr, str_arr_size(substrings), sizeof(char *), (__compar_fn_t)strcmp);
    
    new->suffixes = arr;
    new->nsuffix = len; // off by one? 

    return (sa_suf_arr *) new;
}

/* length of the longest prefix that occurs in both strings
 */
unsigned int longest_equ_prefix_len(const char *str1, const char *str2)
{
    unsigned int i = 0;
    while(  str1[i] != '\0' && 
            str2[i] != '\0' && 
            str1[i] == str2[i])
        i++;
    
    return i;
}

/* creates the longest common prefix array
 */
int *create_lcpA(char **suffixes, unsigned int len)
{
    int *lcpa = malloc(len * sizeof(int));
    lcpa[0] = 0; // ????
    
    unsigned int i = 1;
    while(i < len){
        lcpa[i] = longest_equ_prefix_len(suffixes[i], suffixes[i-1]);
        i++;
    }
    
    return lcpa;
}

/*
 */
int locate(char **suffixes, const char *str)
{
    unsigned int len = strlen(str);
    int min = 0;
    int max = 0;
    int mid;
    
    while(min <= max){
        mid = (min + max) >> 1;
        int cmp = strncmp(suffixes[mid], str, len);
        if(cmp == 0)
            return mid;
        else if(cmp > 0){
            min = mid + 1;
        }else{
            max = mid - 1;
        }
    }
    
    return -1;
}


void sa_free(sa_suf_arr *sa) 
{
    unsigned int i = 0;
    while(((sfarr *) sa)->suffixes[i] != NULL){
        free(((sfarr *) sa)->suffixes[i]);
        i++;
    }
    free(((sfarr *) sa)->suffixes);
    free(((sfarr *) sa)->src_str);
    free(sa);
}
