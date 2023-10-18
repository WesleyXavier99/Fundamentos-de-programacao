/*Questão 01:Determinada zona eleitoral possui N eleitores inscritos que poderão votar, uma única vez, em um dos C candidatos para
o único cargo a ser definido. Pede-se:
a. A declaração de todo(s) o(s) tipo(s) de dados necessário(s) para o armazenamento dos números dos candidatos, assim como 
a quantidade de votos brancos, nulos e votos para cada candidato;
b. Uma função que leia o voto de cada eleitor, considerando que o processo terminará quando os N eleitores votarem ou quando 
o número -1 for digitado como voto;
c. Uma função que exiba:
i. O total de votos para cada candidato, assim com a quantidade de votos brancos (código 0) 
e de nulos (código sem candidato associado);
ii. A quantidade de abstenções (eleitores que não votaram);
iii. O número do candidato vencedor (caso tenha mais de 50% dos votos válidos) ou dos que irão para o segundo turno 
(os dois mais votados). 
Notas: a) o número do candidato deve conter dois algarismos apenas;b) podem considerar que não haverá mais de um candidato 
com a mesma quantidade de votos.*/
#include<stdio.h>
#include<string.h>
#define CANDIDATOS 3
#define ELEITORES 10

typedef struct{
	int n_candidato[CANDIDATOS];
	int n_eleitor[ELEITORES];
	int n_votos;
	int brancos;
	int nulos;
	int abstencoes;
}Teleicao;

Teleicao preencher_candidatos(Teleicao candidato,int tam){
	int i,numero = 40;
	for(i=0;i<tam;i++,numero+=15){
		candidato.n_candidato[i] = numero;
	}
	return candidato;
}

Teleicao preencher_eleitores(Teleicao eleitor,int tam){
	int i;
	for(i=0;i<tam;i++){
		eleitor.n_eleitor[i] = -1;
	}
	return eleitor;
}

Teleicao ler_votos(Teleicao eleicao, int tam){
	int i,opcao=0;
	
	for(i=0;i<tam && opcao!=-1;i++){
		printf("Digite seu voto:\n");
		scanf("%d",&opcao);
	
		if(opcao==0){
			eleicao.brancos+=1;
			eleicao.n_votos+=1;
			eleicao.n_eleitor[i] = opcao;
			printf("entrou1\n");
		}else{
			if(opcao==eleicao.n_candidato[0]){
				eleicao.n_eleitor[i] = opcao;
				eleicao.n_votos+=1;
				printf("entrou2\n");
			}else{
				if(opcao==eleicao.n_candidato[1]){
					eleicao.n_eleitor[i] = opcao;
					eleicao.n_votos+=1;
					printf("entrou3\n");
				}else{
					if(opcao==eleicao.n_candidato[2]){
						eleicao.n_eleitor[i] = opcao;
						eleicao.n_votos+=1;
						printf("entrou4\n");
					}else{
						if(opcao>0){
							eleicao.nulos+=1;
							eleicao.n_votos+=1;
							printf("entrou5\n");
						}
					}
				}
			}
		}
	}
	
	return eleicao;
}

void exibir_resultado(Teleicao eleitor,int tam){
	int i,cand1=0,cand2=0,cand3=0;
	
	for(i=0;i<tam;i++){
		if(eleitor.n_eleitor[i]==eleitor.n_candidato[0]){
			cand1++;
		}else{
			if(eleitor.n_eleitor[i]==eleitor.n_candidato[1]){
				cand2++;
			}else{
				if(eleitor.n_eleitor[i]==eleitor.n_candidato[2]){
					cand3++;
				}else{
					if(eleitor.n_eleitor[i]==-1){
						eleitor.abstencoes +=1;
					}
				}
			}
		}
	}
	
	//total de votos para cada candidato, brancos e nulos
	printf("Candidato %d = %d\n",eleitor.n_candidato[0],cand1);
	printf("Candidato %d = %d\n",eleitor.n_candidato[1],cand2);
	printf("Candidato %d = %d\n",eleitor.n_candidato[2],cand3);
	printf("nulos = %d\n",eleitor.nulos);
	printf("brancos = %d\n",eleitor.brancos);
	
	//abstenções
	printf("Abstencoes = %d\n",eleitor.abstencoes);
	//candidato vencedor ou segundo turno
	if(cand1>eleitor.n_votos/2){
		printf("O vencedor e o candidato %d\n",eleitor.n_candidato[0]);
	}else{
		if(cand2>eleitor.n_votos/2){
			printf("O vencedor e o candidato %d\n",eleitor.n_candidato[1]);
		}else{
			if(cand3>eleitor.n_votos/2){
				printf("O vencedor e o candidato %d\n",eleitor.n_candidato[2]);
			}else{
				if(cand1>cand3 && cand2>cand3){
					printf("A votacao sera decidida em segundo turno com os candidatos: %d e %d",eleitor.n_candidato[0],eleitor.n_candidato[1]);
				}else{
					if(cand1>cand2 && cand3>cand2){
						printf("A votacao sera decidida em segundo turno com os candidatos: %d e %d",eleitor.n_candidato[0],eleitor.n_candidato[2]);
					}else{
						if(cand2>cand1 && cand3>cand1){
							printf("A votacao sera decidida em segundo turno com os candidatos: %d e %d",eleitor.n_candidato[2],eleitor.n_candidato[1]);
						}
					}
				}
			}
		}
	}
}

void main(){
	Teleicao eleicao;
	int tam_eleitores = ELEITORES, tam_candidatos = CANDIDATOS;
	eleicao.n_votos = 0;
	eleicao.abstencoes = 0;
	eleicao.brancos = 0;
	eleicao.nulos = 0;
	
	//preencher o vetor de candidatos
	eleicao = preencher_candidatos(eleicao,tam_candidatos);
	
	//preencher o vetor de eleitores
	eleicao = preencher_eleitores(eleicao,tam_eleitores);
	
	//ler voto dos eleitores
	eleicao = ler_votos(eleicao,tam_eleitores);
	
	//exibir resultados
	exibir_resultado(eleicao,tam_eleitores);
}
