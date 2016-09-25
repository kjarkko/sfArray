#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


void radix_sort(char **strings, unsigned int len)
{
    
}


/*---vector---*/

typedef struct {
    char **arr;
    unsigned int size;
    unsigned int length;
} str_arr_st;


/* Allocates a new vector.
 */
str_arr *str_arr_new()
{
    str_arr_st *new = malloc(sizeof(str_arr_st));
    
    new->arr = malloc(8 * sizeof(char *));
    new->size = 0;
    new->length = 8;
    
    return (str_arr *)new;
}

/* 
 */
void str_arr_free(str_arr *vector)
{
    str_arr_st *vect = (str_arr_st *)vector;
    unsigned int i = 0;
/*
    while(i < vect->size){
        free(vect->arr[vect->size]);
        i++;
    }
*/
    free(vect->arr);
    free(vect);
}

inline unsigned int str_arr_size(str_arr *vector)
{
    return ((str_arr_st *)vector)->size;
}
    
/* returns a pointer to a dynamically allocated string array
 * the array is null terminated
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
    
/* Adds a member to the array, increasing the size if needed.
 */
int str_arr_add(str_arr *vector, char *str)
{
    str_arr_st *vect = (str_arr_st *)vector;
    
    if(vect->length == vect->size){
        int success = inc_len(vect);
        if(!success)
            return 0;
    }
    
    vect->arr[vect->size] = str;
    vect->size++;
    
    return 1;
}

/* return the pointer to the string stored in index i
 */
inline char *str_arr_get(str_arr *vector, unsigned int index)
{
    return ((str_arr_st *)vector)->arr[index];
}

/* find the index of the given member, -1 if not contained in the array
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

/* Doubles the length of the array and updates the 'length' variable
 */
int inc_len(str_arr_st vect)
{
    unsigned int newlen = vect.length << 1;
    vect.length = newlen;
    vect.arr = realloc(vect.arr, newlen);
    return vect.arr != NULL;
}
