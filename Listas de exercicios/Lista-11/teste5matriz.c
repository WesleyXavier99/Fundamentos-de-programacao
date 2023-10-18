#include<stdio.h>
#define QUANT 4
int main()
{
	int n,i,j;
	int matriz[QUANT][QUANT];
	
	
	for(i=0;i<QUANT;i++)
	{
		printf("\n");
		for(j=0;j<QUANT;j++)
		{
			printf("Digite o valor da linha [%d] coluna[%d]",i,j);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	for(i=0;i<QUANT;i++)
	{
		printf("\n");
		for(j=0;j<QUANT;j++)
		{
			printf("%d ",matriz[i][j]);
		}
	}
	
	jogar(matriz);
}

void jogar(int matriz[][])
{
	
}
