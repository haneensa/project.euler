/* Finding the Greatest Common Divisor using different algorithms */

#include <stdio.h>
#include <stdlib.h>

/* Using Euclidean algorithm */
/* Recursive version */
int GCDr(int, int);
/* Subtraction version */
int GCDs(int, int);
/* division based  version */
int GCDd(int, int);

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Usage %s x y", argv[0]);
		return 0;
	}
	int x = strtol(argv[1], NULL, 10);
	int y = strtol(argv[2], NULL, 10);
	
	printf("GCD for %d and %d is %d\n", x, y, GCDr(x, y));
	return 0;
}

int min(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}
int GCDr(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCDr(y, x%y);
}

int GCDs(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCDr(y, x%y);
}

int GCDd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCDr(y, x%y);
}
