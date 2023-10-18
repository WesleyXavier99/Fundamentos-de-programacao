/*Desenvolver uma função que gere a seguinte
matriz M5?5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9*/
#include<stdio.h>
#define COLUNAS 5
#define LINHAS 5

int gerar(int m[LINHAS][COLUNAS]){
	int i,j,k;
	
	for(i=0;i<LINHAS;i++){
		for(j=0,k=i+1;j<COLUNAS;j++,k++){
			m[i][j] = k;
		}
	}
}

void main(){
	//declaração de variaveis
	int m[5][5];
	
	//gerar matriz
	gerar(m);
}
