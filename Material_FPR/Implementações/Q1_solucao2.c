/*
	FPR - 2020/1
	Professor Leonardo Vianna
	
	Resolu��o da AV1 (solu��o apresentada por alunx)
	
	Quest�o 01 [1,0 ponto]:
	Desenvolver uma fun��o recursiva que determine o n�mero de caracteres comuns entre 
	duas strings s1 e s2.
	
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
#include <string.h>

//prot�tipos das fun��es

//Fun��o auxiliar: verifica se o caracter 'c' existe na string 's', a 
//partir da posi��o 'pos'
int buscar (char s[], char c, int pos);


/*Par�metros: 
     s1 	a primeira string
	 s2 	a segunda string
	 pos	cada posi��o de s2	 
	 quant	quantidade de caracteres comuns entre s1 e s2
	 
  Retorno: a quantidade de caracteres comuns entre as duas strings
*/
int caracteresComuns (char s1[], char s2[], int pos, int quant);

//fun��o 'main'
void main ()
{
	//declara��o de vari�veis
	int resp;
	char str1[10], str2[10];
	
	//atribuindo valores �s strings para testar a fun��o
	strcpy (str1, "abcde");
	strcpy (str2, "badce");
	
	//chamando a fun��o
	resp = caracteresComuns (str1, str2, 0, 0);
	
	//exibindo o resultado
	printf("Ha %d caracteres comuns entre as strings %s e %s.\n", resp, str1, str2);
}

//implementa��o das fun��es

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
     
	 	//continuando as compara��es a partir da pr�xima posi��o   
		return caracteresComuns (s1, s2, pos+1, quant);
    }
}

//Verifica se o caracter 'c' existe na string 's', a partir da posi��o 'pos'
int buscar (char s[], char c, int pos)
{
	//verificando se percorreu toda a string
	if (s[pos] == '\0')
    {
        return 0;		//toda a string foi percorrida e o caracter n�o encontrado
    }
    else
	{    	
        //verificando se o caracter 'c' est� na posi��o 'pos' de 's'
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
