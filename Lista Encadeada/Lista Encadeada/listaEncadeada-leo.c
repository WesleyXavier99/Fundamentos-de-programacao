/*
   FPR - 2020/1
   Professor Leonardo Vianna

   Aula de 05/10/2020

   Implementa��o de listas encadeadas (simples)
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
	//declara��o de vari�veis
	TLista L = NULL;
	//nova fun��o
	TLista L1= NULL;
	TLista L2 = NULL;
	int opcao, num1, num2, alt;

	do
	{
		//exibindo o menu ao usu�rio
		opcao = menu ();

		switch (opcao)
		{
			//inser��o
			case 1: printf ("Entre com o n�mero a ser inserido: ");
			        scanf ("%d", &num1);

			        if (inserir (&L, num1) == TRUE) //ou apenas inserir (&L, num1)
			        {
			        	printf ("Elemento inserido!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o inserido!\n");
					}
					break;

			//remo��o
			case 2: printf ("Entre com o n�mero a ser removido: ");
			        scanf ("%d", &num1);

			        if (remover (&L, num1) != 0)
			        {
			        	printf ("Elemento removido!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o removido!\n");
					}
					break;

			//alterar
			case 3: printf ("Entre com o n�mero a ser alterado: ");
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
						printf ("ERRO: Elemento n�o alterado!\n");
					}
					break;

			//pesquisar
			case 4: printf ("Entre com o n�mero a ser buscado: ");
			        scanf ("%d", &num1);

			        if (buscar (L, num1))   //ou    if (buscar (L, num1) != NULL)
			        {
			        	printf ("endereco: %d\n",buscar (L, num1));
					}
					else
					{
						printf ("Elemento n�o encontrado!\n");
					}
					break;

			//exibir
			case 5: exibir (L);
			        break;
			        
			//sa�da
			case 6: printf ("Fim do programa!\n");
			        break;
			        
			case 7: printf ("Entre com o n�mero: ");
			        scanf ("%d", &num1);
					CriaDuasLista(L,num1,&L1, &L2);
					exibir(L1);
					exibir(L2);
					break;
					
			//op��o inv�lida
			default: printf ("Op��o inv�lida! Tente novamente.\n");
		}

		system ("pause");
	}
	while (opcao != 6);
}

//implementa��o das fun��es

/*Insere o elemento 'numero' em 'L', retornando TRUE ou FALSE (se conseguiu ou n�o realizar
a inser��o.*/
int inserir (TLista *L, int numero)
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
		aux->prox = *L;

		//Passo 4: fazer o L apontar para o novo n�
		*L = aux;

		return TRUE;
	}
}

/*Remove todas as ocorr�ncias de 'numero' em 'L', retornando a quantidade de remo��es
realizadas.*/
int remover (TLista *L, int numero)
{
	TLista aux1, aux2;
	int cont = 0;

	//tratando a remo��o no in�cio da lista
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
		//posicionando os auxiliares nos dois primeiros n�s
		aux2 = *L;
		aux1 = (*L)->prox; // ou aux1 = aux2->prox;

		//percorrendo toda a lista
		while (aux1)
		{
			//verificando se aux1 est� apontando para o n�mero a ser removido
			if (aux1->valor == numero)
			{
				//mandando o elemento anterior apontar para o pr�ximo do n� que ser� removido
				aux2->prox = aux1->prox;

				//liberando a posi��o de mem�ria // removendo o elemento
				free (aux1);
				cont++;

				//mandando o aux1 apontar para o pr�ximo n�
				aux1 = aux2->prox;
			}
			else
			{
				//seguir para a pr�xima posi��o
				aux2 = aux1;
				aux1 = aux1->prox;
			}
		}
	}

	//retornando a quantidade de remo��oes realizadas
	return cont;
}

/*Altera todas as ocorr�ncias do n�mero 'velho' pelo 'novo' em 'L', retornando a
quantidade de altera��es realizadas.*/
int alterar (TLista L, int velho, int novo)
{
	//declara��o de vari�veis
	TLista i;
	
	
	int cont=0;		//contar� o n�mero de altera��es realizadas

	//i come�a apontando para o primeiro n� da lista L
	i = L;

	//enquanto o ponteiro i n�o chegar ao final da lista (ou seja, n�o chegar a NULL)
	while (i != NULL)  // while (i)
	{
		//se o elemento a ser alterado for encontrado...
		if (i->valor == velho)
		{
			//altera��o sendo feita e contabilizada
			i->valor = novo;
			cont++;
		}

		//ponteiro i segue para o pr�ximo n� da lista
		i = i->prox;
	}

	//retornando a quantidade de altera��es realizadas
	return cont;
}

/*Busca o elemento 'numero' na lista 'L'. Caso ele seja encontrado, � retornado o endere�o
do n� da primeira ocorr�ncia de 'numero'.*/
TLista buscar (TLista L, int numero)
{
	//declara��o de vari�veis
	TLista i;

	//i come�a apontando para o primeiro n� da lista L
	i = L;

	//enquanto o ponteiro i n�o chegar ao final da lista (ou seja, n�o chegar a NULL)
	while (i)  //while (i != NULL)
	{
		//se o elemento 'numero' for encontrado...
		if (i->valor == numero)
		{
			//a sua posi��o � retornada
			return i;
		}

		//ponteiro i segue para o pr�ximo n� da lista
		i = i->prox;
	}

	//Se a execu��o chegou at� aqui, significa que toda a lista foi percorrida e o n�mero
	//n�o foi encontrado
	return NULL;
}

/*Exibe todos os elementos da lista 'L'.*/
void exibir (TLista L)
{
	//declara��o de vari�veis
	TLista i;

	//testando se a lista est� vazia
	if (L == NULL)			//if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos: ");

    	//i come�a apontando para o primeiro n� da lista L
		i = L;

    	//enquanto o ponteiro i n�o chegar ao final da lista (ou seja, n�o chegar a NULL)
		while (i) //while (i != NULL)
		{
			//exibindo o elemento apontado por 'i'
			printf ("%d ", i->valor);

			//ponteiro i segue para o pr�ximo n� da lista
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


/*Exibe um menu de op��es ao usu�rio com as opera��es que podem ser realizadas sobre a
lista. A op��o selecionada pelo usu�rio ser� retornada.*/
int menu ()
{
	int op;

	system ("cls");
	printf ("Menu de op��es:\n\n");
	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n");
	printf ("(4) Buscar\n(5) Exibir\n(6) Sair\n\n");
	printf ("(7) NovaFuncao\n\n");
	printf ("Entre com a sua op��o: ");
	scanf ("%d", &op);

	return op;
}
