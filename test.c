
#include<stdio.h>
#include<stdlib.h>

int main()
{
struct test{
	int arr[100];
};
	
	int i = 0;
	printf("this is sizeof(int) = %d \n", sizeof(int));
	printf("this is sizeof(int*) = %d \n", sizeof(int*));
	printf("this is sizeof(char) = %d \n",sizeof(char));
	printf("this is sizeof(char*) = %d \n",sizeof(char*));
	printf("this is sizeof(long long int) = %d \n",sizeof(long long int));
	printf("this is sizeof(struct test*) = %d \n",sizeof(struct test*));
	printf("this is sizeof(double*) = %d \n",sizeof(double*));

	return 0;
}
