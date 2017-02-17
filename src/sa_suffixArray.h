
#ifndef SA_SUFFIXARRAY_H
#define	SA_SUFFIXARRAY_H

    #define sa_lcpa_len(suf_arr_ptr) (((sfarr *)suf_arr_ptr)->nsuffix);     
    
    #define sa_src_str_len(suf_arr_ptr) (((sfarr *)suf_arr_ptr)->nsuffix);
    
    typedef struct sfarr sa_suf_arr;
    
    sa_suf_arr *sa_new(const char *src);
    void sa_free(sa_suf_arr *sa);

#ifdef	__cplusplus
}
#endif

#endif	/* SA_SUFFIXARRAY_H */

