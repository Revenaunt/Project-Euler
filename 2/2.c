#include <stdio.h>

#define LIMIT 4000000

int main(){
	//Variables: the total sum, a two element array containing the last two values of the
	//	fibonacci sequence, the iteration number to keep track of whick array element to
	//	overwrite, and the next fibonacci number. 
	int sum, fibo[2] = {1, 1}, i, next = fibo[0] + fibo[1];
	
	//Until the limit is reached
	for (sum = 0, i = 0; next <= LIMIT; i++){
		//Add if even.
		if (!(next%2)){
			sum += next;
		}
		//Store the next.
		fibo[i%2] = next;
		next = fibo[0] + fibo[1];
	}
	
	printf("The sum of the even fibonacci sequence terms whose value is below 4M is %i\n", sum);
}

