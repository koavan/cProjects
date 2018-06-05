#include <stdio.h>

int binomial(int,int);

int main(int argc, char **argv)
{
	int c,r,ncr;
	printf("Enter the values of C and r respectively : ");
	scanf("%d%d",&c,&r);
	ncr = binomial(c,r);
	printf("The binomial value of %d and %d is %d\n",c,r,ncr);
	return 0;
}

int binomial(int input1, int input2)
{
	int nfact=1, rfact=1, nrfact=1, output=0;
	int counter;
	for(counter=1;counter<input1;counter++,nfact*=counter);
	for(counter=1;counter<input2;counter++,rfact*=counter);
	for(counter=1;counter<(input1-input2);counter++,nrfact*=counter);
	output=nfact/(rfact*nrfact);
	return output;
}
