//-----------------------------------------------------------------------------
//  FAETERJ-Rio
//  Fundamentos de Programação - FPR - 2020/1
//  Professor Leonardo Vianna
//
//  Listas Duplamente Encadeadas
//
//  ==> A atividade consiste em completar a implementação, desenvolvendo as funções
//      de remoção e a que exibe a lista na ordem inversa.
//
//  Pode ser feita em dupla ou individualmente.
//  Data limite de entrega: 29/11/2020
//
//-----------------------------------------------------------------------------

//Importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Definição de constantes
#define TRUE 1
#define FALSE 0

//Definição de Tipos
typedef struct No
{
   int valor;
   struct No *prox, *ant;
} TNo;
/*A diferença para a lista encadeada simples consiste na inclusão de um ponteiro que
permite cada nó apontar para o seu elemento anterior (e não apenas para o próximo)*/

typedef TNo* TLista;

//Protótipos das funções
int inserir (TLista *L, TLista *U, int num);	//U aponta para o último elemento da LDE
int remover (TLista *L, TLista *U, int num);
int alterar (TLista L, int velho, int novo);
TLista pesquisar (TLista L, int num);
void exibir (TLista L);
void exibirAoContrario (TLista U);

int menu ();

//Função 'main'
int main ()
{
	//Definição de variáveis
	TLista L = NULL,	//A lista que armazenará os elementos
	       U = NULL;	//ponteiro para o último elemento da lista
	int num1, num2, op;
	TLista pos;
	
	//um menu será exibido ao usuário até que ele opte pela saída do sistema
	do
	{
		system ("cls");
      	op = menu ();
      
      	switch (op)
      	{
      		//Inserir
			case 1: printf ("Entre com o número: ");
                    scanf ("%d", &num1);
					
					if (inserir (&L, &U, num1))
					{
						printf ("Inserção realizada!\n");
					}
					else
					{
						printf ("ERRO: Inserção não realizada!\n");
					}
                 	break;

         	//Remover
         	case 2: printf ("Entre com o número: ");
                 	scanf ("%d", &num1);
                 
                 	if (remover (&L, &U, num1))
                 	{
                    	printf ("Remoção realizada!\n");
                 	}
                 	else
                 	{
                    	printf ("ERRO: Remoção não realizada!\n");
                 	}
                 	break;
					 
			//Alterar
         	case 3: printf ("Entre com o número a ser alterado: ");
                 	scanf ("%d", &num1);
                 
                 	printf ("Entre com o novo número: ");
                 	scanf ("%d", &num2);
                 
                 	if (alterar (L, num1, num2))
                 	{
                    	printf ("Alteração realizada!\n");
                 	}
                 	else
                 	{
                    	printf ("ERRO: Alteração não realizada!\n");
                 	}
                 	break;

         	//Pesquisar
         	case 4: printf ("Entre com o número a ser pesquisado: ");
                 	scanf ("%d", &num1);
              
                 	pos = pesquisar (L, num1);
                 	if (pos != NULL)
					{
                    	printf ("O número %d foi encontrado na lista!\n", num1);
                 	}
                 	else
                 	{
                    	printf ("ERRO: O número %d não se encontra na lista!\n", num1);
                 	}
                 	break;

         	//Exibir na ordem natural
         	case 5: exibir (L);
                 	break;

         	//Exibir na ordem inversa
         	case 6: exibirAoContrario (U);
                 	break;
                 
         	//Fim do programa
         	case 7: printf ("Fim do programa!\n");
                 	break;
                 
         	//Opção inválida
         	default:printf ("Opção inválida!\nTente novamente!\n");
      }
      
      system ("pause");
   }
   while (op != 7);
}

//Implementação das funções
int menu ()
{
	int opcao;
   
   	printf ("Menu de opcoes:\n\n");
   	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n");
   	printf ("(4) Pesquisar\n(5) Exibir na ordem natural\n");
   	printf ("(6) Exibir na prdem inversa\n(7) Sair\n\n");
   	printf ("Entre com a opcao: ");
   	scanf ("%d", &opcao);
   
   	return opcao;
}

