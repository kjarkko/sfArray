#ifndef SFARR_H
#define SFARR_H


struct sf_arr {
	/* possibly padded with extra '\0' bytes 
	 * to make length divisible by three
	 * see DC3 algorithm for more info
	 */
	char *base_str;

	/* index of each suffix, sorted
	 */
	int *suffixes;

	/*
	 */
	int *lcp_arr;

	/* see base_str for more info on padding
	 */
	int len;
};

/* use the sfa_free function to release memory allocated by this funtion
 * the str parameter is copied into a new string
 */
void sfa_init(struct sf_arr *sa, const char *str, int len);
void sfa_free(struct sf_arr *sa);

/* returns the index of the string find in
 * the base_str, -1 if the string is not present
 */
int sfa_strpos(struct sf_arr *sa, const char *find);

/* 
 */
int sfa_contains(struct sf_arr *sa, const char *find);


#endif
