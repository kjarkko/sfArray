#include <stdlib.h>
#include <string.h>
#include "sa_suffixArray.h"
#include "sa_stringutils.h"

typedef struct {
    char *start;
    unsigned int len;
} substr;

typedef struct {
    char *str;
    substr *suffixes;
    unsigned int nsuffix;
} sfarr;

int suffixcmp(substr ss1, substr ss2){
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

sa_suf_arr *sa_construct(const char *src) {
    sfarr *new = malloc(sizeof (sfarr));

    new->str = strdup(src);

    return (sa_suf_arr *) new;
}


void sa_free(sa_suf_arr *sa) {
    free(((sfarr *) sa)->str);
    free(((sfarr *) sa)->suffixes);
    free(sa);
}