//Insere um novo elemento no início da lista
int inserir (TLista *L, TLista *U, int num)
{
	TLista aux = (TLista) malloc (sizeof(TNo));
   
   	if (!aux)  //Sem memória disponível
   	{
    	return FALSE;
   	}
   	else
   	{
   		//preenchendo os campos do novo nó
   		aux->valor = num;
      	aux->prox = *L;
      	aux->ant = NULL;
      
      	//se a lista nãpo estiver vazia
	  	if (*L)
      	{
         	(*L)->ant = aux;
      	}
      	else
      	{
      		*U = aux;
	  	}
      
      	*L = aux;
      
      	return TRUE;
   	}
}

//Remove todas as ocorrencias de determinado valor na lista.
//Retorna a quantidade de remoções realizadas.
int remover (TLista *L, TLista *U, int num)
{
	TLista aux1; //= (*L);
	TLista aux2; //= aux1->prox;
	TLista aux3; //= aux2->prox;
	int cont=0;
	
	//verificando se a lista tá vazia
	if(!(*L)){
		printf("\nentrou0\n");
		return 0;
	}
	
	//verificando se for o unico elemento da lista
		while(((*L)->valor==num)&&((*L)->ant==NULL)){//&&((*L)->prox==NULL)
			aux1=(*L)->prox;
			aux2=(*L)->prox;
			free(*L);
			*L=aux1;
			//printf("\nl->valor = %d\n",(*L)->valor);
			cont++;
		}
	
//	//tratando a remoção no início da lista
//	//while ((*L != NULL) && ((*L)->valor == numero))
//	while ((*L) && ((*L)->valor == numero))
//	{
//		//aux aponta para o segundo elemento
//		aux1 = (*L)->prox;
//
//		//removendo o primeiro
//		free (*L);
//		cont++;
//
//		//mandando L apontar para o "antigo segundo elemento"
//		*L = aux1;
//	}
	
//	while(aux1){
//		else{
//			//verificando se for o primeiro da lista
//			if(aux1->ant==NULL&&aux1->valor==num){
//				(*L)=(*L)->prox;
//				free(aux1);
//				aux1=(*L);
//				cont++;
//				printf("\nentrou3\n");
//			}else{
//				//verificando se estiver no meio da lista
//				if(aux2->valor==num){
//					aux1->prox=aux2->prox;
//					aux3->ant=aux2->ant;
//					free(aux2);
//					cont++;
//					printf("\nnentrou4\n");
//				}else{
//					printf("\nvirou a chave\n");
//					aux1=aux1->prox;
//					aux2=aux2->prox;
//					aux3=aux3->prox;
//				}
//			}
//		}
//	}
//	printf("\nfim\n");
	printf("\nfim\n");
	return cont;

}

//Altera todas as ocorrencias de 'velho' pelo numero 'novo'
//Retorna a quantidade de alterações realizadas.
int alterar (TLista L, int velho, int novo)
{
	TLista aux = L;
   	int c = 0;
   
   	while (aux)
   	{
    	if (aux->valor == velho)
      	{
        	aux->valor = novo;
         	c++;
      	}
      
      	aux = aux->prox;
   	}

   	//retornando a quantidade de alterações realizadas
    return c;
}

//Busca determinado elemento na lista. Se for encontrado, é retornado o endereço de sua 
//primeira ocorrência; caso contrário, o valor NULL é retornado
TLista pesquisar (TLista L, int num)
{
	TLista aux = L;
   
   	while (aux)
   	{
      	if (aux->valor == num)
      	{
        	return aux;
      	}
      	
		aux = aux->prox;
   	}
   
   	//elemento não encontrado
   	return NULL;
}

//Exibe todos os elementos da lista, na ordem natural
void exibir (TLista L)
{
	TLista aux;
   
   	//verificando se a lista está vazia
   	if (!L)
   	{
      	printf ("Lista vazia!\n");
   	}
   	else
   	{
      	printf ("Lista: ");
      	
      	aux = L;
      
      	while (aux)
      	{
         	printf ("%d ", aux->valor);
         	aux = aux->prox;
      	}
            
      	printf ("\n");
   	}
}


//Exibe todos os elementos da lista, na ordem inversa
void exibirAoContrario (TLista U)
{
	TLista aux;
	
	//verificando se a lista está vazia
	if(!aux){
		printf("Lista vazia!");
	}else{
		aux = U;
		
		while(aux){
			printf ("%d ", aux->valor);
			aux = aux->ant;
		}
		printf ("\n");
	}
}
