#include <stdio.h>
#include <math.h>

struct Result
{
	int output1;
	int output2[100];
};

struct Result findingDoro(int);

int main(int argc, char **argv)
{
	int billAmnt;
	struct Result output;
	int j=0;
	printf("Enter the bill amount : ");
	scanf("%d",&billAmnt);
	output=findingDoro(billAmnt);
	printf("Currency to be paid : %d\n",output.output1);
	printf("Balance amount denominations\n");
	for(j=0;output.output2[j]!=-999;j++)
		printf("%d ",output.output2[j]);
	return 0;
}

struct Result findingDoro(int input1)
{
	int maxCurrency=0,counter;
	int amntBalance,factor,i=0;
	struct Result out;
	for(counter=0;maxCurrency<=input1;counter++)
	{
		maxCurrency=pow(2,counter);
	}

	amntBalance=maxCurrency-input1;
	out.output1=amntBalance;
	while(amntBalance>0)
	{
		for(counter=0;;counter++)
		{
			if(pow(2,counter)>amntBalance)
				break;
			else
				factor=pow(2,counter);
		}
		out.output2[i]=factor;
		amntBalance=amntBalance-factor;
		i+=1;
	}
	out.output2[i]=-999;
	return out;
}


