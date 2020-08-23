/*********************************************Authorship*******************************************/
// Deep C secrents

/**************************************preprocessor directives*************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64
#define pop stack[top--]
#define push(s) stack[++top]=s

/******************************************ADT definitions*****************************************/
enum type_tag {
	IDENTIFIER,
	QUALIFIER,
	TYPE 
};
struct token{
	char type;
	char string[MAXTOKENLEN];
};

/***********************************global variables declarations**********************************/
int top = -1;
struct token stack[MAXTOKENS];
struct token this;

/*********************************functions prototypes declarations********************************/
enum type_tag classify_string(void);
void gettoken(void); 
void read_to_first_identifier();
void deal_with_arrays(void);
void deal_with_function_args();
void deal_with_pointers();
void deal_with_declarator();

/*************************************functions implementations************************************/
int main()
{
	// put tokens on stack until we reach identifier
	read_to_first_identifier();
	deal_with_declarator();
	printf("\n");
	return 0;
}

enum type_tag classify_string(void)
// figure out the identifier type
{
	char* s= this.string;
	if(!strcmp(s, "const"))
	{
		strcpy(s, "read_only");
		return QUALIFIER;
	}
	if(!strcmp(s, "volatile")) return QUALIFIER;
	if(!strcmp(s, "void")) return TYPE;
	if(!strcmp(s, "char")) return TYPE;
	if(!strcmp(s, "signed")) return TYPE;
	if(!strcmp(s, "unsigned")) return TYPE;
	if(!strcmp(s, "short")) return TYPE;
	if(!strcmp(s, "int")) return TYPE;
	if(!strcmp(s, "long")) return TYPE;
	if(!strcmp(s, "float")) return TYPE;
	if(!strcmp(s, "double")) return TYPE;
	if(!strcmp(s, "struct")) return TYPE;
	if(!strcmp(s, "union")) return TYPE;
	if(!strcmp(s, "enum")) return TYPE;
	return IDENTIFIER;
}

void gettoken(void) // read next token into "this"
{
	char *p = this.string;
	/* read past any spaces*/
	while((*p = getchar()) == ' ');
	if(isalnum(*p)) // it starts with a-z, 0-9 read in identifier
	{
		while(isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		this.type = classify_string();
		return;
	}
	if(*p == '*')
	{
		strcpy(this.string, "pointer to");
		this.type = '*';
		return;
	}
	this.string[1] = '\0';
	this.type = *p;
	return;
}

// the piece of code that understandeth all parsing
void read_to_first_identifier()
{
	gettoken();
	while(this.type != IDENTIFIER)
	{
		push(this);
		gettoken();
	}
	printf("%s is ", this.string);
	gettoken();
}

void deal_with_arrays(void)
{
	while(this.type == '[')
	{
		printf("array");
		gettoken; // a number or ']'
		if(isdigit(this.string[0]))
		{
			printf("0..%d", atoi(this.string) - 1);
			gettoken(); // read the ']'
		}
		gettoken(); // read past the ']'
		printf("of ");
	}
}

void deal_with_function_args()
{
	while(this.type != ')')
	{
		gettoken();
	}
	gettoken();
	printf("function returning ");
}

void deal_with_pointers()
{
	while(stack[top].type == '*')
	{
		printf("%s ", pop.string);
	}
}

void deal_with_declarator()
{
	// deal with possible array/function following identifier
	switch(this.type)
	{
		case '[': deal_with_arrays(); break;
		case'(' : deal_with_function_args();
	}
	deal_with_pointers();
	// process tokens that we stacked while reading
	while(top >= 0)
	{
		if(stack[top].type == '(')
		{
			pop;
			gettoken(); // read past ')'
			deal_with_declarator();
		}
		else
		{
			printf("%s ", pop.string);
		}
	}
}

