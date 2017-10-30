/*
 * Problem 99: Largest exponential
 *
 * https://projecteuler.net/problem=99
 */



#include <stdio.h>
#include <math.h>


int main(){
	//Open the file and check for success
	FILE *file = fopen("dataset.txt\0", "r");
	if (file != NULL){
		int base, exponent, max_line, line = 1;
		double result, max = 0;
		
		//Read the tuples one by one
		while (fscanf(file, "%d, %d", &base, &exponent) != EOF){
			//If A > B, then log(A) > log(B), here I am applying log(b^e) = e*log(b)
			result = exponent * log((double)base);
			//Compare the result with the maximum value and update the records if needed
			if (result > max){
				max = result;
				max_line = line;
			}
			line++;
		}
		
		//Close the file and output the result
		fclose(file);
		printf("The biggest value is at line %d\n\n", max_line);
	}
	else{
		printf("The file couldn't be found.\n\n");
	}
	return 0;
}

