/*
 * Problem 21: Amicable numbers.
 *
 * https://projecteuler.net/problem=21
 */


#include <stdio.h>
#include <stdlib.h>

#define SCOPE 10000
#define PRINT 0


//The sum of the proper divisors of a number, as defined by the problem
int d(int n){
    int i, result = 0;
    for (i=1; i<=n/2; i++){
        if (!(n%i)){
            result += i;
        }
    }
    return result;
}

int amicable(int *sums, int a){
    int b = sums[a];
    //d(6) = 6, however a number cannot be amicable with itself
    if (a != b){
        //Actual condition for a number to be amicable with another number
        if (sums[a] == b && sums[b] == a){
            return 1;
        }
    }
    return 0;
}

int main(){
    int i, result = 0;
    int *sums = (int*)malloc(SCOPE*sizeof(int));
    
    sums[0] = 0;
    sums[1] = 0;
    for (i=2; i<SCOPE; i++){
        sums[i] = d(i);
        if (PRINT){
            printf("%d: %d\n", i, sums[i]);
        }
    }
    
    for (i=2; i<SCOPE; i++){
        if (amicable(sums, i)){
            //If the numbers are amicable, add both numbers to the result and mark the higher as added
            result += i;
            result += sums[i];
            if (PRINT){
                printf("%d and %d are amicable\n", i, sums[i]);
            }
            sums[i] = 0;
        }
    }
    
    free(sums);
    
    printf("\nThe sum of all amicable numbers between 1 and %d is %d\n\n", SCOPE, result);
    
    return 0;
}

