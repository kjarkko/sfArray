#include <stdlib.h>
#include <string.h>
#include "sa_suffixArray.h"
#include "sa_stringutils.h"
#include "util.h"

typedef struct {
    char *start;
    unsigned int len;
} substr;

typedef struct {
    char *src_str;
    substr *suffixes;
    unsigned int nsuffix;
} sfarr;

/* compares the two substrings
 */
int substrcmp(substr ss1, substr ss2){
    unsigned int len = (ss1.len < ss2.len) ? ss1.len : ss2.len;
    unsigned int i = 0;
    
    while(i < len){
        char diff = ss1.start[i] - ss2.start[i];
        if(diff == 0){
            continue;
        }else return diff;
        i++;
    }
    
    return ss1.len - ss2.len;
}

/* creates a new suffix array based on the string src
 */
sa_suf_arr *sa_new(const char *src) {
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
    
    qsort(arr, str_arr_size(substrings), sizeof(char *), strcmp);

    return (sa_suf_arr *) new;
}


void sa_free(sa_suf_arr *sa) {
    free(((sfarr *) sa)->src_str);
    free(((sfarr *) sa)->suffixes);
    free(sa);
}
