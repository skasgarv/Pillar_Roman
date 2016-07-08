char* romanAddition(char number1[1000], char number2[1000]) {
	int romanTonumber1 = romanToNumber(number1);
	int romanTonumber2 = romanToNumber(number2);

	int romanSum = 0;
	romanSum = romanTonumber1 + romanTonumber2;
	char *c = malloc(1000);
	numberToRoman(romanSum, c);
	return c;

}