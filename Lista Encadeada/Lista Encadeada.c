#include<stdio.h>
#include<stdlib.h>

typedef struct Lista {
	int elemento;
	struct Lista *prox;
}celula;

void insereH (celula **topo,int elemento)
{
	celula *novo = malloc(sizeof(celula));
	
	novo->elemento = elemento;
	
	if(*topo==NULL)
	{
		novo->prox = NULL;
		*(topo) = novo;
	}else{
		novo->prox = *topo;
		*(topo) = novo; 
	}
}

void exibir(celula *topo)
{
	celula *aux = topo;
	
	if(aux == NULL)
	{
		
	}else{
		do{
			printf("%d-> \n",aux->elemento);
			aux = aux->prox;
		}while(aux != NULL);
	}
}

void main()
{
	celula *topo = NULL;
	insereH(&topo,3);
	insereH(&topo,5);
	insereH(&topo,7);
	exibir(topo);
}
