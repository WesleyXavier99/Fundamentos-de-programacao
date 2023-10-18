#include<stdio.h>
#include<stdlib.h>

typedef struct no{
	
	int chave;
	struct no *prox;
	
}Tno;


void exibir(Tno *p);
int inserir_inicio(Tno **p, int num);
int inserir_final(Tno **p, int num);
int remover_final(Tno **p);
int remover_inicio(Tno **p);
Tno* buscar(Tno *p, int num);
int menu();

void main()
{

	Tno *inicio;
	inicio = NULL;
	int escolha, num;
	
	do{
		escolha = menu();
		switch(escolha)
		{
			case 1: exibir(inicio);
					break;
			
			case 2: printf("Entre com o numero a ser inserido: ");
					scanf("%d",&num);
					inserir_inicio(&inicio, num);
					break;
					
			case 3:	printf("Entre com o numero a ser inserido: ");
					scanf("%d",&num);
					inserir_final(&inicio, num);	
					break;
					
			case 4: remover_final(&inicio);
					break;
			
			case 5: remover_inicio(&inicio);
					break;
			
			case 6: printf("Entre com o elemento a ser buscado: ");
					scanf("%d",&num);
					
					printf("%d \n",buscar(inicio,num));
					break;
					
			case 7: printf("FIM!\n");
					break;
					
			default: printf("Opção invalida! Digite novamente: \n");
			
		}
	system("pause");	
	}while(escolha!=7);
}

void exibir(Tno *p)
{
	Tno *aux;
	
	if(p == NULL)
	{
		printf("A lista esta vazia!\n");
	}
	
	else
	{
		aux = p;
		
		while(aux!=NULL)
		{
			printf("%d ",aux->chave);
			aux = aux->prox;
		}
	}
	printf("\n");
}

int inserir_inicio(Tno **p, int num)
{
	Tno *aux;
	aux = malloc(sizeof(Tno));
	
	aux->chave = num;
	aux->prox = NULL;
	
	if(*p == NULL)
	{
		*p=aux;
		//return 0;
	}
	else
	{
		aux->prox = *p;
		*p = aux;
	}
	
	return 1;
}

int inserir_final(Tno **p, int num)
{
	Tno *aux1, *aux2 = NULL;
	aux1 = malloc(sizeof(Tno));
	
	aux1->chave = num;
	aux1->prox = NULL;
	
	if(*p == NULL)
	{
		*p=aux1;
	}
	else
	{
		aux2=*p;
		
		while(aux2->prox != NULL)
		{
			aux2 = aux2->prox;	
			
		}
		aux2->prox = aux1;
		aux1->prox = NULL;	
	}
	
	return 1;
}

int remover_final(Tno **p)
{
	Tno *aux1, *aux2;

	if(*p != NULL)
	{
		aux2 = *p;
		aux1 = (*p)->prox;
		
		while((aux1->prox) != NULL)
		{
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		free(aux1);
		aux2->prox = NULL;
		
	}
	return 1;
}

int remover_inicio(Tno **p)
{
	Tno *aux1;
	
	if(*p != NULL)
	{
		aux1 = (*p)->prox;
		free(*p);
		*p=aux1;
	}
	return 1;
	
}

Tno* buscar(Tno *p, int num)
{
	Tno *aux;
	aux = p;
	
	while(aux != NULL)
	{
		if(aux->chave == num);
		{
			return aux;
		}
		
		aux = aux->prox;
		
	}
	
	return NULL;
}
	
int menu()
{
	int op;
	
	system("cls");
	printf("Menu de opcoes:\n\n");
	printf("1 - EXIBIR\n2 - INSERIR NO INICIO\n3 - INSERIR NO FINAL\n4 - REMOVER NO FINAL\n5 - REMOVER NO INICIO\n6 - BUSCAR\n7 - SAIR\n");
	printf("Entre com a sua escolha: ");
	scanf("%d",&op);
	
	return (op);
}
