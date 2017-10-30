/*
 * Problem 97: Large non-Mersenne prime
 * 
 * https://projecteuler.net/problem=97
 */

#include <stdio.h>

#define MAX 10000000000
#define EXPONENT 7830457

int main(){
	//The largest 10 digit number is 34 bit long, so we need a longer datatype than an int
	unsigned long long result = 1;
	int i;
	//Perform the 2^EXPONENT operation
	for (i = 0; i < EXPONENT; i++){
		result *= 2;
		//Truncate the result to 10 digits as soon as it becomes 11 digits long, this
		//	overcomes the precision issue
		if (result >= MAX){
			result %= MAX;
		}
	}
	
	//Perform the remainder of the operation and truncate again
	result = (result*28433 + 1)%MAX;
	
	printf("The last ten digits of 28433*2^7830457+1 are %llu\n", result);
	return 0;
}

