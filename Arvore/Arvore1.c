//Arvore
#include<stdio.h>
#include<stdlib.h>

struct NoDaArvore
{
	int valor;
	struct NoDaArvore *esquerda;
	struct NoDaArvore *direita;
};

typedef struct NoDaArvore no;

no* inserirNo (int valor,no *esq,no *dir);
void imprimePreOrdem(no* n);
void imprimeEmOrdem(no* n);
void imprimePosOrdem(no* n);

void main()
{
	no *n = inserirNo(15,inserirNo(10,NULL,NULL),inserirNo(50,inserirNo(20,NULL,NULL),NULL));
	
	printf("Pre ordem = ");
	imprimePreOrdem(n);
	printf("\nEm ordem = ");
	imprimeEmOrdem(n);
	printf("\nPos ordem = ");
	imprimePosOrdem(n);
	
}

no* inserirNo (int valor,no *esq,no *dir)
{
	no *n = (no*)malloc(sizeof(no));
	
	if(n==NULL)
	{
		exit(1);
	}else{
		n->valor = valor;
		n->esquerda = esq;
		n->direita = dir;
	}
}

void imprimePreOrdem(no* n)
{
	if(n!=NULL)
	{
		printf("%d ",n->valor);
		imprimePreOrdem(n->esquerda);
		imprimePreOrdem(n->direita);
	}
}

void imprimeEmOrdem (no* n)
{
	if(n!=NULL)
	{
		imprimeEmOrdem(n->esquerda);
		printf("%d ",n->valor);
		imprimeEmOrdem(n->direita);
	}
}

void imprimePosOrdem (no* n)
{
	if(n!=NULL)
	{
		imprimePosOrdem(n->esquerda);
		imprimePosOrdem(n->direita);
		printf("%d ",n->valor);
	}
}

