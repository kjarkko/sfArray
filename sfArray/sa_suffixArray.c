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


/* length of the longest prefix that occurs in both strings
 * 
 * O(n)
 */
inline unsigned int longest_equ_prefix_len(const char *str1, const char *str2)
{
    register unsigned int i = 0;
    while(  str1[i] != '\0' && 
            str2[i] != '\0' && 
            str1[i] == str2[i])
        i++;
    
    return i;
}

/* creates the longest common prefix array
 * 
 * O(n*l)
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

/* creates a new suffix array based on the string src
 * 
 * O(l^2), where l is the length of the str
 */
sa_suf_arr *sa_new(const char *src) 
{
    sfarr *new = malloc(sizeof (sfarr));

    new->src_str = strdup(src);
    
    // create a vector containing all the suffixes
    str_arr *substrings = str_arr_new();
    unsigned int len = strlen(src);
    unsigned int i = 0;
    while(i < len){
        str_arr_add(substrings, &new->src_str[len]);
        i++;
    }
    
    // sort the suffixes
    char **arr = get_array(substrings);
    radix_sort(arr, str_arr_size(substrings));
    
    new->lcp = create_lcpA(arr, len);
    new->suffixes = arr;
    new->nsuffix = len+1; // off by one? 

    str_arr_free(substrings);
    return (sa_suf_arr *) new;
}



/* locate the string in the given sorted array using binary search
 * return: index of the string, -1 if not found
 * 
 * O(l log n), l = length of find, n = nsuffix 
 */
int locate(char **suffixes, size_t nsuffix, const char *find)
{
    unsigned int len = strlen(find);
    int min = 0;
    int max = nsuffix;
    int mid;
    
    while(min <= max){
        mid = (min + max) >> 1;
        int cmp = strncmp(suffixes[mid], find, len);
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

/* free the structure.
 * 
 * O(n)
 */
void sa_free(sa_suf_arr *sa) 
{
    free(((sfarr *) sa)->lcp);
    free(((sfarr *) sa)->suffixes);
    free(((sfarr *) sa)->src_str);
    free(sa);
}
