
#include<stdio.h>
#include<stdlib.h>

void generate_initializer(char * string)
{
	static char separator=' ';
	printf( "%c %s \n", separator, string);
	separator = ',';
}

int main()
{
	// old style
	printf( "A favorite children's book \
	is 'Muffy Gets It: the hilarious tale of a cat, \
	a boy, and his machine gun'\n" );
	
	// new style
	printf( "A second favorite children's book "
	"is 'Thomas the tank engine and the Naughty Enginedriver who "
	"tied down Thomas's boiler safety valve'\n" );
	char *available_resources[] = 
	{
			"color monitor",
			"big disk",
			"Cray" /* whoa! no comma! */
			"on-line drawing routines",
			"mouse",
			"keyboard",
			"power cables", /* and what's this extra comma? */
	};
	
	// every time after the first time the comma will be printed instead of the space
	generate_initializer("foo");
	generate_initializer("moo");
	generate_initializer("hha");
	return 0;
}
