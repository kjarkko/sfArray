#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include "util.h"
#include "def.h"


void rdxsrt(char **unsorted, u32 len, u32 char_index)
{
    u32 char_count[128] = {0};
    u32 sumtbl[128];
    u32 index[128]; 
    u32 i;
    
    for(i = 0; i < len; i++)
        char_count[unsorted[i][char_index]]++;
    
    sumtbl[0] = 0;
    for(i = 1; i < 128; i++)
        sumtbl[i] = sumtbl[i-1] + char_count[i-1];
    memcpy(index, sumtbl, 128 * sizeof(u32));
    
    char *sorted[len];
    for(i = 0; i < len; i++){ 
        char *str = unsorted[i];
        sorted[index[str[char_index]]++] = str;
    }
    memcpy(unsorted, sorted, len * sizeof(char *));
    
    char_index++;
    for(i = 1; i < 128; i++)
        if(char_count[i] > 0)
            rdxsrt(&unsorted[sumtbl[i]], char_count[i], char_index);
}

/* sort the string array based on MSD radix sort
 * 
 * O(n*l), l is the length of the longest string
 */
inline void radix_sort(char **strings, unsigned int len)
{
    rdxsrt(strings, len, 0);
}

