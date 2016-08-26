/*
 * Problem 89: Roman numerals
 *
 * https://projecteuler.net/problem=89
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function converts a roman numeral into an arabic numeral
int to_arabic_numeral(char *roman_numeral){
	char current, next;
	int number = 0;
	while (*roman_numeral != '\0'){
		current = *roman_numeral;
		next = *(roman_numeral+sizeof(char));
		if (current == 'M'){
			number += 1000;
		}
		else if (current == 'D'){
			number += 500;
		}
		else if (current == 'C'){
			if (next == 'M'){
				number += 900;
				roman_numeral++;
			}
			else if(next == 'D'){
				number += 400;
				roman_numeral++;
			}
			else{
				number += 100;
			}
		}
		else if (current == 'L'){
			number += 50;
		}
		else if (current == 'X'){
			if (next == 'C'){
				number += 90;
				roman_numeral++;
			}
			else if(next == 'L'){
				number += 40;
				roman_numeral++;
			}
			else{
				number += 10;
			}
		}
		else if (current == 'V'){
			number += 5;
		}
		else if (current == 'I'){
			if (next == 'X'){
				number += 9;
				roman_numeral++;
			}
			else if(next == 'V'){
				number += 4;
				roman_numeral++;
			}
			else{
				number += 1;
			}
		}
		roman_numeral++;
	}
	return number;
}

//This function counts the number of characters a roman numeral would have
int count_in_roman(int src){
	int count = 0;
	while (src != 0){
		if (src >= 1000){
			count++;
			src -= 1000;
		}
		else if (src >= 900){
			count += 2;
			src -= 900;
		}
		else if (src >= 500){
			count++;
			src -= 500;
		}
		else if (src >= 400){
			count += 2;
			src -= 400;
		}
		else if (src >= 100){
			count++;
			src -= 100;
		}
		else if (src >= 90){
			count += 2;
			src -= 90;
		}
		else if (src >= 50){
			count++;
			src -= 50;
		}
		else if (src >= 40){
			count += 2;
			src -= 40;
		}
		else if (src >= 10){
			count++;
			src -= 10;
		}
		else if (src >= 9){
			count += 2;
			src -= 9;
		}
		else if (src >= 5){
			count++;
			src -= 5;
		}
		else if (src >= 4){
			count += 2;
			src -= 4;
		}
		else if (src >= 1){
			count++;
			src -= 1;
		}
	}
	return count;
}

int main(){
	//Open the file and check for success
	FILE *file = fopen("dataset.txt\0", "r");
	if (file != NULL){
		char *roman_numeral = (char*)malloc(64*sizeof(char));
		int number, saved_characters = 0;
		//Read the numbers one by one
		while (fscanf(file, "%s", roman_numeral) != EOF){
			//Convert to arabic numeral
			number = to_arabic_numeral(roman_numeral);
			//Compare the optimal length against the length of the provided number
			saved_characters += strlen(roman_numeral)-count_in_roman(number);
		}
		printf("%d characters saved\n\n", saved_characters);
	}
	else{
		printf("The file couldn't be found.\n\n");
	}
	return 0;
}

