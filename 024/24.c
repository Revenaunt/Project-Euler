/*
 * Problem 21: Lexicographic permutations.
 *
 * https://projecteuler.net/problem=24
 */


#include <stdio.h>

#define TARGET 1000000
#define PRINT 0


int factorial(int n){
    if (n < 2){
        return 1;
    }
    return n*factorial(n-1);
}

void print(int *array){
    int i;
    printf("[");
    for (i = 0; i < 10; i++){
        printf("%d", array[i]);
        if (i < 9){
            printf(", ");
        }
    }
    printf("]\n");
}

//This function calculates the number of permutations in all branches in order, traversing
//  only the branch that would make the target overflow. When it finds said branch, it records
//  the number of iterations it took to find it and moves on to that branch. The process is
//  repeated until the function gets to the bottom of the permutation tree.
//
//  NOTE: This could be achieved with modulo math as well.
void next(int *iterations, int total_permutations, int level){
    int i, branch_permutations = factorial(level);
    if (level < 0){
        return;
    }
    if (PRINT){
        printf("\nLevel: %d", level);
        printf("\nBranch Permutations: %d\n", branch_permutations);
    }
    for (i = 0; i < 10; i++){
        if (PRINT){
            printf("\tTotal Permutations: %d\n", total_permutations);
        }
        //count([0, 999999]) = 1000000
        if (total_permutations + branch_permutations >= TARGET){
            iterations[9-level] = i;
            next(iterations, total_permutations, level-1);
            break;
        }
        else{
            total_permutations += branch_permutations;
        }
    }
}

//This function calculates the permutation from the iteration array. It finds the nth available
//  item in an availability array, where n is the number of iterations that took to get to
//  the branch of the tree that needed to be traversed. This item, which is the next digit
//  in the permutation we're looking for, is recorded and marked unavailable. The process is
//  repeated until there are no more available digits.
void calculate_permutation(int *iterations){
    int available[10], i, j;
    
    for (i = 0; i < 10; i++){
        available[i] = 1;
    }
    if (PRINT){
        print(iterations);
        print(available);
        printf("\n");
    }
    
    for (i = 0; i < 10; i++){
        for (j = 0; j < iterations[i]; j++){
            if (!available[j]){
                //Add the gaps to the number of iterations to get the correct result
                iterations[i]++;
            }
        }
        //If we land on a gap, find the next available result
        while (!available[j++]){
            iterations[i]++;
        }
        //Mark the result unavailable
        available[iterations[i]] = 0;
        
        if (PRINT){
            print(iterations);
            print(available);
            printf("\n");
        }
    }
}

int main(){
    int iterations[10];
    next(iterations, 0, 9);
    calculate_permutation(iterations);
    
    printf("The millionth lex permutation of 0-9 is ");
    print(iterations);
    printf("\n");
    
    return 0;
}

