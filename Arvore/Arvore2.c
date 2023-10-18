//Arvore(mais completo)
#include<stdio.h>
#include<stdlib.h>

struct noArv
{
	int valor;
	struct noArv *esq;
	struct noArv *dir;
};

//renomeando a estrutura
typedef struct noArv Arv;

//prototipo das funçoes
void imprimeArv (Arv *a);
Arv* insere (Arv *a,int valor);
Arv* retira (Arv *r,int valor);

void main()
{
	//criando o ponteiro pra mexer com a estrutura
	Arv *a = NULL;
	
	a = insere(a,10);
	a = insere(a,5);
	a = insere(a,1);
	a = insere(a,2);
	a = insere(a,7);
	a = insere(a,20);
	a = insere(a,33);
	a = insere(a,30);
	
	printf("Saida:\n");
	imprimeArv(a);
	
	a = retira(a,1);
	printf("\nDepois de remover o 1: \n");
	imprimeArv(a);
}


void imprimeArv (Arv *a)//exibição em ordem da esquerda pra direita
{
	if(a!=NULL)
	{
		imprimeArv (a->esq);
		printf("%d ",a->valor);
		imprimeArv (a->dir);
	}
}

Arv* insere (Arv *a,int valor)//inserir valores menores que a raiz pra esquerda e maiores pra direita
{
	if(a==NULL)//inserir o primeiro valor
	{
		a = (Arv*)malloc(sizeof(Arv));
		a->valor = valor;
		a->esq = NULL;
		a->dir = NULL;
	}else if(valor < a->valor)//menores
	{
		a->esq = insere(a->esq,valor);
	}else if(valor > a->valor)//maiores
	{
		a->dir = insere(a->dir,valor);
	}
	return a;
}

Arv* retira (Arv *r,int valor)//remover
{
	if(r==NULL)//se estiver vazia a arvore, nao tem como remover
	{
		return NULL;
	}else if (r->valor > valor)
	{
		r->esq = retira (r->esq,valor);
	}else if (r->valor < valor)
	{
		r->dir = retira (r->dir,valor);
	}else{
			if(r->esq == NULL && r->dir == NULL)
			{
				free(r);
				r = NULL;
			}else if(r->esq == NULL)
			{
				Arv *t = r;
				r = r->dir;
				free(t);
			}else if (r->dir == NULL)
			{
				Arv *t = r;
				r = r->esq;
				free(t);
			}
	}
	return r;
}
/*else {
		if(valor < a->valor)
		{
			a->esq = insere(a->esq,valor);
		}else{
			a->esq = insere(a->dir,valor);
		}
	}*/
