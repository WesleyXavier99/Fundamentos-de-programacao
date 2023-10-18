#include<stdio.h>
#include<stdlib.h>
/*Escreva um programa que leia primeiro os 6 n´umeros gerados pela loteria e depois os 6
n´umeros do seu bilhete. O programa ent˜ao compara quantos n´umeros o jogador acertou.
Em seguida, ele aloca espac¸o para um vetor de tamanho igual a quantidade de n´umeros
corretos e guarda os n´umeros corretos nesse vetor. Finalmente, o programa exibe os
n´umeros sorteados e os seus n´umeros corretos.*/

void main()
{
	//ler os 6 numeros da loteria
	int loteria[6] = {6,5,4,3,2,1};
	int i,numeros[6],acertos=0,j,VetAcertos[6],saiu;
	
	//ler seus 6 numeros
	printf("Digite os seus numeros");
	for(i = 0 ; i<6 ; i++)
	{
		scanf("%d",&numeros[i]);
	}
	
	//comparar quantos numeros o jogador acertou
	for(i=0; i<6 ;i++)
	{
		for(j=0; j<6 ;j++)
		{
			/*printf("%d",j);
			if(numeros[i]==loteria[j])
			{
				printf("numeros[%d] = %d loteria[%d] = %d\n",i,numeros[i],j,loteria[j]);
				VetAcertos[acertos]=i;
				acertos++;
			}*/
			printf("numeros[i]=%d\nloteria[j]=%d\n\n ",numeros[i],loteria[j]);
			if(numeros[i]==loteria[j])
			{
				VetAcertos[acertos]=numeros[i];
				acertos++;
				printf("achou\n\n");
			}
		}
	}
	printf("\n");
	printf("\nacertos = %d\n",acertos);
	//alocar vetor de tamanho = quantidade de acertos
	//exibir os numeros sorteados
	for(i = 0; i<6 ; i++)
	{
		printf("%i",loteria[i]);
	}
	printf("\n");
	
	for(i = 0; i<6 ; i++)
	{
		printf("%i",numeros[i]);
	}
	printf("\n");
	
	for(i = 0; i<6 ; i++)
	{
		printf("%d",VetAcertos[i]);
	}
	
}
