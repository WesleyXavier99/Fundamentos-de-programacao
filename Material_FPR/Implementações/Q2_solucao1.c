/*
	FPR - 2020/1
	Professor Leonardo Vianna
	
	Resolu��o da AV1 (solu��o apresentada por alunx)
	
	Quest�o 02 [1,0 ponto]:
	Uma determinada faculdade mant�m o seu "mapa de salas" armazenado sob a forma de uma 
	matriz tridimensional de structs, considerando que:
	   i.  O pr�dio possui 8 andares e, em cada andar, h� 10 salas;
	   ii. Uma vez que h� atividades em todos os turnos, � necess�rio que a aloca��o de 
	       salas seja separada por turno (matutino, vespertino e noturno).

	[imagem]

	Aten��o: a partir da imagem acima, podemos dizer que o elemento M[2][3][1] representa: 
	no andar 2, a sala n� 3 do andar 2, turno 1 (vespertino).
	
	E o que representa este "mapa de salas"? Apenas um controle que diz a que turma 
	determinada sala est� alocada, em um dado turno. Para isto, cada posi��o da matriz 
	dever� armazenar as seguintes informa��es: 
	   - status (int): 0 - livre; 1 - alocada; 2 - em manuten��o;
	   - curso (string): caso a sala esteja alocada, a que curso;
	   - per�odo (int): caso a sala esteja alocada, a qual per�odo daquele curso. 

	Sobre este cen�rio, pede-se:
	   1. A declara��o da matriz, assim como de todos os tipos de dados associados � sua 
	      estrutura;
	   2. Uma fun��o que, dado um curso, exiba todas as salas ocupadas por ele. Ao exibir 
	      cada sala, utilizar o formato do exemplo a seguir: 

							M75: sala 5 do 7� andar, turno manh�

	Notas:
	   i.   A solu��o deve estar na linguagem de programa��o C;
	   ii.  Podem considerar que as salas variam de 0 a 9, assim como os andares de 0 a 7;
	   iii. Quanto aos turnos, considerar: 0 - matutino; 1 - vespertino; 2 - noturno;
	   iv.  Salvar o arquivo com o seu nome completo, seguido da extens�o .c.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defini��o de constantes

//-----TURNOS
#define MATUTINO 0
#define VESPERTINO 1
#define NOTURNO 2

//-----DIMENSOES
#define ANDARES 8
#define SALAS 10
#define TURNOS 3

//-----STATUS DE SALA
#define LIVRE 0
#define ALOCADA 1
#define EMMANUTENCAO 2

//Defini��o de tipos

//-----Representando cada sala do pr�dio
typedef struct
{
	int status;			//se est� ocupada, livre ou em manuten��o
	char curso[30];		//caso esteja ocupada, a qual curso
	int periodo;		//caso esteja ocupada, a qual per�odo do curso representado no 
	                    //campo anterior	
} TSala;

//prot�tipos das fun��es

//-----converte um turno inteiro (0, 1 ou 2) para 'M', 'V' ou 'N'
char obterTurno (int turno);

//-----exibe todas as salas ocupados pelo 'curso'
void exibirSalasOcupadasPorCurso (TSala salas[ANDARES][SALAS][TURNOS], char* curso);

//-----'limpa' todas as salas, tornando todas livres
void limpar (TSala salas[ANDARES][SALAS][TURNOS]);

//fun��o 'main'
void main ()
{
	//declara��o de vari�veis	
	TSala mapa[ANDARES][SALAS][TURNOS];		//a matriz tridimensional

	//inicializando a matriz
	limpar (mapa);

	//preenchendo os dados de algumas salas para teste
	strcpy(mapa[0][1][1].curso, "MEDICINA");
	mapa[0][1][1].periodo = 5;
	mapa[0][1][1].status = ALOCADA;

	strcpy(mapa[0][2][1].curso, "MEDICINA");
	mapa[0][2][1].periodo = 5;
	mapa[0][2][1].status = EMMANUTENCAO;

	strcpy(mapa[2][3][0].curso, "TI");
	mapa[2][3][0].periodo = 5;
	mapa[2][3][0].status = ALOCADA;

	strcpy(mapa[6][5][2].curso, "MEDICINA");
	mapa[6][5][2].periodo = 5;
	mapa[6][5][2].status = ALOCADA;

	//chamando a fun��o para exibir as salas ocupadas pelo curso de Medicina
	exibirSalasOcupadasPorCurso (mapa, "MEDICINA");
}

//implementa��o das fun��es

//-----converte um turno inteiro (0, 1 ou 2) para 'M', 'V' ou 'N'
char obterTurno (int turno)
{
	switch (turno)
	{
		case MATUTINO:	 return 'M';
		                 break;
		case VESPERTINO: return 'V';
		                 break;
		case NOTURNO:    return 'N';
	}
}

//-----'limpa' todas as salas, tornando todas livres
void limpar (TSala salas[ANDARES][SALAS][TURNOS])
{
	//declara��o de vari�veis
	int i, j, k;

	//varrendo todos os andares
	for (i=0; i<ANDARES; i++)
	{
		//varrendo todas as salas
		for (j=0; j<SALAS; j++)
		{
			//varrendo todos os turnos
			for (k=0; k<TURNOS; k++)
			{
				salas[i][j][k].curso[0] = '\0';
				salas[i][j][k].periodo = 0;
				salas[i][j][k].status = LIVRE;
			}
		}
	}
}

//-----exibe todas as salas ocupados pelo 'curso'
void exibirSalasOcupadasPorCurso(TSala salas[ANDARES][SALAS][TURNOS], char* curso)
{
	//declara��o de vari�veis
	int i, j, k;
	
	//varrendo todos os andares
	for (i=0; i<ANDARES; i++)
	{
		//varrendo todas as salas
		for (j=0; j<SALAS; j++)
		{
			//varrendo todos os turnos
			for (k=0; k<TURNOS; k++)
			{
				//verificando: i. se a sala est� ocupada; 
				//             ii. caso esteja, se est� ao curso passado por par�metro
				if ((salas[i][j][k].status == ALOCADA) && (strcmp (salas[i][j][k].curso, curso) == 0))
				{
					printf("%c%i%i\n", obterTurno(k), i, j);
				}
			}
		}
	}
}
