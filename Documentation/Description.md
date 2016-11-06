#### A suffix array library for C.

The library will mainly consist of two parts, the suffixArray file that builds the data structure and the stringutils file which is meant for all the operations that are related to the suffix array.

####Using the library
The actual usability of the program as a library at the moment might be somewhat questionable, since I haven't been able to import it into other projects, at least in netbeans. My inexperience with C projects in general has been a issue in this project.

For creating and freeing suffix arrays, include the header "sa_suffixArray.h" and to get access to operations that utilize them, use the header "sa_stringutils.h"
Notable functions include (all functions have the prefix 'sa_'): new, free, contains, longest_recurring, count_occurrances

example - does the string "mississippi" contain "sip":
sa_suf_arr *sa = sa_new("mississippi");
int contains = sa_contains(sa, "sip");
sa_free(sa);

#### Sources 
- https://en.wikipedia.org/wiki/Suffix_array
- https://www.cs.umd.edu/class/fall2011/cmsc858s/SuffixArrays.pdf
