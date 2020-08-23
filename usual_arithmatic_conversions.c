#include<stdio.h>
#include<stdlib.h>

int main()
{
	if ( -1 < (unsigned char) 1 )
		printf("-1 is less than (unsigned char) 1: ANSI semantics \n");
	else
		printf("-1 NOT less than (unsigned char) 1: K&R semantics \n");

	unsigned int a = -5;
	int b = -4;
	printf("a + b = %d\n", a + b);
	return 0;
}
