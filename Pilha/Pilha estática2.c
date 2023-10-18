/*PILHA ESTATICA*/

#include<stdio.h>
#include<stdlib.h>

#DEFINE N 50

struct pilha {
	int n;
	int vet[N];
};

typedef struct pilha Pilha;

/**/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->n = 0;
	return p;
}

/**/
void pilha_push(Pilha* p, float v ){
	if(p->n==N){
		printf("Capacidade total da pilha esgotou!\n");
		exit(1);
	}
	p->vet[p->n] = v;
	p->n++;
}

/**/
float pilha_pop(Pilha* p){
	float v;
	
	if(pilha_vazia(p)){
		printf("A pilha esta vazia!\n");
		exit(1);
	}
	v = p->vet[p->n];
	p->n--;]
	return v;
}

/**/
int pilha_vazia(Pilha* p){
	if(p->n==0){
		return 0;
	}else{
		return 1;
	}
}

/**/
int pilha_libera(Pilha* p){
	p->n = 0;
}
