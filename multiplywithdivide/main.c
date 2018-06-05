#include <stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
	float multiplicant,multiplier,temp=0;
	int i;
	printf("Enter multiplicant : ");
	scanf("%f",&multiplicant);
	printf("Enter multiplier : ");
	scanf("%f",&multiplier);
	for(i=0;i<multiplier;i++)
		temp+=multiplicant;
	printf("Method 1\t\tMultiplied Value : %.0f\n",temp);
	
	temp = multiplicant / (1/multiplier);
	printf("Method 2\t\tMultiplied Value : %.0f\n",ceil(temp));
	
	return 0;
}
