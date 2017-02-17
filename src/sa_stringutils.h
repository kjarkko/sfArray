#ifndef SA_STRINGUTILS_H
#define	SA_STRINGUTILS_H

    #include "sa_suffixArray.h"
    int sa_contains(sa_suf_arr *sa, const char *str);
    int sa_locate(sa_suf_arr *sa, const char *str);
    char *sa_longest_common(sa_suf_arr *sa1, sa_suf_arr *sa2);
    char *sa_longest_repeated(sa_suf_arr *sa1, sa_suf_arr *sa2);
    char *sa_longest_palindrome(sa_suf_arr *sa1);

#endif

