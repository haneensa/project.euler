#include <stdio.h>
#include <stdlib.h>

#include <math.h>

double mcp1(double n, double m);

long sum(int, int, int);

int main ( int argc, char *argv[] ) {
	if (argc != 4)
		printf("usage: %s first# second# below#\n", argv[0]);
	else {
		int a, b, c;
		a = strtol(argv[1], NULL, 0);
		b = strtol(argv[2], NULL, 0);
		c = strtol(argv[3], NULL, 0);
		long ans = sum(a, b, c);
		printf("Answer = %ld\n", ans);
    		// second approach
		
		printf("--- %.1f\n",
        	mcp1(3.0, 999.0) + mcp1(5.0, 999.0) - mcp1(15.0, 999.0));
	}
	return 0;
}

long sum(int first, int sec, int below) {
    int i;
    long sum = 0;
    for (i = 0; i < below; i++) {
    	if ((i % first == 0)|| (i % sec == 0)) {
        	sum += i;
	}
	}
    return sum;
}

double mcp1(double n, double m) {
    double floor(double x);
    double fl = floor(m/n);
    return n * fl * (fl + 1) / 2;
}

