#include<stdio.h>

int multiplos (int n,int v,int k);

void main()
{
	int n,v,k=0,t;
	
	printf("Digite a1 :\n");
	scanf("%i",&n);
	
	printf("Digite uma razao :\n");
	scanf("%i",&v);
	
	printf("Digite o termo procurado :\n");
	scanf("%i",&t);
	
	k=t;
	
	multiplos(n,v,k);
}

int multiplos (int n,int v,int k)
{
	if(k==0)
	{
		return 1;
	}else{
		printf("%i\t",n);
		multiplos(n*v,v,k-1);
	}
}
