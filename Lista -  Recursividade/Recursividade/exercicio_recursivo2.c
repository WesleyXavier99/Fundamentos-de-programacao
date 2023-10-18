#include<stdio.h>

void funcao(int n);
void funcaoB(int x, int y);

void main(){
	funcaoA(8);
}

void funcaoA(int n){
	
	funcaoB(1,n);
}

void funcaoB(int x, int y){
	if(y>0){
		
		printf("%d ",x);
		funcaoB(x*2,y-1);
	}
}
