/* 
 * File:   sa_stringutils.h
 * Author: jarkko
 *
 * Created on September 9, 2016, 6:06 PM
 */

#ifndef SA_STRINGUTILS_H
#define	SA_STRINGUTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

    int sa_contains(sa_suf_arr *sa, const char *str);
    int sa_locate(sa_suf_arr *sa, const char *str);
    char *sa_longest_common(sa_suf_arr *sa1, sa_suf_arr *sa2);
    char *sa_longest_repeated(sa_suf_arr *sa1, sa_suf_arr *sa2);
    char *sa_longest_palindrome(sa_suf_arr *sa1);

#ifdef	__cplusplus
}
#endif

#endif	/* SA_STRINGUTILS_H */

