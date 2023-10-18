#include<stdio.h>
#include<stdlib.h>

void main()
{
	int *p = (int *) malloc(sizeof(int));//malloc recebe um inteiro sempre positivo. ex: sizeof(double)/8
	
	*p=1000;
	
	printf("%i",*p);
}
