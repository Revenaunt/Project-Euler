/*
 * Problem 7: 10001st prime.
 *
 * https://projecteuler.net/problem=7
 */


#include <stdio.h>

#define TARGET 10001


int main(){
    //Keep a list of prime numbers
    int list[TARGET] = {};
    int n, i, j;
    
    list[0] = 2;
    for (n = 3, i = 1; i < TARGET; n++){
        for (j = 0; j < i; j++){
            //Since all factors are primes we only need to check against the numbers
            //  that are already in the list, when a factor is found, break the loop
            if (!(n%list[j])){
                break;
            }
        }
        //If a factor was not found, then this is a prime; add it to the list
        if (j == i){
            list[i] = n;
            i++;
        }
    }
    
    printf("The prime number %d is %d\n\n", TARGET, list[TARGET-1]);
}

