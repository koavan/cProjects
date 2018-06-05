#include <stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	char input[100],temp;
	int i,j,length;
	scanf("%s",input);
	length=strlen(input);
	j=length;
	for(i=0;i<length/2;)
	{
		if(isalpha(input[i]) && isalpha(input[j]))
		{
			temp=input[i];
			input[i]=input[j];
			input[j]=temp;
			
			++i;
			--j;
		}
		else if(isalpha(input[i]))
		{
			--j;
		}
		else if(isalpha(input[j]))
		{
			++i;
		}
		else
		{
			++i;
			--j;
		}
	}
	printf("Reversed String is %s\n",input);
	return 0;
}
