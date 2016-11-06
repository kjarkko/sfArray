
#### Performance tests

testing the algorithms inside the stringutils file is not really feasible since they are all O(n log n) or lower, meaning that in order to get any meningful performance data out of them the array construction algorithm would have to work for way too long (see implementation.md - shortcomings).

Suffix array construction
- single character ('a'^n) string:
- 1000  - 0.0135 seconds
- 2000  - 0.0444 seconds
- 3000  - 0.0829 seconds
- 4000  - 0.1292 seconds
- 5000  - 0.2592 seconds
- 6000  - 0.3526 seconds
- 7000  - 0.4795 seconds
- 8000  - 0.5306 seconds
- 9000  - 0.5013 seconds
- 10000 - 0.5694 seconds

randomized string, length 1000: 0.4599 seconds (average, 10 strings)

