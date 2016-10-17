#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "sa_suffixArray.h"
#include "sa_stringutils.h"
#include "def.h"

int main(int argc, char** argv){
    char str[10000];
    memset(str, 'a', 10000);
    str[5000] = 'b';
    
    sa_suf_arr *sa = sa_new(str);
    char test[5000];
    memset(test, 'a', 5000);
    printf("%d\n", sa_contains(sa, test));
    sa_free(sa);
}