#include <stdio.h>
#include <math.h>

int isPrime(int);
void primeFactor (long num);

int main()
{
	printf("is 4 a prime? %d\n", isPrime(4));
	printf("is 7 a prime? %d\n", isPrime(7));
	primeFactor(600851475143);
}

int isPrime(int test) {
	int prime = 1;
	int i;
	for (i = 2; i <= test; i++) {
		if ( (test != i) && (test % i == 0)) {
			prime = 0;
			break;
		}
	}
	return prime;
}

void primeFactor(long num) 
{
	int i;
	for (i = 2; i < sqrt(num); i++) {
		if( isPrime(i) && (num % i == 0) )
			printf("%d ", i);
	}
	printf("\n");
}
