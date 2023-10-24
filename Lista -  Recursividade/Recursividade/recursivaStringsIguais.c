 //recursiva que determina quantidade de caracteres comuns em duas strings
#include<stdio.h>
#include<string.h>
#define MAX 20

int percorreS2(char letra, char s2[MAX], int i);
int contIguais(char s1[MAX],char s2[MAX],int i,int *p);


void main(){
	char s1[MAX] = "Wesley";
	char s2[MAX] = "Paulos";
	
	puts(s1);
	puts(s2);
	int cont = 0;
	int p = 0;
	
	contIguais(s1,s2,cont,&p);
	printf("\n\nachou %d valores iguais",p);	
}

int contIguais(char s1[MAX],char s2[MAX],int i,int *p){	
	int contlocal = 0;
	
	if(s1[i]!='\0'){
		printf("\nPRIMEIRA RECURSIVA");
		printf("\n%c\t",s1[i]);
		printf("%d\n\n",i);
		printf("\nSEGUNDA RECURSIVA\n");
		contlocal = percorreS2(s1[i],s2,0);
		if(contlocal>0){
			(*p) += contlocal;
		}
		printf("\n\nachou ? %d\n\n",(*p));
		contIguais(s1,s2,i+1,p);
		printf("\ndepois da chamada de cada recursão\n");
	}else{
		printf("\nretornou");
		return 0;
	}
}

int percorreS2(char letra, char s2[MAX], int i){
	
	if(s2[i]!='\0'){
		printf("%c\t%c\t",s2[i],letra);
		printf("%d\t",i);
		if(letra == s2[i]){
			printf("iguais\n\n");
			return 1;
		}else{
			printf("diferentes\n\n");
		}
		percorreS2(letra,s2,i+1);
	}else{
		return 0;
	}
}

