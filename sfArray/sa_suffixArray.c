#include <stdlib.h>
#include <string.h>
#include "sa_suffixArray.h"
#include "util.h"
#include "def.h"


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
    lcpa[0] = 0;
    
    unsigned int i = 1;
    while(i < len){
        lcpa[i] = longest_equ_prefix_len(suffixes[i], suffixes[i-1]);
        i++;
    }
    
    return lcpa;
}

int cmpstr(void const *a, void const *b) { 
    return strcmp(* (char * const *)a, * (char * const *)b); // what the fuck
}

/* creates a new suffix array based on the string src
 * 
 */
sa_suf_arr *sa_new(const char *src) 
{
    sfarr *new = malloc(sizeof (sfarr));
    char *string = strdup(src);
    
    u32 len = strlen(string) + 1; //null terminator included
    u32 i;
    char **suffixes = malloc(sizeof(char *) * len);
    for(i = 0; i < len; i++){
        suffixes[i] = &string[i];
    }
    
    radix_sort(suffixes, len);
    //qsort(suffixes, len, sizeof(char *), cmpstr);
    new->nsuffix = len;
    new->src_str = string;
    new->lcp = create_lcpA(suffixes, len);
    new->suffixes = suffixes;
    

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
    int max = nsuffix-1;
    int mid;
    
    while(min <= max){
        mid = (min + max) >> 1;
        int cmp = strncmp(suffixes[mid], find, len);
        if(cmp == 0)
            return mid;
        else if(cmp < 0){
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
