#include<stdio.h>
#include<ctype.h>
int main()
{
	int i,idpointer=0,oppointer=0,chpointer=0;
	char a[100],id[100],op[100],ch[100];
	printf("Enter a string");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(isdigit(a[i]))
		{
			ch[chpointer]=a[i];
			chpointer++;
		}
		else if(isalpha(a[i]))
		{
			id[idpointer]=a[i];
			idpointer++;
		}
		else
		{
			op[oppointer]=a[i];
			oppointer++;
		}	
	}
	printf("identifiers;");
	for(i=0;i<idpointer;i++)
	{
		printf("%c",id[i]);
	}
	printf("\n constants:");
	for(i=0;i<chpointer;i++)
	{
		printf("%c,",ch[i]);
		}	
		printf("\n operators:");
		for(i=0;i<oppointer;i++)
		{
			printf("%c",op[i]);
		}
	}
