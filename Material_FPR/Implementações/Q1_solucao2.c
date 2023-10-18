/*
	FPR - 2020/1
	Professor Leonardo Vianna
	
	Resolução da AV1 (solução apresentada por alunx)
	
	Questão 01 [1,0 ponto]:
	Desenvolver uma função recursiva que determine o número de caracteres comuns entre 
	duas strings s1 e s2.
	
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
#include <string.h>

//protótipos das funções

//Função auxiliar: verifica se o caracter 'c' existe na string 's', a 
//partir da posição 'pos'
int buscar (char s[], char c, int pos);


/*Parâmetros: 
     s1 	a primeira string
	 s2 	a segunda string
	 pos	cada posição de s2	 
	 quant	quantidade de caracteres comuns entre s1 e s2
	 
  Retorno: a quantidade de caracteres comuns entre as duas strings
*/
int caracteresComuns (char s1[], char s2[], int pos, int quant);

//função 'main'
void main ()
{
	//declaração de variáveis
	int resp;
	char str1[10], str2[10];
	
	//atribuindo valores às strings para testar a função
	strcpy (str1, "abcde");
	strcpy (str2, "badce");
	
	//chamando a função
	resp = caracteresComuns (str1, str2, 0, 0);
	
	//exibindo o resultado
	printf("Ha %d caracteres comuns entre as strings %s e %s.\n", resp, str1, str2);
}

//implementação das funções

//retorna a quantidade de caracteres comuns entre as strings 's1' e 's2'
int caracteresComuns (char s1[], char s2[], int pos, int quant)
{
	//verificando se percorreu toda a string 's2'
	if (s2[pos] == '\0')
    {
        return quant;
    }
    else
	{
		//verificando se o caracter 's2[pos]' existe na string 's11
		if (buscar (s1, s2[pos], 0) == 1)
        {
			quant++;
        }
     
	 	//continuando as comparações a partir da próxima posição   
		return caracteresComuns (s1, s2, pos+1, quant);
    }
}

//Verifica se o caracter 'c' existe na string 's', a partir da posição 'pos'
int buscar (char s[], char c, int pos)
{
	//verificando se percorreu toda a string
	if (s[pos] == '\0')
    {
        return 0;		//toda a string foi percorrida e o caracter não encontrado
    }
    else
	{    	
        //verificando se o caracter 'c' está na posição 'pos' de 's'
		if (s[pos] == c)
        {
            return 1;	//caracter encontrado
        }
        else
		{
			return buscar (s, c, pos+1);
        }
    }
}
