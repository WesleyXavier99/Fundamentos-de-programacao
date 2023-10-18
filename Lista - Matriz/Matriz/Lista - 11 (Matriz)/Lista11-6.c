/*QUEST�O 06: Considere uma loja que mant�m em uma matriz o total vendido por cada funcion�rio
pelos diversos meses do ano. Ou seja, uma matriz de 12 linhas (uma por m�s) e 10 colunas
(10 funcion�rios). Pede-se o desenvolvimento de uma fun��o para cada item abaixo:

a. Calcular o total vendido durante o ano;
b. Dado um m�s fornecido pelo usu�rio,
determinar o total vendido nesse m�s;
c. Dado um funcion�rio fornecido pelo
usu�rio, determinar o total vendido por ele
durante o ano;
d. Determinar o m�s com maior �ndice de
vendas;
e. Determinar o funcion�rio que menos
vendeu durante o ano.*/
#include<stdio.h>
#define LINHAS 12
#define COLUNAS 10

float TotalVendido(float matriz[LINHAS][COLUNAS]);
float TotalMes(float matriz[LINHAS][COLUNAS],int mes);
float TotalAno(float matriz[LINHAS][COLUNAS],int funcionario);
int MaiorMesVendas(float matriz[LINHAS][COLUNAS]);
int FuncionarioMaisVendas(float matriz[LINHAS][COLUNAS]);

void main()
{
	int i,j,mes,funcionario,mesvendas,funcVendas;
	float matriz[LINHAS][COLUNAS];
	
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			//printf("Digite o total vendido pelo funcionario no mes %d ",j+1);
			matriz[i][j]=1;//rand()%1000+10;
		}
	}
	
	/*for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			//printf("Digite o total vendido pelo funcionario no mes %d ",j+1);
			printf("%.2f\t",matriz[i][j]);
		}
		printf("\n");
	}*/
	
	//a. Calcular o total vendido durante o ano;
	printf("O total vendido foi %.2f \n",TotalVendido(matriz));
	
	//b. Dado um m�s fornecido pelo usu�rio, determinar o total vendido nesse m�s;
	printf("Digite um mes\n");
	scanf("%d",&mes);
	printf("O total no mes %d e : %.2f\n",mes,TotalMes(matriz,mes));
	
	//c. Dado um funcion�rio fornecido pelo usu�rio, determinar o total vendido por ele durante o ano;
	printf("Digite um funcionario\n");
	scanf("%d",&funcionario);
	printf("O funcionario %d vendeu %.2f durante o ano\n",funcionario,TotalAno(matriz,funcionario));
	
	//d. Determinar o m�s com maior �ndice de vendas;
	mesvendas=MaiorMesVendas(matriz);
	printf("O mes com o maior indice de vendas foi o mes %d\n",mesvendas);
	
	//e. Determinar o funcion�rio que menos vendeu durante o ano.
	funcVendas=FuncionarioMaisVendas(matriz);
	printf("O funcionario que menos vendeu durante  o ano foi %d\n",funcVendas);
}

int FuncionarioMaisVendas(float matriz[LINHAS][COLUNAS])
{
	int i,j,menor=100000000;
	float soma=0;
		
	for(i=0;i<COLUNAS;i++)
	{
		for(j=0;j<LINHAS;j++)
		{
			soma+=matriz[i][j];
		}
		if(soma>menor)
		{
			menor=i+1;
		}
		soma=0;
	}
	return menor;
}

int MaiorMesVendas(float matriz[LINHAS][COLUNAS])
{
	int i,j,maior=-100;
	float soma=0;
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			soma+=matriz[i][COLUNAS];
		}
		if(soma>maior)
		{
			maior=i+1;
		}
		soma=0;
	}
	return maior;
}

float TotalAno(float matriz[LINHAS][COLUNAS],int funcionario)
{
	int i,total=0;
	
	for(i=0;i<LINHAS;i++)
	{
		total+=matriz[i][funcionario-1];
	}
	
	return total;
}

float TotalMes(float matriz[LINHAS][COLUNAS],int mes)
{
	int i;
	float total;
	
	for(i=0;i<COLUNAS;i++)
	{
		total+=matriz[mes-1][i];
	}
	
	return total;
	
}

float TotalVendido(float matriz[LINHAS][COLUNAS])
{
	int i,j,total=0;
	
	for(i=0;i<LINHAS;i++)
	{
		for(j=0;j<COLUNAS;j++)
		{
			total+=matriz[i][j];
		}
	}
	
	return total;
}




