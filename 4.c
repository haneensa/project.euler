#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(int);
int largePalProduct(void);

int main() {
	printf("Large Palindrome Product is %d\n", largePalProduct());	
	return 0;
}


int is_palindrome (int n) 
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


int largePalProduct (void) 
{
	int max = 0;
	int i, j;
	for (i = 999; i > 99; i--) {
		for (j = 999; j > 99; j--) {
			if (is_palindrome(j*i)) {
				if (max < i * j)
					max = i *j;
			}
		}
	}
	return max;	 
}
