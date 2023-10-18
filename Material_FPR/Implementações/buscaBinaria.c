#include <stdio.h>

int buscaBinariaAux (int vetor[], int inf, int sup, int x)
{
	int meio;
	
	if (inf > sup)	 //caso base 1
	{
		return -1;   //elemento não existe no vetor
	}
	else
	{
		meio = (inf + sup)/2;
		
		if (vetor[meio] == x) //caso base 2 - elemento encontrado
		{
			return meio;
		}
		else
		{
			if (vetor[meio] > x)   //caso exista no vetor, só pode estar no subvetor da esquerda
			{
				return buscaBinariaAux (vetor, inf, meio-1, x);
			}
			else   //vetor[meio] < x
			//caso exista no vetor, só pode estar no subvetor da direita
			{
				return buscaBinariaAux (vetor, meio+1, sup, x);
			}
		}	
	}	
}


int buscaBinaria (int vetor[], int tamanho, int x)
{
	return buscaBinariaAux (vetor, 0, tamanho-1, x);
}


void main ()
{
	int v[10] = {1,4,6,8,10,14,17,20,25,27};
	int num, resp;
	
	printf ("entre com o numero a ser pesquisado: ");
	scanf ("%d", &num);
	
	resp = buscaBinaria (v,10,num);
	
	if (resp < 0)
	{
		printf ("O valor %d não se encontra no vetor", num);
	}
	else
	{
		printf ("O valor %d foi encontrado na posicao %d", num, resp);
	}
}
