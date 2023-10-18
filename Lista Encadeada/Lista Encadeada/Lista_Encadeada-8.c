/*QUESTÃO 08:
Implementar uma função que crie uma lista encadeada (dinâmica) com os N primeiros termos
de uma PA (progressão aritmética) de razão R e primeiro termo igual a A1.
*/
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
		//colocando o aux pra apontar pro primeiro nó da lista
		aux->prox = *L1;
		//colocando o L1 pra apontar pro novo primeiro item da lista
		*L1 = aux;
	}
	return TRUE;
}

void exibir(TLista L){
	TLista i;
	
	//testar se a lista está vazia
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

void preencherPg(TLista L,int r,int a1,int n){
	int vetor[n],i;
	TLista aux = L;
	
	for(i=0;i<n;i++,a1*=r){
		vetor[i]=a1;
	}
	
	for(i=n-1;i>=0;i--){
		inserir(L,vetor[i]);
	}
}

void main (){

	TLista L1 = NULL,topo;
	int r,a1,n;
	
	printf("Digite a razao:");
	scanf("%d",&r);
	
	printf("Digite a1:");
	scanf("%d",&a1);
	
	printf("Digite quantos termos:");
	scanf("%d",&n);
	
	preencherPg(&L1,r,a1,n);
	exibir(L1);
	
}
