
#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int two = 2;
	for(int i = 1; i <= 3; i++)
	{
		switch(i)
		{  // there is a very subtle language feature
			// run this code and find this feature
			// you can solve with "break;"

			// even after solving with break;
			// break; itself will cause another problem
			// if you used break; into nested if expression 
			// and you meant to break the if expression
			// you will instead break the switch case
			// remember AT&T

			case 1: printf("case one\n");
			//case two: printf("case two\n"); // this will not work and will cause an error
			// problems of constants not being constant appears here
			case 2: printf("case two\n");
			case 3: printf("case three\n");
		}
		
	}
	return 0;
}
