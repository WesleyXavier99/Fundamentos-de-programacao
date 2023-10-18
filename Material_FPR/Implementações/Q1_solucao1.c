/*
	FPR - 2020/1
	Professor Leonardo Vianna
	
	Resolução da AV1 (solução apresentada por alunx)
	
	Questão 01 [1,0 ponto]:
	Desenvolver uma função recursiva que determine o número de caracteres comuns entre 
	duas strings s1 e s2.
	
	s1: atfe
	s2: teste	
	
	Notas:
	   i.   A solução deve estar na linguagem de programação C;
	   ii.  Caso um mesmo caracter apareça n vezes em determinada string, não será 
	        considerado erro se a sua solução contar este caracter n vezes;
	   iii. Se a sua solução for desmembrada em mais de uma função (de maneira que a 
	        principal - que resolve o problema proposto - chame outras auxiliares), todas 
			as funções deverão ser recursivas;
	   iv.  Salvar o arquivo com o seu nome completo, seguido da extensão .c.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//protótipo da função

/*Parâmetros: 
     s1 	a primeira string
	 s2 	a segunda string
	 quant	quantidade de caracteres comuns entre s1 e s2
	 pos1	cada posição de s1
	 pos2	cada posição de s2	 
	 
  Retorno: a quantidade de caracteres comuns entre as duas strings
*/
int caracteresComuns (char s1[], char s2[], int quant, int pos1, int pos2);

//função 'main'
void main() 
{
	//declaração de variáveis
	int resp;
	char str1[10], str2[10];
	
	//atribuindo valores às strings para testar a função
	strcpy (str1, "abe");
	strcpy (str2, "bdfac");
	
	//chamando a função
	resp = caracteresComuns (str1, str2, 0, 0, 0);
	
	//exibindoo resultado
	printf("Ha %d caracteres comuns entre as strings %s e %s.\n", resp, str1, str2);
}

//implementação da função
int caracteresComuns (char s1[], char s2[], int quant, int pos1, int pos2)
{
	//verificanso de s1 foi totalmente percorrida
	if (pos1 == strlen (s1))
	{
		//verificanso de s2 também foi totalmente percorrida
		if (pos2 == strlen (s2))
		{
			return quant;		//retornar 'quant', pois não há mais caracteres 
			                    //a comparar
		} 
		else 
		{
			//segue para o próximo caracter de 's2', comparando-o com todos de 's1', 
			//começando por aquele que está na posição 0
			return caracteresComuns (s1, s2, quant, 0, pos2+1);
		}
	} 
	
	//se encontrar caracteres iguais...
	if (s1[pos1] == s2[pos2])
	{
		//acrescentar um à quantidade de caracteres iguais. E continuar com as comparações...
		return caracteresComuns (s1, s2, quant+1, pos1+1, pos2);
	} 
	else 
	{
		//se não são iguais, continue a busca sem atualizar o 'quant'
		return caracteresComuns (s1, s2, quant, pos1+1, pos2);
	}	
}
