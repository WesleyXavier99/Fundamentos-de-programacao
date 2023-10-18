/*
   FPR - 2020/1
   Professor Leonardo Vianna
   
   Aula de 26/10/2020
   
   Implementação de filas encadeadas
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *numero);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista F = NULL, U = NULL;
	int opcao, num, resp;
	
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//Enfilar
			case 1: printf ("Entre com o número a ser inserido: ");
			        scanf ("%d", &num);
			        
			        if (enfilar (&F, &U, num) == TRUE) //ou apenas enfilar (&P, &U, num)
			        {
			        	printf ("Elemento inserido na fila!\n");
					}
					else
					{
						printf ("ERRO: Elemento não inserido na fila!\n");
					}
					break;
				
			//Desenfilar
			case 2: resp = desenfilar (&F, &U, &num); 
			
					if (resp == TRUE)
			        {
			        	printf ("O valor %d foi removido da fila!\n", num);
					}
					else
					{
						printf ("ERRO: Fila vazia.\n");
					}
					break;
				
			//Primeiro
			case 3: resp = primeiro (F, &num); 
			
					if (resp == TRUE)
			        {
			        	printf ("Primeiro elemento da fila: %d\n", num);
					}
					else
					{
						printf ("ERRO: Fila vazia.\n");
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

/*Insere o elemento 'numero' no final da fila, retornando TRUE ou FALSE (se conseguiu ou não realizar
a inserção).
*/
int enfilar (TLista *F, TLista *U, int numero)
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
		
		//Passo 3: fazer o novo nó apontar para NULL
		aux->prox = NULL;
		
		//Passo 4: fazer o "até então último elemento" apontar para o aux
		if (*U != NULL)
		{
			(*U)->prox = aux;
		
		}
		else
		{
			*F = aux;	
		}
		
		//Passo 5: atualizando o último
		*U = aux;
		
		return TRUE;
	}
}

/*Remove o primeiro elemento da fila (caso exista) e retorna este elemento.*/
int desenfilar (TLista *F, TLista *U, int *numero)
{
	TLista aux;
	
	//verificando se a fila está vazia
	if (*F == NULL)
	{
		return FALSE;
	}
	else
	{
		//aux aponta para o segundo elemento
		aux= (*F)->prox;
		
		//retornando o elemento removido
		*numero = (*F)->valor;
		
		//removendo o primeiro
		free (*F);
		
		//mandando F apontar para o "antigo segundo elemento"
		*F = aux;		
		
		//se a fila ficou vazia, o ponteiro U deve ser atualizado para NULL
		if (*F == NULL)
		{
			*U = NULL;
		}		
		
		return TRUE;
	}
}

/*Retorna o primeiro elemento da fila (caso exista)*/
int primeiro (TLista F, int *numero)
{
	//verificando se a fila está vazia
	if (F == NULL)
	{
		return FALSE;
	}
	else
	{
		*numero = F->valor;

		return TRUE;
	}
}

/*Exibe um menu de opções ao usuário com as operações que podem ser realizadas sobre a 
fila. A opção selecionada pelo usuário será retornada.*/
int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opções:\n\n");
	printf ("(1) Enfilar\n(2) Desenfilar\n(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	printf ("Entre com a sua opção: ");
	scanf ("%d", &op);
	
	return op;
}
