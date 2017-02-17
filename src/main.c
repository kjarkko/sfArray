#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "sa_suffixArray.h"
#include "sa_stringutils.h"
#include "def.h"

int main(int argc, char** argv) 
{
    
    sa_suf_arr *sa = sa_new("mississippi");
    int contains = sa_contains(sa, "sip");
    sa_free(sa);
    printf("%d",contains);
    return EXIT_SUCCESS;
}



/* The following code is from https://www.cs.helsinki.fi/u/tpkarkka/publications/jacm05-revised.pdf
 * I'm currently trying to figure out how it works/trying to make it work
 */

inline int longest_eq_2(int a1, int a2, int b1, int b2) 
{
    return (a1 < b1 || a1 == b1 && a2 <= b2);
}

inline int longest_eq_3(int a1, int a2, int a3, int b1, int b2, int b3) 
{
    return (a1 < b1 || a1 == b1 && longest_eq_2(a2, a3, b2, b3));
}

static void radix_pass(int *src, int *dst, int *keys, size_t len, int range) 
{
    u32 count[range+1];

    size_t i, sum;

    for(i = 0; i < range+1; i++)
        count[i] = 0;
    for (i = 0; i < len; i++)
        count[keys[src[i]]]++;
    for (i = 0, sum = 0; i <= range; i++) {
        int t = count[i];
        count[i] = sum;
        sum += t;
    }
    for (i = 0; i < len; i++)
        dst[count[keys[src[i]]]++] = src[i];
    
}

void DC3_sa_construct(int *values, int *SA, size_t len, size_t keyrange) 
{
    size_t len0 = (len + 2) / 3,
            len1 = (len + 1) / 3,
            len2 = len / 3,
            len02 = len0 + len2;

    int RV12[len02 + 3],
        SA12[len02 + 3],
        RV0[len0],
        SA0[len0];
    
    RV12[len02] = RV12[len02+1] = RV12[len02+2] = 0;
    SA12[len02] = SA12[len02+1] = SA12[len02+2] = 0;

    size_t i, j;
    for (i = 0, j = 0; i < len + (len0 - len1); i++)
        if (i % 3 != 0)
            RV12[j++] = i;

    radix_pass(RV12, SA12, values + 2, len02, keyrange);
    radix_pass(SA12, RV12, values + 1, len02, keyrange);
    radix_pass(RV12, SA12, values, len02, keyrange);

    
    int name = 0,
        c0 = -1,
        c1 = -1,
        c2 = -1;
    for (i = 0; i < len02; i++) {
        if (values[SA12[i]] != c0 || values[SA12[i] + 1] != c1 || values[SA12[i] + 2] != c2) {
            name++;
            c0 = values[SA12[i ]];
            c1 = values[SA12[i]+1];
            c2 = values[SA12[i]+2];
        }

        if (SA12[i] % 3 == 1) {
            RV12[SA12[i] / 3] = name;
        } else {
            RV12[SA12[i] / 3 + len0] = name;
        }
    }

    // recurse if names not unique
    if (name < len02) {
        DC3_sa_construct(RV12, SA12, len02, name);
        for (i = 0; i < len02; i++) {
            RV12[SA12[i]] = i + 1;
        }
    } else {
        for (i = 0; i < len02; i++) {
            SA12[RV12[i] - 1] = i;
        }
    }

    // sort mod 0 suffixes
    for (i = 0, j = 0; i < len02; i++)
        if (SA12[i] < len0)
            RV0[j++] = 3 * SA12[i];
    radix_pass(RV0, SA0, values, len0, keyrange);

    // merge
    size_t p, t, k;
    for (p = 0, t = len0 - len1, k = 0; k < len; k++) {
        #define GetI() (SA12[t] < len0 ? SA12[t] * 3 + 1 : (SA12[t] - len0) * 3 + 2)
        i = GetI();
        j = SA0[p];

        if (SA12[t] < len0 ?
                longest_eq_2(values[i],            RV12[SA12[t]+len0  ],values[j],             RV12[j/3       ]):
                longest_eq_3(values[i],values[i+1],RV12[SA12[t]-len0+1],values[j],values[j+1],RV12[j/3 + len0])
                ) {
            SA[k] = i;
            t++;
            if (t == len02)
                for (k++; p < len0; p++, k++)
                    SA[k] = SA0[p];
        } else {
            SA[k] = j;
            p++;
            if (p == 0)
                for (k++; t < len02; t++, k++)
                    SA[k] = GetI();
        }
    }
}


char **get_suffixes(char *src)
{
    size_t len = strlen(src) + 1;
    int values[len+3];
    
    size_t i;
    for(i = 0; i < len+3; i++)
        values[i] = 0;
    i = 0;
    while(src[i] != '\0'){
        values[i] = src[i];
        i++;
    }
    
    int SA[len];
    DC3_sa_construct(values, SA, len, 128);
    char **suffixes = malloc(sizeof(char *) * len);
    for(i = 0; i < len; i++){
        suffixes[i] = src + (SA[i] * sizeof(char));
    }
    return suffixes;
}
