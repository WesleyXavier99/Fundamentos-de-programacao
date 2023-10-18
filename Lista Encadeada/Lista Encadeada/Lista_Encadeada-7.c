/*QUEST�O 07:
Desenvolver uma fun��o que insira um n�mero inteiro N na i-�sima posi��o de uma lista
encadeada L.
Observa��o: caso a posi��o i informada seja inv�lida, a fun��o dever� retornar o valor 0; caso
contr�rio, o retorno ser� igual a 1.*/
#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

typedef struct No{
	int valor;
	struct No *prox;
}TNo;

typedef TNo* TLista;

int inserir(TLista *L1,int numero){
	TLista aux =(TLista) malloc(sizeof(TNo));
	
	if(!aux){//aux==NULL
		return FALSE;
	}else{
		//inserindo o valor desejado no campo valor
		aux->valor = numero;
		//colocando o aux pra apontar pro primeiro n� da lista
		aux->prox = *L1;
		//colocando o L1 pra apontar pro novo primeiro item da lista
		*L1 = aux;
	}
	return TRUE;
}

void exibir(TLista L){
	TLista i;
	
	//testar se a lista est� vazia
	if(L==NULL){
		printf("\nLISTA VAZIA\n");
	}else{
		
		i = L;
		
		while(i){//(i!=NULL)
			printf("%d ",i->valor);
			
			i = i->prox;
		}
	}
	printf("\n");
}

int tamanho(TLista L){
	TLista aux = L;
	int cont=0;
	
	while(aux){
		cont++;
		aux = aux->prox;
	}
	
	return cont;
}

int alterar(TLista L,int numero,int posicao){
	
	if(posicao>tamanho(L)){
		return 0;
	}else{
		
		TLista aux = L;
		int i=1;
		
		while(aux){
			if(i==posicao){
				aux->valor = numero;
			}
			aux = aux->prox;
			i++;
		}
	}
	return 1;
	
}
void main (){
	int numero,posicao,i,tam,res;
	TLista L1 = NULL;
	TLista L2 = NULL;
	
	//preencher as listas
	for(i=0;i<5;i++){
		inserir(&L1,i);		
	}
	
	printf("Digite o valor:");
	scanf("%d",&numero);
	
	printf("Digite a posi��o:");
	scanf("%d",&posicao);
	
	res = alterar(L1,numero,posicao);
	if(res==0){
		printf("Posicao invalida!\n");
	}else{
		printf("\nValor alterado com sucesso!\n");
	}
	exibir(L1);
	
}
