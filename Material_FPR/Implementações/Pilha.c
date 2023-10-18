/*
   FPR - 2020/1
   Professor Leonardo Vianna
   
   Aula de 26/10/2020
   
   Implementa��o de pilhas encadeadas
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declara��o de constantes
#define TRUE 1
#define FALSE 0

//declara��o de tipos

//tipo que representa cada n� da lista
typedef struct No {
	int valor;			//campo valor (do tipo que vc desejar (lista de inteiros, float, strings, TAlunos, ...)
	struct No *prox;	//campo prox: armazena o endere�o do pr�ximo n� da lista
} TNo;

typedef TNo* TLista;	//TLista � a mesma coisa que *TNo

//declara��o dos prot�tipos das fun��es
int empilhar (TLista *P, int numero);
int desempilhar (TLista *P, int *numero);
int topo (TLista P, int *numero);
//TLista topo (Tlista P);   -- outra possibilidade de implementa��o

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista P = NULL;
	int opcao, num, resp;
	
	do
	{
		//exibindo o menu ao usu�rio
		opcao = menu ();
		
		switch (opcao)
		{
			//Empilhar
			case 1: printf ("Entre com o n�mero a ser inserido: ");
			        scanf ("%d", &num);
			        
			        if (empilhar (&P, num) == TRUE) //ou apenas empilhar (&P, num)
			        {
			        	printf ("Elemento inserido na pilha!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o inserido na pilha!\n");
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
				
			//sa�da
			case 4: printf ("Fim do programa!\n");
			        break;
			        
			//op��o inv�lida
			default: printf ("Op��o inv�lida! Tente novamente.\n");
		}
		
		system ("pause");
	}
	while (opcao != 4);
}

//implementa��o das fun��es

/*Insere o elemento 'numero' no topo da pilha, retornando TRUE ou FALSE (se conseguiu ou n�o realizar
a inser��o).
Por quest�o de performance, elegemos o in�cio como o topo da pilha.
*/
int empilhar (TLista *P, int numero)
{
	//Passo 1: "tentar" alocar mem�ria para o novo valor
	TLista aux = (TLista) malloc (sizeof(TNo));
	
	//testando se a mem�ria foi alocada
	if (!aux) //(aux == NULL)
	{
		return FALSE;
	}
	else
	{
		//Passo 2: armazenar 'numero' na nova posi��o
		aux->valor = numero;
		
		//Passo 3: fazer o novo n� apontar para o "antigo primeiro n� da lista"
		aux->prox = *P;
		
		//Passo 4: fazer o L apontar para o novo n�
		*P = aux;
		
		return TRUE;
	}
}

/*Remove o elemento que est� no topo da pilha (caso exista) e retorna este elemento.*/
int desempilhar (TLista *P, int *numero)
{
	TLista aux;
	
	//verificando se a pilha est� vazia
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

/*Retorna o elemento que est� no topo da pilha (caso exista)*/
int topo (TLista P, int *numero)
{
	//verificando se a pilha est� vazia
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

/*Exibe um menu de op��es ao usu�rio com as opera��es que podem ser realizadas sobre a 
pilha. A op��o selecionada pelo usu�rio ser� retornada.*/
int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de op��es:\n\n");
	printf ("(1) Empilhar\n(2) Desempilhar\n(3) Topo\n");
	printf ("(4) Sair\n\n");
	printf ("Entre com a sua op��o: ");
	scanf ("%d", &op);
	
	return op;
}
