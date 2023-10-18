#include<stdio.h>

void main(){
	printf("%d",funcao(30,6));
}

int funcao(int a,int b){
	if(a>=b){
		return funcao(a-b,b);
	}else{
		return a;
	}
}
