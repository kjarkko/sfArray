/* 
 * File:   def.h
 * Author: jarkko
 *
 * Created on October 14, 2016, 1:45 PM
 */

#ifndef DEF_H
#define	DEF_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {
    char *src_str;
    int *lcp;
    char **suffixes;
    unsigned int nsuffix;
} sfarr;

typedef struct {
    char **arr;
    unsigned int size;
    unsigned int length;
} str_arr_st;

typedef unsigned int u32;


#ifdef	__cplusplus
}
#endif

#endif	/* DEF_H */

