#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
	int chave;
	struct no *prox;
}Tno;

int main()
{
	Tno *inicio, *aux;
	
	aux = malloc(sizeof(Tno));
	aux -> chave= 15;
	aux -> prox = NULL;
	inicio = aux;
	
	aux = malloc(sizeof(Tno));
	aux -> chave= 20;
	aux -> prox = NULL;
	
	inicio -> prox = aux;
	
	aux = inicio;
	
	printf("inicio --> %p\n\n", inicio);
	while(aux != NULL)
	{
		printf("[%p] ---> (%d, %p)\n", aux, aux->chave, aux->prox);
		aux = aux -> prox;
	}
}
