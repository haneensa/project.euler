#include <stdio.h>

void fib(int);

int main (int argc, char *argv[])
{
	fib(1000000);	
}

void fib(int limit) {
	int sec = 1;
	int first = 0;
	int i, fib;
	long sum = 0;
	for (i = 0; i < limit; i++) {
		fib = sec + first;
		//printf("%d ", fib);
		first = sec;
		sec = fib;
		if (fib > 4000000)
			break;
		if (fib%2 == 0)
			sum += fib;
	}
	printf("\n");
	printf("sum = %ld\n", sum);
}
