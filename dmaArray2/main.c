#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int rows,cols;
	int **base;
	int i,j;
	rows=cols=0;
	printf("Enter no of rows : ");
	scanf("%d",&rows);
	printf("Enter no of columns : ");
	scanf("%d",&cols);
	
	base = (int**)malloc(rows * sizeof(int *));
	
	for(i=0;i<rows;i++)
	{
		*(base+i) = (int *)malloc(cols * sizeof(int));
	}
	
	printf("Enter array elements : \n");
	for(i=0;i<rows;i++)
	{
		printf("\tRow %d\n",i);
		for(j=0;j<cols;j++)
		{
			scanf("%d",(*(base+i)+j));
		}
	}
	
	printf("Entered Matrix is \n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%d ",*(*(base+i)+j));
		}
		printf("\n");
	}	
	return 0;
}
