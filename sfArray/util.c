#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

typedef struct {
    char **arr;
    unsigned int size;
    unsigned int length;
} str_arr_st;


/* Allocates a new vector.
 */
str_arr *str_arr_new(){
    str_arr_st *new = malloc(sizeof(str_arr_st));
    
    new->arr = malloc(8 * sizeof(char *));
    new->size = 0;
    new->length = 8;
    
    return (str_arr *)new;
}

/* 
 */
void str_arr_free(str_arr *vector){
    str_arr_st *vect = (str_arr_st *)vector;
    unsigned int size = vect->size;
    while(size > 0){
        size--;
        free(vect->arr[size]);
    }
    free(vect->arr);
    free(vect);
}

unsigned int str_arr_size(str_arr *vector){
    return ((str_arr_st *)vector)->size;
}
    
char **get_array(str_arr *vector){
    str_arr_st *vect = (str_arr_st *)vector;
    char **arr = malloc(vect->size * sizeof(char *));
    
    unsigned int i = 0;
    while(i < vect->size){
        arr[i] = strdup(vect->arr[i]);
    }
    
    return arr;
}
    
/* Adds a member to the array, increasing the size if needed.
 */
int str_arr_add(str_arr *vector, char *str){
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

/* find the index of the given member, -1 if not contained in the array
 */
unsigned int str_arr_find(str_arr *vector, char *str){
    
}

int str_arr_contains(str_arr *vector, char *str){
    
}

/* Doubles the length of the array and updates the 'length' variable
 */
int inc_len(str_arr_st vect){
    unsigned int newlen = vect.length << 2;
    vect.length = newlen;
    vect.arr = realloc(vect.arr, newlen);
}
