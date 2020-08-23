
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int * p;
	int	n = sizeof *p; 
	malloc(n);
	printf("every thing is ok %d", n);
	
	return 0;
}
