#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "sa_suffixArray.h"
#define EQUAL 0


unsigned int sa_strlen(const char *s)
{
    unsigned int i = 0;
    while(s[i] != '\0') i++;
    return i;
}

int sa_strcmp(const char *a, const char *b)
{
    return 0;
}

/* determines whether the given string is a substring within the array
 */
int sa_contains(sa_suf_arr *sa, const char *str)
{
    return 0;
}

/* returns the index of the given string, -1 if not found
 */
int sa_locate(sa_suf_arr *sa, const char *str)
{
    return -1;
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

/* asd
 */
char *sa_longest_palindrome(sa_suf_arr *sa1)
{
    return NULL;
}