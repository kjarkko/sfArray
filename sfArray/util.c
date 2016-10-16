#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include "util.h"

typedef unsigned int u32;

void rdxsrt(char **unsorted, u32 len, u32 char_index)
{
    u32 char_count[128] = {0}; // number of times ascii char c occurs in the strings
    u32 sumtbl[128]; // start index of strings, sum table of char_count
    u32 index[128]; // copy of sumtbl that is incremented
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
    memcpy(unsorted, sorted, len);
    
    char_index++;
    for(i = 1; i < 128; i++)
        //if(char_count[i] > 0)
            rdxsrt(&unsorted[sumtbl[i]], char_count[i], char_index);
}

void reverse(char **strings, unsigned int len){
    if(len == 0)
        return;
    
    unsigned int l, r;
    for(l = 0, r = len-1; l < r; l++, r--){
        char *swp = strings[l];
        strings[l] = strings[r];
        strings[r] = swp;
    }
}

/* sort the string array based on MSD radix sort
 * 
 * O(n*l), l is the length of the longest string
 */
inline void radix_sort(char **strings, unsigned int len)
{
    rdxsrt(strings, len, 0);
}


/*---vector---*/

typedef struct {
    char **arr;
    unsigned int size;
    unsigned int length;
} str_arr_st;


/* Allocates a new vector.
 * 
 * O(1)
 */
str_arr *str_arr_new()
{
    str_arr_st *new = malloc(sizeof(str_arr_st));
    
    new->arr = malloc(8 * sizeof(char *));
    new->size = 0;
    new->length = 8;
    
    return (str_arr *)new;
}

/* free the given vector, strings are not freed
 * 
 * O(1)
 */
void str_arr_free(str_arr *vector)
{
    str_arr_st *vect = (str_arr_st *)vector;
    free(vect->arr);
    free(vect);
}

/* returns the amount of members in the given vector
 * 
 * O(1)
 */
inline unsigned int str_arr_size(str_arr *vector)
{
    return ((str_arr_st *)vector)->size;
}
    
/* returns a pointer to a dynamically allocated string array
 * the array is null terminated
 * 
 * O(n)
 */
char **get_array(str_arr *vector)
{
    str_arr_st *vect = (str_arr_st *)vector;
    char **arr = malloc((vect->size + 1) * sizeof(char *));
    arr[vect->size] = NULL;
    
    unsigned int i = 0;
    while(i < vect->size){
        arr[i] = strdup(vect->arr[i]);
        i++;
    }
    
    return arr;
}


/* Doubles the length of the vector and updates the 'length' variable
 */
int inc_len(str_arr_st *vect)
{
    unsigned int newlen = vect->length << 1;
    vect->length = newlen;
    vect->arr = realloc(vect->arr, newlen);
    return vect->arr != NULL ? EXIT_SUCCESS : EXIT_FAILURE;
}
    
/* Adds a member to the vector, increasing the size if needed.
 * 
 * O(1) most of the time, O(n) if the length is increased
 */
int str_arr_add(str_arr *vector, char *str)
{
    str_arr_st *vect = (str_arr_st *)vector;
    
    // increase the length of the vector if needed, return EXIT_FAILURE if unsuccessful
    if(vect->length == vect->size)
        if(inc_len(vect) == EXIT_FAILURE)
            return EXIT_FAILURE;
    
    vect->arr[vect->size] = str;
    vect->size++;
    
    return EXIT_SUCCESS;
}

/* return the pointer to the string stored in index i
 * 
 * O(1)
 */
inline char *str_arr_get(str_arr *vector, unsigned int index)
{
    return ((str_arr_st *)vector)->arr[index];
}

/* find the index of the given member, -1 if not contained in the array
 * O(n*l)
 */
int str_arr_find(str_arr *vector, char *str)
{
    str_arr_st *vec = (str_arr_st *) vector;
    unsigned int i = vec->size;
    while(vec->size-- > 0){
        if(strcmp(vec->arr[i], str) == 0)
        return i;
    }
    return -1;
}

