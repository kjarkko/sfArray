#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "sa_suffixArray.h"
#include "sa_stringutils.h"
#include "def.h"

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

int contains_str(const char *full, const char *sub){
    size_t i = 0;
    while(1){
        char f = full[i];
        char s = sub[i];
        
        if(s == '\0')
            return 0;
        
        if(f == '\0')
            return -s;
        
        if(f != s)
            return f - s;
        
        i++;
    }
}

/* returns the index of the given string, -1 if not found
 * 
 * O(l log n) 
 */
int sa_locate(sa_suf_arr *sa, const char *find)
{
    sfarr *s = (sfarr *)sa;
    unsigned int len = strlen(find);
    char **strings = s->suffixes;
    int min = 0;
    int max = s->nsuffix-1;
    int mid;
    
    while(min <= max){
        mid = (min + max) >> 1;
        //int cmp = strncmp(strings[mid], find, len);
        int cmp = contains_str(strings[mid],find);
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

inline size_t char_dist(const char *a, const char *b)
{
    size_t diff = (a < b) ? (b - a) : (a - b);
    return diff / sizeof(char);
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
    u32 longest = 0;
    u32 location = 0;
    
    u32 i;
    for(i = 1; i < s->nsuffix; i++){
        if(s->lcp[i] > longest){
            char *start1 = s->suffixes[i];
            char *start2 = s->suffixes[i-1];
            size_t dist = char_dist(start1, start2);
            if(dist >= longest){
                longest = dist;
                location = i;
            }
        }
    }
    
    return strndup(s->suffixes[location], longest);
}

unsigned int sa_count_occurrences(sa_suf_arr *sa, const char *str)
{
    sfarr *s = (sfarr *)sa;
    u32 i = sa_locate(sa, str);
    u32 slen = strlen(str);
    if(i == -1)
        return 0;
    
    u32 len = s->nsuffix;
    u32 count = 1;
    { // left
        u32 lcpi = i;
        while(lcpi-- > 0){
            if(s->lcp[lcpi] >= slen)
                count++;
            else break;
        }
    };
    
    { // right
        u32 lcpi = i;
        while(lcpi < len){
            if(s->lcp[lcpi] >= slen)
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