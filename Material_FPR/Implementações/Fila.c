/*
   FPR - 2020/1
   Professor Leonardo Vianna
   
   Aula de 26/10/2020
   
   Implementa��o de filas encadeadas
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
int enfilar (TLista *F, TLista *U, int numero);
int desenfilar (TLista *F, TLista *U, int *numero);
int primeiro (TLista F, int *numero);

int menu ();

//main
void main ()
{
	//declara��o de vari�veis
	TLista F = NULL, U = NULL;
	int opcao, num, resp;
	
	do
	{
		//exibindo o menu ao usu�rio
		opcao = menu ();
		
		switch (opcao)
		{
			//Enfilar
			case 1: printf ("Entre com o n�mero a ser inserido: ");
			        scanf ("%d", &num);
			        
			        if (enfilar (&F, &U, num) == TRUE) //ou apenas enfilar (&P, &U, num)
			        {
			        	printf ("Elemento inserido na fila!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o inserido na fila!\n");
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

/*Insere o elemento 'numero' no final da fila, retornando TRUE ou FALSE (se conseguiu ou n�o realizar
a inser��o).
*/
int enfilar (TLista *F, TLista *U, int numero)
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
		
		//Passo 3: fazer o novo n� apontar para NULL
		aux->prox = NULL;
		
		//Passo 4: fazer o "at� ent�o �ltimo elemento" apontar para o aux
		if (*U != NULL)
		{
			(*U)->prox = aux;
		
		}
		else
		{
			*F = aux;	
		}
		
		//Passo 5: atualizando o �ltimo
		*U = aux;
		
		return TRUE;
	}
}

/*Remove o primeiro elemento da fila (caso exista) e retorna este elemento.*/
int desenfilar (TLista *F, TLista *U, int *numero)
{
	TLista aux;
	
	//verificando se a fila est� vazia
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
	//verificando se a fila est� vazia
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

/*Exibe um menu de op��es ao usu�rio com as opera��es que podem ser realizadas sobre a 
fila. A op��o selecionada pelo usu�rio ser� retornada.*/
int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de op��es:\n\n");
	printf ("(1) Enfilar\n(2) Desenfilar\n(3) Primeiro\n");
	printf ("(4) Sair\n\n");
	printf ("Entre com a sua op��o: ");
	scanf ("%d", &op);
	
	return op;
}
