/*
 * Problem 112: Bouncy numbers
 * 
 * https://projecteuler.net/problem=112
 */


#include <stdio.h>

#define RATIO 0.99


//Function that checks the problem condition
int is_ratio_reached(int bouncy, int non_bouncy){
	return ((double)bouncy)/(bouncy+non_bouncy) >= RATIO;
}

//Returns the relative direction between two digits, left to right
int get_direction(int n1, int n2){
	if (n1 < n2){
		//Increasing
		return 1;
	}
	else if (n1 > n2){
		//Decreasing
		return -1;
	}
	else{
		//Equal, representing that the direction didn't change without knowledge of previous iterations
		return 0;
	}
}

//Tells whether a number is bouncy, right to left; bouncy vs non-bouncy is a symmetric problem
int is_bouncy(int number){
	int n1, n2, direction, new_direction;
	
	//Get the two rightmost digits
	n1 = number%10;
	number /= 10;
	n2 = number%10;
	number /= 10;
	
	//So log as they are equal and there is still a number to extract digits from
	while (n1 == n2 && number != 0){
		//Copy the left digit into the right digit and extract another one
		n1 = n2;
		n2 = number%10;
		number /= 10;
	}
	
	if (number == 0){
		//If there is not a number at this point, all digits are equal, therefore non-bouncy
		return 0;
	}
	else{
		//Otherwise, calculate the direction
		direction = get_direction(n1, n2);
		
		//While there is still a number to extract digits from
		while (number != 0){
			//Move one position to the left
			n1 = n2;
			n2 = number%10;
			number /= 10;
			
			//Compare directions
			new_direction = get_direction(n1, n2);
			if (new_direction == -direction){
				//If the direction has changed, then the number is bouncy
				return 1;
			}
		}
		//If the direction didn't change at all, then non-bouncy
		return 0;
	}
}

int main(){
	//We know the first 99 numbers are non-bouncy
	int i, bouncy = 0, non_bouncy = 99;
	
	//Until the ratio is reached
	for (i = 100; !is_ratio_reached(bouncy, non_bouncy); i++){
		//Add numbers to the counts
		if (is_bouncy(i)){
			bouncy++;
		}
		else{
			non_bouncy++;
		}
	}
	
	//Subtract one from the result to compensate for the last increment in the for loop
	printf("The first number that satisfies the condition is %i\n", i-1);
		
	return 0;
}

