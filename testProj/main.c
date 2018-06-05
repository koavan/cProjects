#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int *ptr,*temp;
	int sum=0,num=0,i;
	printf("Enter the number of subjects : ");
	scanf("%d",&num);
	ptr=(int *) calloc(num,sizeof(int));
	temp=ptr;
	for(i=0;i<num;i++)
	{
		printf("Enter mark %d : ",i);
		scanf("%d",temp);
		temp++;
	}
	temp=ptr;
	for(i=0;i<num;i++)
	{
		printf("Mark %d = %d\n",i,*temp);
		sum+=(*temp);
		temp++;
	}
	printf("Total of all subjects : %d\n",sum);
	return 0;
}
