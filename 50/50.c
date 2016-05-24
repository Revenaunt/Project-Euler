/*
 * Problem 50: Consecutive prime sum
 *
 * https://projecteuler.net/problem=50
 */


#include <stdio.h>
#include <stdlib.h>

//A constant with the problem's boundary.
#define LIMIT 1000000


int main(){
	//A byte field for the sieve of Eratosthenes, an additional element was added
	//	to match indices and numbers.
	char *byte_field = (char*)malloc((LIMIT+1)*sizeof(char));
	int i, j, current_sum, largest_prime;
	
	//Initialise the sieve's array to 1, as all numbers are possible primes.
	byte_field[0] = 0;
	byte_field[1] = 0;
	for (i = 2; i < LIMIT+1; i++){
		byte_field[i] = 1;
	}
	
	//Execute the sieve
	for (i = 2; i < LIMIT+1; i++){
		if (!byte_field[i]){
			continue;
		}
		for (j = 2*i; j < LIMIT+1; j += i){
			byte_field[j] = 0;
		}
	}
	
	//Traverse the array, initialise current sum and largest prime to 0.
	for (i = 2, current_sum = 0, largest_prime = 0; i < LIMIT+1; i++){
		//If this is a prime, add it to the current sum, if the sum exceeds the limit undo the
		//	operation and break the loop, otherwise, and, if the result is a prime, record it.
		if (byte_field[i]){
			current_sum += i;
			if (current_sum > LIMIT){
				current_sum -= i;
				break;
			}
			if (byte_field[current_sum]){
				largest_prime = current_sum;
			}
		}
	}
	
	//Since the problem is about finding consecutive primes, we need to try removing the lower
	//	primes to see if the result increases, once the sum falls below the largest recorded
	//	prime carrying on would make no sense. So, starting from 2, remove primes from the sum.
	for (i = 2; current_sum > largest_prime; i++){
		if (byte_field[i]){
			current_sum -= i;
			//If the operation yields a prime, it will be in fact the largest prime we'll be
			//	able to find, since at this point we are subtracting.
			if (byte_field[current_sum]){
				largest_prime = current_sum;
				break;
			}
		}
	}
	
	//Clean up and output the result.
	free(byte_field);
	printf("\n\nThe largest prime is %i\n\n", largest_prime);
}
