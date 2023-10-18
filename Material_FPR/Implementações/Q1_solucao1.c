/*
	FPR - 2020/1
	Professor Leonardo Vianna
	
	Resolu��o da AV1 (solu��o apresentada por alunx)
	
	Quest�o 01 [1,0 ponto]:
	Desenvolver uma fun��o recursiva que determine o n�mero de caracteres comuns entre 
	duas strings s1 e s2.
	
	s1: atfe
	s2: teste	
	
	Notas:
	   i.   A solu��o deve estar na linguagem de programa��o C;
	   ii.  Caso um mesmo caracter apare�a n vezes em determinada string, n�o ser� 
	        considerado erro se a sua solu��o contar este caracter n vezes;
	   iii. Se a sua solu��o for desmembrada em mais de uma fun��o (de maneira que a 
	        principal - que resolve o problema proposto - chame outras auxiliares), todas 
			as fun��es dever�o ser recursivas;
	   iv.  Salvar o arquivo com o seu nome completo, seguido da extens�o .c.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prot�tipo da fun��o

/*Par�metros: 
     s1 	a primeira string
	 s2 	a segunda string
	 quant	quantidade de caracteres comuns entre s1 e s2
	 pos1	cada posi��o de s1
	 pos2	cada posi��o de s2	 
	 
  Retorno: a quantidade de caracteres comuns entre as duas strings
*/
int caracteresComuns (char s1[], char s2[], int quant, int pos1, int pos2);

//fun��o 'main'
void main() 
{
	//declara��o de vari�veis
	int resp;
	char str1[10], str2[10];
	
	//atribuindo valores �s strings para testar a fun��o
	strcpy (str1, "abe");
	strcpy (str2, "bdfac");
	
	//chamando a fun��o
	resp = caracteresComuns (str1, str2, 0, 0, 0);
	
	//exibindoo resultado
	printf("Ha %d caracteres comuns entre as strings %s e %s.\n", resp, str1, str2);
}

//implementa��o da fun��o
int caracteresComuns (char s1[], char s2[], int quant, int pos1, int pos2)
{
	//verificanso de s1 foi totalmente percorrida
	if (pos1 == strlen (s1))
	{
		//verificanso de s2 tamb�m foi totalmente percorrida
		if (pos2 == strlen (s2))
		{
			return quant;		//retornar 'quant', pois n�o h� mais caracteres 
			                    //a comparar
		} 
		else 
		{
			//segue para o pr�ximo caracter de 's2', comparando-o com todos de 's1', 
			//come�ando por aquele que est� na posi��o 0
			return caracteresComuns (s1, s2, quant, 0, pos2+1);
		}
	} 
	
	//se encontrar caracteres iguais...
	if (s1[pos1] == s2[pos2])
	{
		//acrescentar um � quantidade de caracteres iguais. E continuar com as compara��es...
		return caracteresComuns (s1, s2, quant+1, pos1+1, pos2);
	} 
	else 
	{
		//se n�o s�o iguais, continue a busca sem atualizar o 'quant'
		return caracteresComuns (s1, s2, quant, pos1+1, pos2);
	}	
}
