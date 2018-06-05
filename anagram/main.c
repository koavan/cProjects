
#include <stdio.h>
#include <string.h>
 
void bubbleSort(char*, int);
 
int AnagramTest(char *str1, char *str2)
{
    int n1 = strlen(str1);
    int n2 = strlen(str2);
 
    if (n1 != n2)
      return 0;
 
    bubbleSort(str1, n1);
    bubbleSort(str2, n2);
 
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return 0;
 
    return 1;
}
 
void exchange(char *a, char *b)
{
    char temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
 
void bubbleSort(char *s1, int l)
{
    int i,j;
	for(i=0;i<l;i++)
	{
		for(j=i+1;j<l;j++)
		{
			if(*(s1+i)>*(s1+j))
			{
				exchange(s1+i,s1+j);
			}
		}
	}
}
 
/* Driver program to test to print printDups*/
int main()
{
    char str1[100], str2[100];
	printf("Enter string 1 : ");
	scanf("%s",str1);
	printf("Enter string 2 : ");
	scanf("%s",str2);
	
    if (AnagramTest(str1, str2))
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");
 
	printf("After Sorting\nstr1 = %s\nstr2 = %s\n",str1,str2);
 
    return 0;
}