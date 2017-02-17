#include <stdlib.h>
#include <string.h>
#include "sfArr.h"

static void radix_pass(int *tbl, int len)
{

}

static void DC3_construct_array(struct sf_arr *sa)
{
	/* possibly allocate only one block, split into two arrays?
	 */
	int *lcp_arr = malloc(sizeof(int) * sa->len);
	int *suffixes = malloc(sizeof(int) * sa->len);

	sa->lcp_arr = lcp_arr;
	sa->suffixes = suffixes;
}


void sfa_init(struct sf_arr *sa, const char *str, int len)
{
	/* the DC3 algorithm requires that the string length be
	 * divisible by two (including the null terminator)
	 */
	 ++len;
	len += ((len + 3) % 3) - len; /*????*/
	sa->base_str = strncpy(calloc(len, sizeof(char)), str, len);
	sa->len = len;
	DC3_construct_array(sa);
}

void sfa_free(struct sf_arr *sa)
{
	free(sa->base_str);
	free(sa->lcp_arr);
	free(sa->suffixes);
}

int sfa_strpos(struct sf_arr *sa, const char *str)
{
	return -1;
}


int sfa_contains(struct sf_arr *sa, const char *str)
{
	return sfa_strpos(sa,str) != -1;
}
