/*
   FPR - 2020/1
   Professor Leonardo Vianna
   
   Aula de 26/10/2020
   
   Implementação de pilhas encadeadas
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declaração de constantes
#define TRUE 1
#define FALSE 0

//declaração de tipos

//tipo que representa cada nó da lista
typedef struct No {
	int valor;			//campo valor (do tipo que vc desejar (lista de inteiros, float, strings, TAlunos, ...)
	struct No *prox;	//campo prox: armazena o endereço do próximo nó da lista
} TNo;

typedef TNo* TLista;	//TLista é a mesma coisa que *TNo

//declaração dos protótipos das funções
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *numero);
//TLista topo (Tlista P);   -- outra possibilidade de implementação

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista P = NULL;
	int opcao, num, resp;
	
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//Empilhar
			case 1: printf ("Entre com o número a ser inserido: ");
			        scanf ("%d", &num);
			        
			        if (empilhar (&P, num) == TRUE) //ou apenas empilhar (&P, num)
			        {
			        	printf ("Elemento inserido na pilha!\n");
					}
					else
					{
						printf ("ERRO: Elemento não inserido na pilha!\n");
					}
					break;
				
			//Desempilhar
			case 2: resp = desempilhar (&P, &num); 
			
					if (resp == TRUE)
			        {
			        	printf ("O valor %d foi removido da pilha!\n", num);
					}
					else
					{
						printf ("ERRO: Pilha vazia.\n");
					}
					break;
				
			//Topo
			case 3: resp = topo (P, &num); 
			
					if (resp == TRUE)
			        {
			        	printf ("Topo da pilha: %d\n", num);
					}
					else
					{
						printf ("ERRO: Pilha vazia.\n");
					}
					break;
				
			//saída
			case 4: printf ("Fim do programa!\n");
			        break;
			        
			//opção inválida
			default: printf ("Opção inválida! Tente novamente.\n");
		}
		
		system ("pause");
	}
	while (opcao != 4);
}

//implementação das funções

/*Insere o elemento 'numero' no topo da pilha, retornando TRUE ou FALSE (se conseguiu ou não realizar
a inserção).
Por questão de performance, elegemos o início como o topo da pilha.
*/
int empilhar (TLista *P, int numero)
{
	//Passo 1: "tentar" alocar memória para o novo valor
	TLista aux = (TLista) malloc (sizeof(TNo));
	
	//testando se a memória foi alocada
	if (!aux) //(aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenar 'numero' na nova posição
		aux->valor = numero;
		
		//Passo 3: fazer o novo nó apontar para o "antigo primeiro nó da lista"
		aux->prox = *P;
		
		//Passo 4: fazer o L apontar para o novo nó
		*P = aux;
		
		return TRUE;
	}
}

/*Remove o elemento que está no topo da pilha (caso exista) e retorna este elemento.*/
int desempilhar (TLista *P, int *numero)
{
	TLista aux;
	
	//verificando se a pilha está vazia
	if (*P == NULL)
	{
		return FALSE;
	}
	else
	{
		//aux aponta para o segundo elemento
		aux= (*P)->prox;
		
		//retornando o elemento removido
		*numero = (*P)->valor;
		
		//removendo o primeiro
		free (*P);
		
		//mandando P apontar para o "antigo segundo elemento"
		*P = aux;		
		
		return TRUE;
	}
}

/*Retorna o elemento que está no topo da pilha (caso exista)*/
int topo (TLista P, int *numero)
{
	//verificando se a pilha está vazia
	if (P == NULL)
	{
		return FALSE;
	}
	else
	{
		*numero = P->valor;

		return TRUE;
	}
}

/*Exibe um menu de opções ao usuário com as operações que podem ser realizadas sobre a 
pilha. A opção selecionada pelo usuário será retornada.*/
int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opções:\n\n");
	printf ("(1) Empilhar\n(2) Desempilhar\n(3) Topo\n");
	printf ("(4) Sair\n\n");
	printf ("Entre com a sua opção: ");
	scanf ("%d", &op);
	
	return op;
}
