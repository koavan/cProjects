#include <stdio.h>
#include <string.h>

int countDiff(char *str1, char * str2)
{
	int counter, difference=0;
	for(counter=0;counter<5;counter++)
	{
		if(*(str1+counter)!=*(str2+counter))
		{
			difference+=1;
		}
	}
	return difference;
}

int WordMorpher(char* input1[])
{
	int i;
	int dfrnc=0;
	for(i=0;i<4;i++)
	{
		dfrnc=countDiff(*(input1+i),*(input1+i+1));
		if(dfrnc>1)
			return 0;
	}
	return 1;
}

int main(int argc, char **argv)
{
	char input[5][6]={"TREAT","TREAD","BREAD","BROAD","BROOD"};
	char* index[5];
	int i;
	for(i=0;i<6;i++)
		index[i]=input[i];
	int output = WordMorpher(index);
	printf("-----%d-----",output);
	return 0;
}
