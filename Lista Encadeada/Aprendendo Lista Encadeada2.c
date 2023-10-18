#include<stdio.h>

struct Lista {
	int valor;
	struct Lista *proximo;
};

struct Lista *procurarValor(struct Lista *pLista,int valor)
{
	while(pLista!= (struct Lista *)0)
	{
		if(pLista->valor == valor)
		{
			return (&pLista);
		}else{
			pLista= pLista->proximo;
		}
	}
	return (struct Lista *)0;
}

void main()
{
	struct Lista *procurarValor(struct Lista *pLista,int valor);
	struct Lista m1,m2,m3;
	struct Lista *resultado,*gancho= &m1;
	int valor;
	
	m1.valor = 10;
	m2.valor = 20;
	m3.valor = 30;
	
	m1.proximo = &m2;
	m2.proximo = &m3;
	m3.proximo = (struct Lista *)0;
	
	printf("Digite o valor a ser pesquisado : \n");
	scanf("%d",&valor);
	
	resultado = procurarValor(gancho,valor);
	
	
	if(resultado == (struct Lista *)0)
	{
		printf("O valor nao foi encontrado");
	}else{
		printf("O valor %d foi encontrado",resultado->valor);
	}
	
	
}
