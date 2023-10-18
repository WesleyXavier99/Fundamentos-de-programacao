/*
	FPR - 2020/1
	Professor Leonardo Vianna
	
	Resolução da AV1 (solução apresentada por alunx)
	
	Questão 02 [1,0 ponto]:
	Uma determinada faculdade mantém o seu "mapa de salas" armazenado sob a forma de uma 
	matriz tridimensional de structs, considerando que:
	   i.  O prédio possui 8 andares e, em cada andar, há 10 salas;
	   ii. Uma vez que há atividades em todos os turnos, é necessário que a alocação de 
	       salas seja separada por turno (matutino, vespertino e noturno).

	[imagem]

	Atenção: a partir da imagem acima, podemos dizer que o elemento M[2][3][1] representa: 
	no andar 2, a sala nº 3 do andar 2, turno 1 (vespertino).
	
	E o que representa este "mapa de salas"? Apenas um controle que diz a que turma 
	determinada sala está alocada, em um dado turno. Para isto, cada posição da matriz 
	deverá armazenar as seguintes informações: 
	   - status (int): 0 - livre; 1 - alocada; 2 - em manutenção;
	   - curso (string): caso a sala esteja alocada, a que curso;
	   - período (int): caso a sala esteja alocada, a qual período daquele curso. 

	Sobre este cenário, pede-se:
	   1. A declaração da matriz, assim como de todos os tipos de dados associados à sua 
	      estrutura;
	   2. Uma função que, dado um curso, exiba todas as salas ocupadas por ele. Ao exibir 
	      cada sala, utilizar o formato do exemplo a seguir: 

							M75: sala 5 do 7º andar, turno manhã

	Notas:
	   i.   A solução deve estar na linguagem de programação C;
	   ii.  Podem considerar que as salas variam de 0 a 9, assim como os andares de 0 a 7;
	   iii. Quanto aos turnos, considerar: 0 - matutino; 1 - vespertino; 2 - noturno;
	   iv.  Salvar o arquivo com o seu nome completo, seguido da extensão .c.
*/

//importação de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definição de constantes

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

//Definição de tipos

//-----Representando cada sala do prédio
typedef struct
{
	int status;			//se está ocupada, livre ou em manutenção
	char curso[30];		//caso esteja ocupada, a qual curso
	int periodo;		//caso esteja ocupada, a qual período do curso representado no 
	                    //campo anterior	
} TSala;

//protótipos das funções

//-----converte um turno inteiro (0, 1 ou 2) para 'M', 'V' ou 'N'
char obterTurno (int turno);

//-----exibe todas as salas ocupados pelo 'curso'
void exibirSalasOcupadasPorCurso (TSala salas[ANDARES][SALAS][TURNOS], char* curso);

//-----'limpa' todas as salas, tornando todas livres
void limpar (TSala salas[ANDARES][SALAS][TURNOS]);

//função 'main'
void main ()
{
	//declaração de variáveis	
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

	//chamando a função para exibir as salas ocupadas pelo curso de Medicina
	exibirSalasOcupadasPorCurso (mapa, "MEDICINA");
}

//implementação das funções

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
	//declaração de variáveis
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
	//declaração de variáveis
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
				//verificando: i. se a sala está ocupada; 
				//             ii. caso esteja, se está ao curso passado por parâmetro
				if ((salas[i][j][k].status == ALOCADA) && (strcmp (salas[i][j][k].curso, curso) == 0))
				{
					printf("%c%i%i\n", obterTurno(k), i, j);
				}
			}
		}
	}
}
