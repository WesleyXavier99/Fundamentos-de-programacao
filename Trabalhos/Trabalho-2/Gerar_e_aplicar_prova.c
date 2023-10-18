#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#define QUESTOES 50
#define ENUNCIADOS 1000
#define ALTERNATIVA 1000
#define NOME 100
#define RESPOSTAS 10
#define ALUNOS 20

//DEFINIÇÃO DOS TIPOS DE DADOS
typedef struct{
	char enunciado[ENUNCIADOS],
	a[ALTERNATIVA],
	b[ALTERNATIVA],
	c[ALTERNATIVA],
	d[ALTERNATIVA],
	e[ALTERNATIVA],
	gabarito;
}TQuestoes;

typedef struct{
	char nome[NOME],respostas[RESPOSTAS];
	int matricula;
	float nota;
}TAlunos;

//ESCOPO DAS FUNÇÕES
int preencher_questoes(TQuestoes banco[], int tam);
void gerarProva (TQuestoes banco[],TQuestoes prova[],int tam);
int verificar(TQuestoes banco[],TQuestoes prova[],int aux,int atual);
char exibirQuestao(TQuestoes prova[], int questao);
void aplicarProva(TQuestoes prova[], int tam, TAlunos aluno[],int atual);
float calcularNota(TAlunos aluno[], int atual, TQuestoes prova[], int tamProva);
void exibirResultado(TAlunos turma[], int tam);

int preencher_questoes(TQuestoes banco[], int tam){
	int cont=0,i,j=0,tam_Enunciado=0,tama=0,tamb=0,tamc=0,tamd=0,tame=0,tamg=0;
	char aux, gabarito[4];

	//abrindo arquivo com as questoes
	FILE *arq = fopen("Questoes_trabalho.txt","r");

	//verificando se tem erro na abertura do arquivo
	if(arq==NULL){
		return 0;
	}

	//lendo questao por questao
	for(i=0;i<tam;i++){
		while(cont!=7&&fscanf(arq,"%c",&aux)!=EOF){

			if(aux=='°'){
				cont++;
				j=0;
			}
			switch(cont){
				case 0:banco[i].enunciado[j] = aux;
						j++;
						tam_Enunciado++;
				break;
				case 1: banco[i].a[j] = aux;
						j++;
						tama++;
				break;
				case 2: banco[i].b[j] = aux;
						j++;
						tamb++;
				break;
				case 3: banco[i].c[j] = aux;
						j++;
						tamc++;
				break;
				case 4: banco[i].d[j] = aux;
						j++;
						tamd++;
				break;
				case 5: banco[i].e[j] = aux;
						j++;
						tame++;
				break;
				case 6: gabarito[j] = aux;
						j++;
						tamg++;
				break;
			}
			banco[i].gabarito = gabarito[2];
		}
		banco[i].enunciado[tam_Enunciado-1]='\0';
		banco[i].a[tama-1]= '\0';
		banco[i].b[tamb-1]= '\0';
		banco[i].c[tamc-1]= '\0';
		banco[i].d[tamd-1]= '\0';
		banco[i].e[tame-1]= '\0';
		cont=0;
		tam_Enunciado=0;
		tama = 0;
		tamb = 0;
		tamc = 0;
		tamd = 0;
		tame = 0;
		tamg = 0;
	}
	fclose(arq);
	return 1;
}

void gerarProva (TQuestoes banco[],TQuestoes prova[],int tam){
	int i,aux;
	srand((unsigned)time(NULL));

	//gerar prova com questões aleatórias
	for(i=0;i<tam;i++){
		aux = rand()%50;
		while(verificar(banco,prova,aux,i)==1){
			aux = rand()%50;
		}
		strcpy(prova[i].enunciado,banco[aux].enunciado);
		strcpy(prova[i].a,banco[aux].a);
		strcpy(prova[i].b,banco[aux].b);
		strcpy(prova[i].c,banco[aux].c);
		strcpy(prova[i].d,banco[aux].d);
		strcpy(prova[i].e,banco[aux].e);
		prova[i].gabarito = banco[aux].gabarito;
	}

}

int verificar(TQuestoes banco[],TQuestoes prova[],int aux,int atual){
	int i;
	//procurar o valor dentro do vetor
	for(i=0;i<atual;i++){
		if(strcmp(banco[aux].enunciado,prova[i].enunciado)==0){
			return 1;
		}
	}
	return 0;
}

