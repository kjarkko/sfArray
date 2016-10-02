#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "sa_suffixArray.h"
#include "sa_stringutils.h"

typedef struct {
    char *src_str;
    int *lcp;
    char **suffixes;
    unsigned int nsuffix;
} sfarr;

/* returns the length of the given string
 */
unsigned int sa_strlen(const char *s)
{
    unsigned int i = 0;
    while(s[i] != '\0') i++;
    return i;
}


int sa_strcmp(const char *a, const char *b)
{
    unsigned int i = 0;
    while(a[i] != '\0' && b[i] != '\0' && a[i] == b[i])
        i++;
    
    return a[i] - b[i];
}

/* determines whether the given string is a substring within the array
 */
int sa_contains(sa_suf_arr *sa, const char *str)
{
    return sa_locate(sa, str) != -1;
}

/* returns the index of the given string, -1 if not found
 */
int sa_locate(sa_suf_arr *sa, const char *str)
{
    sfarr *s = (sfarr *)sa;
    unsigned int len = strlen(str);
    int min = 0;
    int max = s->nsuffix;
    int mid;
    
    while(min <= max){
        mid = (min + max) >> 1;
        int cmp = strncmp(s->suffixes[mid], str, len);
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

/* the longest substring that occurs more than once
 * returns a duplicated string.
 * if multiple substrings with similar length are present, the first one found
 * is returned 
 * runs in linear time
 */
char *sa_longest_recurring(sa_suf_arr *sa)
{
    sfarr *s = (sfarr *)sa;
    unsigned int longest = 0;
    unsigned int location = 0;
    
    unsigned int i = 0;
    while(i < s->nsuffix){
        if(s->lcp[i] > longest){
            longest = s->lcp[i];
            location = i;
        }
        i++;
    }
    
    return strndup(s->suffixes[location], longest);
}

unsigned int sa_count_occurrances(sa_suf_arr *sa, const char *str)
{
    sfarr *s = (sfarr *)sa;
    int i = sa_locate(sa, str);
    if(i == -1)
        return 0;
    
    unsigned int len = sa_lcpa_len(sa);
    unsigned int count = 1;
    { // left
        unsigned int lcpi = i;
        while(lcpi-- > 0){
            if(s->lcp[lcpi] >= len)
                count++;
            else break;
        }
    };
    
    { // right
        unsigned int lcpi = i;
        while(lcpi < s->nsuffix){ // off by one
            if(s->lcp[lcpi] >= len)
                count++;
            else break;
            lcpi++;
        };
    };
    
    return count;
}

/* longest common substring
 */
char *sa_longest_common(sa_suf_arr *sa1, sa_suf_arr *sa2)
{
    
    return NULL;
}

/* longest substring that occurs twice or more
 */
char *sa_longest_repeated(sa_suf_arr *sa1, sa_suf_arr *sa2)
{
    return NULL;
}

/* pointer to the longest palindrome within the string
 */
char *sa_longest_palindrome(sa_suf_arr *sa1)
{
    return NULL;
}