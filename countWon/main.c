#include <stdio.h>

int main(int argc, char **argv)
{
	int wons,i,notes=0;
	int denominations[]={50000,10000,5000,1000,500,100,50,10,5,1};
	scanf("%d",&wons);
	for(;wons>0;i++)
	{
		notes=notes+(wons/denominations[i]);
		wons=wons%denominations[i];
		printf("%d -> %d -> %d\n",denominations[i],notes,wons);
	}
	printf("Minimum no of notes required : %d",notes);
	return 0;
}
