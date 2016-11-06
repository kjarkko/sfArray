#### Program structure
- sa_suffixArray: construction and deletion algorithms
- sa_stringutils: all the algorithms that utilize suffix arrays in some way
- util: bunch of useful definitions used by the program

#### Performance and worst case space/time complexity (n is the length of the source string)
- Suffix array construction: n^2 (goal is O(n) using the DC3/skew algorithm)
- finding substrings: n log n
- longest recurring substring: n
- number of times string occurs: n log n

#### Shortcomings
The main issue with the project at the moment is that the algorithm that constructs the suffix array is a naive implementation (constructs the array by radix sorting the suffixes, O(n^2)). I have not managed to replace it with the DC3/skew algorithm because I am having trouble understanding/implementing it in practice. 

#### Sources
https://www.cs.umd.edu/class/fall2011/cmsc858s/SuffixArrays.pdf

I have used various other sources including wikipedia but the one above is the main one. (Also I cannot remember the rest.)
