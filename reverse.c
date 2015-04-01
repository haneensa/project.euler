#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Reverse string using modulus op */
int reverse1(int);
/* Reverse int using string */
int reverse2(int);
/* Reverse int using modulus with recrusion */
int reverse3(int);
/* Reverse string */
int reverse4(int);

int main() {
	printf("Expermentation with various method to reverse a string"));	
	return 0;
}

int reverse1(int n) 
{
	int flag = 0;
	int org = n;
	int reverse = 0;
	while (n != 0) {
		reverse = reverse * 10;
		reverse = reverse + n%10;
		n = n/10;
	}
	if (org == reverse)
		flag = 1;
	return flag;
}
int reverse2 (int num) 
{
	int flag = 0;
	int i;
	int len = sizeof(num) + 1;
	char *str = (char*) malloc(len*sizeof(char));
	char *reverse = (char*) malloc(len*sizeof(char));

	printf("size of str %ld\n", len);
	snprintf(str, sizeof(str), "%d", num);
	for (i = len; i > 0;  i--) {
		reverse = &str[i];
	}
	printf("reverse is %s, and str is %s\n", reverse, str);
	if (strcmp(str, reverse))
		flag = 1;
	return flag;
}
