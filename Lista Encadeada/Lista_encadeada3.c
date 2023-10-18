#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct Tipo_Lista{
	int cod;
	struct Tipo_Lista *prox;
};

struct Tipo_Lista *Primeiro;
struct Tipo_Lista *Ultimo;

void FLVazia (){
	struct Tipo_Lista *aux = (struct Tipo_Lista*)malloc(sizeof(struct Tipo_Lista));
	Primeiro = aux;
	Ultimo = Primeiro;
}

void insere(int x){
	struct Tipo_Lista *aux = (struct Tipo_Lista*)malloc(sizeof(struct Tipo_Lista));
	aux->cod = x;
	Ultimo->prox = aux;
	Ultimo = Ultimo->prox;
	aux->prox = NULL;
}

void imprime(){
	struct Tipo_Lista *aux = Primeiro->prox;
	while(aux != NULL){
		printf("item = %d\n",aux->cod);
		aux = aux->prox; 
	}
}


int buscar(int x){
	struct Tipo_Lista *aux = Primeiro->prox;
	int flag = 0;
	
	while(aux != NULL)
	{
		if(aux->cod == x)
		{
			printf("Achou o item %d\n",x);
			flag = 1;
			aux = NULL;
		}else{
			aux = aux->prox;
		}
	}
	if(flag == 0)
	{
		printf("O item nao foi encontrado\n");
	}
}

void remover(int x){
	struct Tipo_Lista *aux = Primeiro->prox;
	struct Tipo_Lista *sentinela = Primeiro;
	int flag = 0;
	
	while(aux != NULL)
	{
		if(aux->cod == x)
		{
			printf("Removeu o item %d\n",x);
			sentinela->prox = aux->prox;
			flag = 1;
			aux = NULL;
		}else{
			aux = aux->prox;
			sentinela = sentinela->prox;
		}
	}
	if(flag == 0)
	{
		printf("O item nao foi encontrado\n");
	}
}

void main()
{
	char cp = '2';
	int i,codigo;
	FLVazia();
	
	while(cp != '0')
	{
		printf("Entre com o codigo:");
		scanf("%d",&codigo);
		
		insere(codigo);
		printf("\nContinuar com o cadastro ? 1 = sim 0 = nao\n");
		cp = getch();
	}
	imprime();
	
	printf("Entre com um item para pesquisar:");
	scanf("%d",&codigo);
	buscar(codigo);
	//getch();
	
	printf("item a ser removido:");
	scanf("%d",&codigo);
	remover(codigo);	
	imprime();
	getch();
}
