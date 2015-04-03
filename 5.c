#include <stdio.h>
#include <stdlib.h>

long smallestMul(int);

int main(int argc, char *argv[])
{
	//check on the argc if less than 2 then break
	if (argc < 2 || argc > 2) {
		printf("Usage: %s range#.\n", argv[0]);
		return 1;
	}
	printf("argv[1] is: %d\n", atoi(argv[1]));
	printf("Smallest Mutiple is: %ld\n", smallestMul(atoi(argv[1])));
	return 0;

}


long smallestMul(int range)
{
	long i = 0;
	int j;
	int flag = 1;	
	while(flag) {
		++i;
		flag = 0;
		for(j = 1; j <= range; j++) {
			if ((i%j) != 0) {
				flag = 1;
				break;
			}
		}
		//printf("%d\n", i);
	}
	return i;
}