/*LISTA ENCADEADA*/
#include<stdio.h>
#include<stdlib.h>


struct lista {
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

/*Função de criação da lista: retorna uma lista vazia*/
Lista* lst_cria(void){

	return NULL;
}

/*função de inserção*/
Lista* lst_insere(Lista* l, int info){
	
	Lista* novo =(Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = l;
	return novo;
}

/*Função para imprimir os elementos da lista*/
void lst_imprime(Lista *l){
	
	Lista *p;
	
	for(p = l; p!=NULL;p = p->prox){
		
		printf("info = %d\n", p->info);
	}
}

/*Função para verificar se a lista está vazia. se vazia retorna 1, senão retorna 0*/
int lst_vazia(Lista *l){
	
	if(l==NULL){
		return 1;
	}else{
		return 0;
	}
}

/*Função para buscar um elemento da lista*/
Lista* lst_busca(Lista *l,int elemento){
	
	Lista *p;
	
	for(p=l; p!=NULL;p=p->prox){
		
		if(p->info==elemento){
			return p;
		}
	}
	return NULL; /*não achou o elemento*/
}

/*Função para retirar um elemento da lista*/
Lista * lst_retira(Lista* l, int v){
	
	Lista *ant = NULL;
	Lista *p = l;
	
	/*procura elemento na lista guardando o anterior*/
	while(p!=NULL && p->info!=v){
		ant = p;
		p = p->prox;
	}
	
	/*verifica se achou o elemento*/
	if(p==NULL){
		return l; /*não achou, retorna lista original*/
	}
	
	/*remover o elemento*/
	if(ant==NULL){
		l = p->prox;	/*remove no inicio*/
	}else{
		ant->prox = p->prox;	/*remove no meio*/
	}
	
	free(p);
	return l;
}

/*Função para liberar a lista*/
void lst_libera(Lista *l){
	
	Lista *p = l;
	
	while(p!=NULL){
		Lista * t = p->prox;		/*guarda referencia para o proximo item da lista*/
		free(p);				/*libera a memoria apontada pra p*/
		p = t;					/*faz p apontar para o proximo*/
	}
}

/*Função insere ordenado*/
Lista* lst_insere_ordenado(Lista *l,int v){
	
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	
	/*procurar posução de inserção*/
	while(p!=NULL&&p->info<v){
		ant = p;
		p = p->prox;
	}
	
	/*criar o novo elemento*/
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	
	/*encadeiar elemento*/
	if(ant==NULL){		/*insere no inicio da lista*/
		novo->prox = l;
		l = novo;
	}else{				/*insere no meio da lista*/
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	
	return l;
}

void main(){
	
	Lista* l;
	int opcao = 0, valor;
	
	l = lst_cria();
	
	while(opcao!=8){
		
		printf("Escolha uma opcao: \n1-Insere no inicio \n2-Remove elemento \n3Imprimir a lista \n4-Vereficar se esta vazia \n5-Buscar um valor \n6-Inserir ordenando \n7-Zerar a lista \n");
		scanf("%d",&opcao);
		switch(opcao){
			
			case 1:	printf("Digite o valor a ser inserido:");
					scanf("%d",&valor);
					l = lst_insere(l,valor);
			break;
			
			case 2:	printf("Digite o valor a ser reovido:");
					scanf("%d",&valor);
					l = lst_retira(l,valor);
			
			break;
			
			case 3: if(lst_vazia(l)==1){
					break;
						}else{
							lst_imprime(l);
						}
			break;
			
			case 4: if(lst_vazia(l)==1)
				{
					printf("Lista vazia!\n");
				}else{
					printf("Lista nao vazia\n");
				}
			break;
			
			case 5:	printf("Digite o valor a ser buscado:");
					scanf("%d",&valor);
					if(lst_busca(l,valor)==NULL){
						printf("Valor nao encontrado!\n");
					}else{
						printf("Valor encontrado!\n");
					}
			
			break;
			
			case 6:	printf("Digite o valor a ser inserido:");
					scanf("%d",&valor);
					l = lst_insere_ordenado(l,valor);
			
			break;
			
			case 7:	lst_libera(l);
					printf("Lista zerada!\n");
			
			break;
			
			case 8: 
			
			
			default: printf("Digite um valor valido\n");					
		}
	}
	
}