char exibirQuestao(TQuestoes prova[], int questao)
{
	//exibir questoes
    char r;
    printf("Questao %d: ", questao+1);
    puts(prova[questao].enunciado);
    puts(prova[questao].a);
    puts(prova[questao].b);
    puts(prova[questao].c);
    puts(prova[questao].d);
    puts(prova[questao].e);

	//ler resposta do usuario
    printf("Digite a alternativa correta: ");
    fflush(stdin);
    scanf("%c", &r);
    r = toupper(r);

    return r;
}

void aplicarProva(TQuestoes prova[], int tam, TAlunos aluno[],int atual)
{
    int acertos = 0, i;

    for(i=0;i<tam;i++)
    {
        aluno[atual].respostas[i] = exibirQuestao(prova, i);
    }
}

float calcularNota(TAlunos aluno[], int atual, TQuestoes prova[], int tamProva)
{
    float valorQuestao;
    int acertos=0, i;
    valorQuestao = 10.0/tamProva;
    
    //calculando acertos
    for(i=0;i<tamProva;i++)
    {
        if(aluno[atual].respostas[i]==prova[i].gabarito)
        {
            acertos++;
        }
    }
    return acertos*valorQuestao;
}

void exibirResultado(TAlunos turma[], int tam)
{
    int i,j;
    TAlunos aux[tam],aux2;
    
    //passar dados do vetor pro auxiliar
    for(i=0;i<tam;i++)
    {
    	strcpy(aux[i].nome,turma[i].nome);
    	aux[i].matricula = turma[i].matricula;
    	aux[i].nota = turma[i].nota;
	}
	
	//Ordenar vetor auxiliar
	for(i=0;i<tam;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			if(aux[i].nota>aux[j].nota)
			{
				strcpy(aux2.nome,aux[i].nome);
		    	aux2.matricula = aux[i].matricula;
		    	aux2.nota = aux[i].nota;
				
				strcpy(aux[i].nome,aux[j].nome);
		    	aux[i].matricula = aux[j].matricula;
		    	aux[i].nota = aux[j].nota;
		    	
		    	strcpy(aux[j].nome,aux2.nome);
		    	aux[j].matricula = aux2.matricula;
		    	aux[j].nota = aux2.nota;
			}
		}
	}
	
	//exibir informações e categorias
	for(i=tam-1;i>=0;i--)
	{
		printf("\n");
		if(aux[i].nota>=8){
			printf("\tCategoria A\t");
		}else{
			if(aux[i].nota>=6.5){
				printf("\tCategoria B\t");
			}else{
				if(aux[i].nota>=5){
					printf("\tCategoria C\t");
				}else{
					printf("\tCategoria D\t");
				}
			}
		}
		printf("\t%s\t",aux[i].nome);
		printf("\t%d\t",aux[i].matricula);
	}
    printf("\n\n");

}

void main(){

	//Declaração das variáveis
	TQuestoes banco[QUESTOES],prova[10];
	TAlunos turma[ALUNOS];
	int opcao=-1,quant=-1, quant2,res,i,j;//quant é a quantidade de questoes/quant2 é a quantidade de alunos a fazerem a prova
	
	//preecher o banco de questões
	if(preencher_questoes(banco,QUESTOES)==0){
		printf("\nNao foi possivel ler o banco de questoes\n");
		opcao = 3;
	}

	//menu do usuário
	while(opcao!=3){
		printf("Digite a opcao desejada:\n1-Gerar uma prova.\n2-Aplicar a prova\n3-sair do programa\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1: do{
                        printf("Digite a quantidade de questoes(5 a 10): ");
                        scanf("%d",&quant);
                    }while((quant<5) || (quant>10));
					//gerar prova
					gerarProva(banco,prova,quant);
					printf("\nProva gerada com sucesso\n");

			break;

			case 2:if(quant==-1)
                    {
                        printf("Antes da aplicacao, eh necessario gerar uma prova!\n\n\n");
                    }
                    else{
                            do{
                            printf("Digite a quantidade de alunos: ");
                            scanf("%d",&quant2);
                        }while(quant2<0 || quant2>20);
                        
                        //aplicar a prova e calcular nota
                        for(i=0;i<quant2;i++)
                        {
                            printf("Matricula: ");
                            scanf("%d", &turma[i].matricula);
                            printf("Nome: ");
                            fflush(stdin);
                            gets(turma[i].nome);
                            
                            
                            aplicarProva(prova, quant, turma,i);
							turma[i].nota = calcularNota(turma,i, prova, quant);
                        }
                        
                        //exibindo o resultado
                        exibirResultado(turma, quant2);

                    }

			break;

			case 3:

			break;

			default: printf("\ndigite uma opcao valida!\n");

			break;
		}
	}
}
