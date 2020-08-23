#include<stdio.h>
#include<stdlib.h>
void foo(const char** p)
{
	return;
}

int main(int argc, char** argv)
{
	char* cp;
	const char* ccp;
	ccp = cp;   // this works fine
	// the type pointed to by the left operand has all the qualifiers of the type pointed to by the right operand(none) ,
	// plus one on its own (const)

	//cp = ccp;   // but this will cause an error
	// i really see this is straight forward, we can not assign a pointer, that can not change the value in 
	// the locationa it poitnts to, to a pointer that can do so.
	

	/*
	// this won't compile and will cause an error: 
	foo(argv);
	*/

	// the const keyword would have been better named readonly
	const int limit = 10;
	const int* limitp = &limit;
	// *limitp = 15; // this won't work, and will cause an error
	// error: assignment of read-only location
	const int limit2 = limit;
	printf("this is the value of limit: %d\n", limit2);
	int i = 27;
	limitp = &i; // we really can change the location which limitp points to, 
	// but we can't change the value in that location using limitp
	// *limitp = 43; // this also won't work, and will cause an error
	// error: assignment of read-only location
	printf("this is the value of i: %d\n", *limitp);
	return 0;
}
