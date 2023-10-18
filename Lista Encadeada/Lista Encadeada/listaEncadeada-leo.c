/*
   FPR - 2020/1
   Professor Leonardo Vianna

   Aula de 05/10/2020

   Implementação de listas encadeadas (simples)
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
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
TLista buscar (TLista L, int numero);
void exibir (TLista L);
int CriaDuasLista(TLista L, int n,TLista *l1, TLista *l2);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista L = NULL;
	//nova função
	TLista L1= NULL;
	TLista L2 = NULL;
	int opcao, num1, num2, alt;

	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();

		switch (opcao)
		{
			//inserção
			case 1: printf ("Entre com o número a ser inserido: ");
			        scanf ("%d", &num1);

			        if (inserir (&L, num1) == TRUE) //ou apenas inserir (&L, num1)
			        {
			        	printf ("Elemento inserido!\n");
					}
					else
					{
						printf ("ERRO: Elemento não inserido!\n");
					}
					break;

			//remoção
			case 2: printf ("Entre com o número a ser removido: ");
			        scanf ("%d", &num1);

			        if (remover (&L, num1) != 0)
			        {
			        	printf ("Elemento removido!\n");
					}
					else
					{
						printf ("ERRO: Elemento não removido!\n");
					}
					break;

			//alterar
			case 3: printf ("Entre com o número a ser alterado: ");
			        scanf ("%d", &num1);

			        printf ("Entre com o novo elemento: ");
			        scanf ("%d", &num2);

			        alt = alterar (L, num1, num2);
			        if (alt != 0)
			        {
			        	printf ("%d ocorrencias de %d alteradas!\n", alt, num1);
					}
					else
					{
						printf ("ERRO: Elemento não alterado!\n");
					}
					break;

			//pesquisar
			case 4: printf ("Entre com o número a ser buscado: ");
			        scanf ("%d", &num1);

			        if (buscar (L, num1))   //ou    if (buscar (L, num1) != NULL)
			        {
			        	printf ("endereco: %d\n",buscar (L, num1));
					}
					else
					{
						printf ("Elemento não encontrado!\n");
					}
					break;

			//exibir
			case 5: exibir (L);
			        break;
			        
			//saída
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			case 7: printf ("Entre com o número: ");
			        scanf ("%d", &num1);
					CriaDuasLista(L,num1,&L1, &L2);
					exibir(L1);
					exibir(L2);
					break;
					
			//opção inválida
			default: printf ("Opção inválida! Tente novamente.\n");
		}

		system ("pause");
	}
	while (opcao != 6);
}

//implementação das funções

/*Insere o elemento 'numero' em 'L', retornando TRUE ou FALSE (se conseguiu ou não realizar
a inserção.*/
int inserir (TLista *L, int numero)
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
		aux->prox = *L;

		//Passo 4: fazer o L apontar para o novo nó
		*L = aux;

		return TRUE;
	}
}

/*Remove todas as ocorrências de 'numero' em 'L', retornando a quantidade de remoções
realizadas.*/
int remover (TLista *L, int numero)
{
	TLista aux1, aux2;
	int cont = 0;

	//tratando a remoção no início da lista
	//while ((*L != NULL) && ((*L)->valor == numero))
	while ((*L) && ((*L)->valor == numero))
	{
		//aux aponta para o segundo elemento
		aux1 = (*L)->prox;

		//removendo o primeiro
		free (*L);
		cont++;

		//mandando L apontar para o "antigo segundo elemento"
		*L = aux1;
	}

	//testando se ainda existem elementos na lista
	if (*L)
	{
		//posicionando os auxiliares nos dois primeiros nós
		aux2 = *L;
		aux1 = (*L)->prox; // ou aux1 = aux2->prox;

		//percorrendo toda a lista
		while (aux1)
		{
			//verificando se aux1 está apontando para o número a ser removido
			if (aux1->valor == numero)
			{
				//mandando o elemento anterior apontar para o próximo do nó que será removido
				aux2->prox = aux1->prox;

				//liberando a posição de memória // removendo o elemento
				free (aux1);
				cont++;

				//mandando o aux1 apontar para o próximo nó
				aux1 = aux2->prox;
			}
			else
			{
				//seguir para a próxima posição
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}

	//retornando a quantidade de remoçãoes realizadas
	return cont;
}

/*Altera todas as ocorrências do número 'velho' pelo 'novo' em 'L', retornando a
quantidade de alterações realizadas.*/
int alterar (TLista L, int velho, int novo)
{
	//declaração de variáveis
	TLista i;
	
	
	int cont=0;		//contará o número de alterações realizadas

	//i começa apontando para o primeiro nó da lista L
	i = L;

	//enquanto o ponteiro i não chegar ao final da lista (ou seja, não chegar a NULL)
	while (i != NULL)  // while (i)
	{
		//se o elemento a ser alterado for encontrado...
		if (i->valor == velho)
		{
			//alteração sendo feita e contabilizada
			i->valor = novo;
			cont++;
		}

		//ponteiro i segue para o próximo nó da lista
		i = i->prox;
	}

	//retornando a quantidade de alterações realizadas
	return cont;
}

/*Busca o elemento 'numero' na lista 'L'. Caso ele seja encontrado, é retornado o endereço
do nó da primeira ocorrência de 'numero'.*/
TLista buscar (TLista L, int numero)
{
	//declaração de variáveis
	TLista i;

	//i começa apontando para o primeiro nó da lista L
	i = L;

	//enquanto o ponteiro i não chegar ao final da lista (ou seja, não chegar a NULL)
	while (i)  //while (i != NULL)
	{
		//se o elemento 'numero' for encontrado...
		if (i->valor == numero)
		{
			//a sua posição é retornada
			return i;
		}

		//ponteiro i segue para o próximo nó da lista
		i = i->prox;
	}

	//Se a execução chegou até aqui, significa que toda a lista foi percorrida e o número
	//não foi encontrado
	return NULL;
}

/*Exibe todos os elementos da lista 'L'.*/
void exibir (TLista L)
{
	//declaração de variáveis
	TLista i;

	//testando se a lista está vazia
	if (L == NULL)			//if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos: ");

    	//i começa apontando para o primeiro nó da lista L
		i = L;

    	//enquanto o ponteiro i não chegar ao final da lista (ou seja, não chegar a NULL)
		while (i) //while (i != NULL)
		{
			//exibindo o elemento apontado por 'i'
			printf ("%d ", i->valor);

			//ponteiro i segue para o próximo nó da lista
			i = i->prox;
		}

		printf ("\n");
	}
}

int CriaDuasLista(TLista L, int n,TLista *L1, TLista *L2){
	TLista i = L;
	
	while(i){
		if(i->valor < n){
			//insere l1
			inserir(L1,i->valor);
		}else{
			//insere l2
			inserir(L2,i->valor);
		}
		
	i = i->prox;
	}
//	exibir(L1);
//	exibir(L2);
}


/*Exibe um menu de opções ao usuário com as operações que podem ser realizadas sobre a
lista. A opção selecionada pelo usuário será retornada.*/
int menu ()
{
	int op;

	system ("cls");
	printf ("Menu de opções:\n\n");
	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n");
	printf ("(4) Buscar\n(5) Exibir\n(6) Sair\n\n");
	printf ("(7) NovaFuncao\n\n");
	printf ("Entre com a sua opção: ");
	scanf ("%d", &op);

	return op;
}
