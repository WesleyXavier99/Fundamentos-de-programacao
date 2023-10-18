#include<stdio.h>

void main(){
	int vetor[10]={10,4,2,6,2,4,2,2,4,4},resp;
	
	resp = removeRepeticao(vetor,10);
	printf("resp = %d",resp);
}

int removeRepeticao(int vetor[],int n){
	int i,j,k;
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			printf("i = %d j = %d\n",vetor[i],vetor[j]);
			if(vetor[i]==vetor[j]){
				for(k=j;k<n-1;k++){
					vetor[k]=vetor[k+1];
				}
				n--;
				j--;
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("vet[%d]%d\n",i,vetor[i]);
	}
	return n;
}
