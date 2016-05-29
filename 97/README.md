# Problem 97: [Large non-Mersenne prime](https://projecteuler.net/problem=97)

This problem consists in finding the rightmost 10 digits of 28433×(2^7830457)+1, a 2,357,207 digit long number.

### Issues

The only issue of this problem is datatype precision, the number to calculate is gigantic.

### Solutions

Since the problem requires only the last ten digits of the number in question, the rest of the actual number is irrelevant. The largest 10-digit number, however, is 34-bit long, which requires a datatype larger than `int`, which is 32 bit long. The next bigger datatype, `long`, will suffice, since it is 64-bit in length. The trick here is checking if the result has become more than 10 digits long and, if so, truncate it to 10 digits with a modulo operation.
