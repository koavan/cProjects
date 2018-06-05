#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
 
int main(int argc, char *argv[]) 
{
    int a, b, c;
 
    if (argc < 4 || argc > 5) 
    {
        printf("enter 4 arguments only eg.\"filename arg1 arg2 arg3!!\"");
        return 0;
    }
    
    printf("Total number of arguments : %d \n", argc);
 
    // Converting string type to integer type
    // using function "atoi( argument)" 
    a = atoi(argv[1]); 
    b = atoi(argv[2]);
    c = atoi(argv[3]);
 
    // Checking if all the numbers are positive of not
    if (a < 0 || b < 0 || c < 0) 
    {
        printf("\nEnter only positive values in arguments !!\n");
        return 1;
    }
 
    // Checking if all the numbers are different or not
    if (!(a != b && b != c && a != c)) 
    {
        printf("\nPlease enter three different value \n");
        return 1;
    }
    else
    {
        // Checking condition for "a" to be largest
        if (a > b && a > c)             
            printf("\n%d is largest \n", a);
 
        // Checking condition for "b" to be largest    
        else if (b > c && b > a) 
            printf ("\n%d is largest \n", b);

	// Checking condition for "c" to be largest..
        else if (c > a && c > b) 
            printf("\n%d is largest \n",c);
    }
    return 0;
}


 