#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct searchResult getNumber(char *, int);
struct resultSet getNumbers(char *);

struct searchResult
{
	int offset;
	int value;
};

struct resultSet
{
	int valueSet[100];
	int resultSize;
};

int main(int argc, char **argv)
{
	char input[100];
	int i;
	struct resultSet result;
	scanf("%[^\n]s",input);
	result = getNumbers(input);
	printf("Extracted numbers are...\n");
	for(i=0;i<result.resultSize;i++)
	{
		printf("%d\t",result.valueSet[i]);
	}
	printf("\n");
	return 0;
}

struct searchResult getNumber(char *ptr, int pos)
{
	int i, value=0,flag=0;
	char x;
	struct searchResult res;
	for(i=pos; ;i++)
	{
		x=*(ptr+i);
		if(isdigit(x))
		{
			value=(value*10)+(x-48);
			flag=1;
		}
		else if(flag==1)
		{
			break;
		}
	}
	res.offset=i;
	res.value=value;
	return res;
}

struct resultSet getNumbers(char *ptr)
{
	struct searchResult t;
	struct resultSet output;
	output.resultSize=0;
	int off=-1,len,i=0;
	len=strlen(ptr);
	do
	{
		t=getNumber(ptr,off+1);
		//printf("%d\t",t.value);
		output.valueSet[i++]=t.value;
		output.resultSize=i;
		off=t.offset;
	}while(off<len);
	return output;
}