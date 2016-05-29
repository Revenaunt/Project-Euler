/*
 * Problem 1: Multiples of 3 nad 5.
 *
 * https://projecteuler.net/problem=1
 */


#include <stdio.h>

#define MAX 1000

int main(){
	//Sum of the numbers in the 3, 6, ..., 999 arithmetic series
	int sum = (MAX/3) * (3 + MAX - MAX%3) / 2;
	int i;
	//Add all the multiples of 5 that ain't multiples of 3
	for (i = 5; i < MAX; i += 5){
		if (i%3 != 0){
			sum += i;
		}
	}
	
	printf("The sum is %i\n", sum);
	return 0;
}

