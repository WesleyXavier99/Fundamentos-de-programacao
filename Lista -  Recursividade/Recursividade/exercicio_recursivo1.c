#include<stdio.h>

void funcao(int n);

void main(){
	funcao(10);
}

void funcao(int n){
	
	if(n>0){
		
		printf("%d ",n);
		funcao(n-1);
	}
}
