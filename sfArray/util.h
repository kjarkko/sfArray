/* 
 * File:   util.h
 * Author: jarkko
 *
 * Created on September 17, 2016, 3:07 PM
 */

#ifndef UTIL_H
#define	UTIL_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct str_arr_st str_arr;
    
    str_arr *str_arr_new();
    void str_arr_free(str_arr *vector);
    
    unsigned int str_arr_size(str_arr *arr);
    char **get_array(str_arr *arr);
    void *str_arr_get(str_arr *arr, unsigned int index);
    unsigned int str_arr_find(str_arr *arr, char *str);
    int str_arr_contains(str_arr *arr, char *str);
    int str_arr_add(str_arr *arr, char *str);


#ifdef	__cplusplus
}
#endif

#endif	/* UTIL_H */

