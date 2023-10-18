/*
   FPR - 2020/1
   Professor Leonardo Vianna
   
   AV2 - Parte I - 23/11/2020
   
   Questão 01 [1,0 ponto]:
   Considere uma lista L1, do tipo TLista, contendo números inteiros positivos (garante-se que 
   não há valores negativos, nem o número zero em L1).
   Pede-se o desenvolvimento de uma função que, dada a lista L1, gere uma nova lista - L2 -, 
   também do tipo TLista, contendo os elementos de L1, porém ordenados crescentemente e sem 
   repetição.  
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declaração de constantes
#define TRUE 1
#define FALSE 0

//declaração de tipos

void ordenar (int vetor[], int n);

//tipo que representa cada nó da lista
typedef struct No {
	int valor;	
	struct No *prox;
} TNo;

typedef TNo* TLista;

//declaração dos protótipos das funções
int inserir (TLista *L, int numero);
void exibir (TLista L);

void gerarNovaLista (TLista L1, TLista *L2);

int menu ();

//main
void main ()
{
	//declaração de variáveis
	TLista L1 = NULL,
	       L2 = NULL;
	int opcao, num;
	
	do
	{
		//exibindo o menu ao usuário
		opcao = menu ();
		
		switch (opcao)
		{
			//inserção
			case 1: printf ("Entre com o número a ser inserido: ");
			        scanf ("%d", &num);
			        
			        if (inserir (&L1, num))
			        {
			        	printf ("Elemento inserido!\n");
					}
					else
					{
						printf ("ERRO: Elemento não inserido!\n");
					}
					break;
				
			//gerar a nova lista
			case 2: gerarNovaLista (L1, &L2);
			        break;

			//exibir lista original
			case 3: exibir (L1);
			        break;
			        
			//exibir nova lista
			case 4: exibir (L2);
			        break;
			        
			//saída
			case 5: printf ("Fim do programa!\n");
			        break;
			        
			//opção inválida
			default: printf ("Opção inválida! Tente novamente.\n");
		}
		
		system ("pause");
	}
	while (opcao != 5);
}

//implementação das funções

int inserir (TLista *L, int numero)
{
	TLista aux = (TLista) malloc (sizeof(TNo));
	
	if (!aux)
	{
		return FALSE;
	}
	else
	{
		aux->valor = numero;
		
		aux->prox = *L;
		
		*L = aux;
		
		return TRUE;
	}
}

void exibir (TLista L)
{
	TLista i;
	
	if (L == NULL)
	{
		printf ("Lista vazia!\n");
	}
	else
	{
		printf ("Elementos: ");
	
    	i = L;
		
    	while (i)
		{
			printf ("%d ", i->valor);
			
			i = i->prox;
		}
		
		printf ("\n");
	}
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de opções:\n\n");
	printf ("(1) Inserir\n(2) Gerar nova lista\n");
	printf ("(3) Exibir lista original\n(4) Exibir nova lista\n(5) Sair\n\n");
	printf ("Entre com a sua opção: ");
	scanf ("%d", &op);
	
	return op;
}

void gerarNovaLista (TLista L1, TLista *L2)
{
	TLista aux = L1;
	int tam=0,i=0;
	
	//pegar o tamanho da lista
	while(aux){
		tam++;
		aux= aux->prox;
	}
	
	//declarar um vetor auxiliar
	int v[tam];
	
	//preencher o vetor auxiliar com os valores da lista
	aux = L1;
	while(aux&&i<tam){
		v[i] = aux->valor;
		i++;
		aux=aux->prox;
	}
	
	//ordena o vetor auxiliar
	ordenar(v,tam);
	
	//tira a repetição do vetor auxiliar
	tam = removeRepeticao(v,tam);
	
	//passa os valores do vetor auxiliar para a nova lista
	for(i=tam-1;i>-1;i--){
		inserir(L2,v[i]);
	}
}

void ordenar (int vetor[], int n){
    int k, j, aux;

    for (k = 1; k < n;k++){
        for (j = 0; j < n-1;j++){
            if (vetor[j]>vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

int removeRepeticao(int vetor[],int n){
	int i,j,k;
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(vetor[i]==vetor[j]){
				for(k=j;k<n-1;k++){
					vetor[k]=vetor[k+1];
				}
				n--;
				j--;
			}
		}
	}
	return n;
}

