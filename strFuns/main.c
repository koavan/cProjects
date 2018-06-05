#include <stdio.h>

int main()
{
	char in[100];
	int len;
	scanf("%s",in);
	
	while(in[++len]!='\0');
	
	printf("Length of %s is %d\n",in,len);
	printf("hello world\n");
	return 0;
}
