/* 
 * File:   sa_suffixArray.h
 * Author: jarkko
 *
 * Created on September 9, 2016, 6:06 PM
 */

#ifndef SA_SUFFIXARRAY_H
#define	SA_SUFFIXARRAY_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct suffixarray_st sa_sufArr;

    sa_sufArr *sa_new(const char *src);
    void sa_free(sa_sufArr *sa);

#ifdef	__cplusplus
}
#endif

#endif	/* SA_SUFFIXARRAY_H */

