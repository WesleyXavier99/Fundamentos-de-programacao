#include<stdio.h>//REMOVER REPETICOES
#define CAP 10
void main ()
{
	int v[CAP]={2,3,10,5,2,3,2,8,2,1};
	int tam=CAP,i;
	
	remover(v,&tam);
	
}

int remover(int v[],int *tam)
{
	int i,j,k,aux[CAP],tamaux=CAP,cont=0;
	
	//passando os valores do vetor inicial para o vetor auxiliar.
	for(i=0;i<tamaux;i++)
	{
		aux[i]=v[i];
	}
	
	//removendo a repeticao do vetor inicial 
	for(i=0;i<*tam;i++)
	{
		for(j=i+1;j<*tam;)
		{
			
			if(v[j]==v[i])
			{
				for(k=j;k<*tam;k++)
				{
					v[k]=v[k+1];
				}
				(*tam)--;
			}else{
				j++;
			}
		}
	}
	
	printf("vetor auxiliar => ");
	exibir(aux,&tamaux);
	printf("vetor inicial => ");
	exibir(v,tam);
	
	//comparando o vetor inicial(ja com as remocoes de repeticao feitas) com o vetor auxiliar pra achar a quantidade de vezes q esses numeros aparecem no vetor q o usuario deu 
	for(i=0;i<*tam;i++)
	{
		for(j=0;j<tamaux;j++)
		{
			if(v[i]==aux[j])
			{
				cont++;
			}
		}
		printf("%d : %d vezes\n",v[i],cont);
		cont=0;
	}
	//restaurando o vetor inicial pra voltar como foi mandado pra funcao
	(*tam)=tamaux;
	for(i=0;i<tamaux;i++)
	{
		v[i]=aux[i];
		
	}
	
	printf("vetor auxiliar => ");
	exibir(aux,&tamaux);
	printf("vetor inicial  => ");
	exibir(v,tam);
}



void exibir(int v[],int *tam)
{
	int i;
	for(i=0;i<*tam;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}
