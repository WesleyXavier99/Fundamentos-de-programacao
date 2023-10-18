#include<stdio.h>

void testeVariavel(int x);
void testePonteiro(int *pX);

void main()
{
	int teste = 1;
	int *pTeste= &teste;
	
	testeVariavel(teste);
	testePonteiro(pTeste);
	
	printf("%d\n",teste);
	printf("%d",*pTeste);
	
}

void testeVariavel (int x)
{
	++x;
}

void testePonteiro(int *pX)
{
	++*pX;
}
