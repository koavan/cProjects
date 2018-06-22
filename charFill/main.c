#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	int length,i;
	char sentence[100], word[30], *start;
	printf("Enter a sentence : \n\t");
	scanf("%[^\n]s",sentence);
	printf("Enter the word to fill : \n\t");
	scanf("%s",word);
	printf("Un-filled string is %s\n",sentence);
	length=strlen(word);
	start=strstr(sentence,word);
	for(i=0;i<length;i++)
	{
		*(start+i)='*';
	}
	printf("Filled string is %s\n",sentence);
	return 0;
}
