/*Questão 02: Considere a existência de dois conjuntos numéricos A e B
contendo n1 e n2 elementos, respectivamente.
Pede-se o desenvolvimento de uma função que determine se um dos conjuntos
está contido no outro, retornando os seguintes códigos:
? 1, se A estiver contido em B;
? 2, se B estiver contido em A;
? 0, caso contrário.*/
#include<stdio.h>

int ContidoOuNao(int vetorA[],int vetorB[],int num1,int num2);

int main()
{
	int num1,num2,i;
	
	printf("Digite a quantidade de numeros para o primeiro conjunto:\n");
	scanf("%d", &num1);
	
	int vetorA[num1];
	
	printf("Digite %d numeros para o primeiro conjunto:\n", num1);
	for(i=0;i<num1;i++)
	{
		scanf("%d",&vetorA[i]);
	}
	
	printf("Digite a quantidade de numeros para o segundo conjunto:\n");
	scanf("%d", &num2);
	
	int vetorB[num2];
	
	printf("Digite %d numeros para o segundo conjunto:\n",num2);
	for(i=0;i<num2;i++)
	{
		scanf("%d",&vetorB[i]);
	}
	
	ContidoOuNao(vetorA,vetorB,num1,num2);
	
	
	/*for(i=0;i<num1;i++)
	{
		printf("%d ",vetorA[i]);
	}
	
	printf("\n");
	
	for(i=0;i<num2;i++)
	{
		printf("%d ",vetorB[i]);
	}*/
	
}

int ContidoOuNao(int vetorA[],int vetorB[],int num1,int num2)//num1 é o tamanho do vetor A, num2 é o tamanho do vetor B
{
	int i,j,cont=0;
	
	if(num1<=num2)//se o vetor A for menor q o B, a gente procura o A dentro de B pq é mais rapido;
	{
		for(i=0;i<num1;i++)//for pra varrer o vetor A e ir comparando dentro do B
		{
			for(j=0;j<num2;j++)//for pra varrer o vetor B com um a um os elementos de A e ir comparando se existe dentro de B os elementos um a um de A
			{
				if(vetorA[i]==vetorB[j])//condicao pra saber se o elemento i de A esta dentro de B em alguma de suas posicoes
				{
					cont++;//contador pra contar quantos elementos de A estao dentro de B
				}				
			}
		}
		if(cont==num1)//se isso aqui for verdade é pq todos elementos de A estao dentro de B, já que o tamanho de A(num1) é igual ao numero de valores iguais entre os dois vetores 
		{
			printf("1-A esta contido em B\n");
		}
	}
	
	cont=0;//la em cima comparei se o A estava contido em B, agora vamos comparar pra ver se B esta contido em A; Aqui é a mesma coisa de cima, só muda q to comparando agora o B dentro de A
	
	if(num2<=num1)
	{
		for(i=0;i<num1;i++)
		{
			for(j=0;j<num2;j++)
			{
				if(vetorB[i]==vetorA[j])
				{
					cont++;
				}				
			}
		}
		if(cont==num2)
		{
			printf("2-B esta contido em A");
		}
	}
	
	if((cont!=num1)&&(cont!=num2))
	{
		printf("0-nao ha relacao de continencia");
	}
	
	
}

