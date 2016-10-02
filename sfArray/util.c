#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

#define swap(s1ptr, s2ptr) {char *tmp = s1ptr; s1ptr = s2ptr; s2ptr = tmp;};

void radix_sort_subarray(
        char **strings, char **aux,
        unsigned int l, unsigned int r, // left, right
        unsigned int n) // index of char
{
    int count[256];
    int i = l;
    while(i < r){
        
    }
    
    //char *aux[r-l];
    
}

/* sorts the given string array using MSD radix sort
 */
void radix_sort(char **strings, unsigned int len)
{
    char *aux[len];
    memset(aux, 0, len);
    radix_sort_subarray(strings, aux, 0, len, 0);
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

/* free the given vector, strings are not freed
 */
void str_arr_free(str_arr *vector)
{
    str_arr_st *vect = (str_arr_st *)vector;
    free(vect->arr);
    free(vect);
}

/* returns the amount of members in the given vector
 */
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

