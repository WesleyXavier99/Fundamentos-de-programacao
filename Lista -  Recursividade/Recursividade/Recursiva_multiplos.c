#include<stdio.h>

int multiplos (int n,int v,int k);

void main()
{
	int n,v,k;
	
	printf("Digite um numero :\n");
	scanf("%i",&n);
	
	printf("Digite um numero :\n");
	scanf("%i",&v);
	
	k=n;
	
	multiplos(n,v,k);
}

int multiplos (int n,int v,int k)
{
	if(n>=v)
	{
		return 1;
	}else{
		printf("%i\t",n);
		multiplos(n+k,v,k);
	}
}
