#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int count, *base;
	int i,sum=0;
	printf("Enter the number of items : ");
	scanf("%d",&count);
	base = (int *)malloc(count * sizeof(int));
	for(i=0;i<count*sizeof(int);i+=4)
	{
		scanf("%d",base+i);
	}
	
	for(i=0;i<count*sizeof(int);i+=4)
	{
		sum= sum + *(base+i);
	}
	printf("Sum of products : %d\n",sum);
	return 0;
}
