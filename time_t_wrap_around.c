// when the time_t's wrap around
#include<stdio.h>
#include<time.h>
#include<stdint.h>

int main(void)
{
	time_t now = time(NULL);
	time_t biggest = 0x7fffffff;
	printf("print the value in string form:%s", asctime(gmtime(&biggest)));
	
	return 0;
}
