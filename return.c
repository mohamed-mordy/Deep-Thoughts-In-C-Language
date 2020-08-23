
#include<stdio.h>

void foo();

int main()
{
	foo();
	return 0;

}

// Notice the following
void foo()
{
	printf("how are you my frind");
	return;
	printf(" i'm fine, thank you"); // this statement will never printed
}
// "i'm fine, thank you" will never printed. As the function returned before the evaluation of this statement.
