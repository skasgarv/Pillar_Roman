/*
 ============================================================================
 Name        : RomanMain.c
 Author      : Suhas
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implementation.h"

int isValid(char number[1000]) {
	int i = 0;
	while (number[i]) {
		if (digitValue(number[i]) < 0) {

			return 0;
		}
		if ((strlen(number) - i) > 2) {
			if (digitValue(number[i]) < digitValue(number[i + 2])) {
				printf("Invalid Roman number. Exiting the program");
				return 0;
			}
		}
		i++;
	}
	return 1;
}



int main(void) {

	//Enter 1st number
	printf("Enter the first Roman number:");
	char roman_Number1[1000];
	scanf("%s", roman_Number1);

	if (!isValid(roman_Number1)) {
		printf("Invalid Roman digit-2. Exiting the program");
		return 0;
	}

	//Enter 2nd number
	printf("Enter the second Roman number:");
	char roman_Number2[1000];
	scanf("%s", roman_Number2);

	printf("\n");
	if (!isValid(roman_Number2)) {
		printf("Invalid Roman digit-2. Exiting the program");
		return 0;
	}

	printf("Enter Operation:\n");
	printf("\tEnter '1' for Addition\n");
	printf("\tEnter '2' for Subtraction\n");
	int operationValue;
	scanf("%d", &operationValue);
    printf("\n");
	

	if (operationValue == 1) {
		char *c1 = romanAddition(roman_Number1, roman_Number2);
		printf("\nAddition of %s + %s = %s\n", roman_Number1, roman_Number2, c1);
	} else if (operationValue == 2) {
		char *c2 = romanSubtraction(roman_Number1, roman_Number2);
		printf("\nDifference of %s - %s = %s\n", roman_Number1, roman_Number2, c2);
	} else {
		printf("Invalid Option.\n");
		printf("\tEnter '1' for Addition\n");
		printf("\tEnter '2' for Subtraction\n");
	}

	return 0;
}
