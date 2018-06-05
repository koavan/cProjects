#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int stdnt_count=0,sub_count=0,sum=0;
	float avg=0;
	int i,j;
	int **student,*temp;
	
	printf("Enter the number of students :");
	scanf("%d",&stdnt_count);
	printf("Enter the number of subjects :");
	scanf("%d",&sub_count);
	
	student= (int **) malloc(sizeof(int**)*stdnt_count);
	
	for(i=0;i<stdnt_count;i++)
	{
		*(student+i)=(int *) malloc(sizeof(int) * sub_count);
	}
	
	for(i=0;i<stdnt_count;i++)
	{
		temp=*(student+i);
		printf("Enter Student %d marks : \n",i);
		for(j=0;j<sub_count;j++)
		{
			printf("Enter mark %d : ",j);
			scanf("%d",temp);
			temp++;
		}
	}
	
	for(i=0;i<stdnt_count;i++)
	{
		temp=*(student+i);
		sum=0;
		avg=0;
		for(j=0;j<sub_count;j++)
		{
			sum+=(*temp);
			temp++;
		}
		avg=(float)sum/(float)sub_count;
		printf("\nStudent %d\n\tTotal : %d\n\tAverage : %f\n",i,sum,avg);
	}
	
	return 0;
}
