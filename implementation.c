#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "implementation.h"

char res[1000]={0};
char* romanAddition(char number1[1000], char number2[1000]) {
	int romanTonumber1 = romanToNumber(number1);
	int romanTonumber2 = romanToNumber(number2);

	int romanSum = 0;
	romanSum = romanTonumber1 + romanTonumber2;
	char *c = numberToRoman(romanSum);
	return c;

}

int romanToNumber(char number[1000]) {
	int i = 0, sum = 0;
	while (number[i]) {
		if (digitValue(number[i]) >= digitValue(number[i + 1]))
			sum = sum + digitValue(number[i]);
		else {
			sum = sum + (digitValue(number[i + 1]) - digitValue(number[i]));
			i++;
		}
		i++;
	}
	return sum;
}


int digitValue(char c) {

	int value = 0;

	switch (c) {
	case 'I':
		value = 1;
		break;
	case 'V':
		value = 5;
		break;
	case 'X':
		value = 10;
		break;
	case 'L':
		value = 50;
		break;
	case 'C':
		value = 100;
		break;
	case 'D':
		value = 500;
		break;
	case 'M':
		value = 1000;
		break;
	case '\0':
		value = 0;
		break;
	default:
		value = -1;
	}

	return value;
}

char* numberToRoman(int val) {
	

	char *huns[] =
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	char *tens[] =
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	char *ones[] =
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

	while (val >= 1000) {
		strcat(res, "M");
		val -= 1000;
	}

	strcat(res, huns[val / 100]);
	val = val % 100;
	strcat(res, tens[val / 10]);
	val = val % 10;
	strcat(res, ones[val]);

	printf("%s", res);
	return res;
}