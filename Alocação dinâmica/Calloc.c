#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i;
	int *p;
	p = (int *) calloc(5,sizeof(int));
	
//	*p = 1;
//	*(p+1)=10;
//	*(p+2)=20;
//	*(p+3)=30;p
//	*(p+4)=40;
	
	for(i=0;i<5;i++)
	{
		printf("endereco de p%i = %p | valor de p%i = %i\n",i,(p+1),i,*(p+i));
	}
	
}
