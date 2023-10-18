/*Questão 02:Uma loja de automóveis mantém os carros à venda sob a forma de um vetor de structs contendo as seguintes informações,
 para cada veículo: 
 placa, modelo, marca, cor, quilometragem, ano modelo/fabricação (deve ser um struct), valor e 
 tipo (usado ou 0 km, conforme o valor do campo quilometragem). Pede-se a declaração de uma variável que represente 
 o estoque de veículos da loja, incluindo todas as declarações de tipos que possam ser necessárias.Além disso, implementar 
 as seguintes funções: 
 i. Exibir todos os carros do modelo m, ano de fabricação entre a1 e a2 (inclusive), com valor não superior 
 a x reais;
 ii. Reajustar os valores de todos os carros 0 km, considerando um aumento de 2.5%;
 iii. Retirar do estoque um determinado 
 veículo, dada a sua placa.*/
 #include<stdio.h>
 #include<string.h>
 #define TAM 5
 
 typedef struct{
 	int modelo;
 	int fabricacao;
 }TAno;
 
 typedef struct{
 	char placa[10];
 	char  marca[30];
 	char modelo[30];
 	char cor[20];
 	char tipo[10];
 	float quilometragem;
 	float valor;
 	TAno data;
 }TAutomoveis;
 
 void preencher(TAutomoveis carros[], int tam){
 	int i;
 	
 	for(i=0;i<tam;i++){
 		switch(i){
 			case 0: //placa
 					strcpy(carros[i].placa,"ABC1D23");
 					//marca
 					strcpy(carros[i].marca,"chevrolet");
 					//modelo
 					strcpy(carros[i].modelo,"camaro");
 					//cor
 					strcpy(carros[i].cor,"Cinza");
 					//quilometragem
 					carros[i].quilometragem = 1800;
 					//valor
 					carros[i].valor = 65000;
 					//tipo
 					strcpy(carros[i].tipo,"usado");
 					//ano e modelo
 					carros[i].data.fabricacao = 2015;
 					carros[i].data.modelo = 2015;
 			break;
 			
 			case 1: //placa
 					strcpy(carros[i].placa,"AJK1Y65");
 					//marca
 					strcpy(carros[i].marca,"Peugeot");
 					//modelo
 					strcpy(carros[i].modelo,"206");
 					//cor
 					strcpy(carros[i].cor,"Preto");
 					//quilometragem
 					carros[i].quilometragem = 0;
 					//valor
 					carros[i].valor = 55000;
 					//tipo
 					strcpy(carros[i].tipo,"0 km");
 					//ano e modelo
 					carros[i].data.fabricacao = 2017;
 					carros[i].data.modelo = 2019;
 			
 			break;
 			
 			case 2: //placa
 					strcpy(carros[i].placa,"FTF1O63");
 					//marca
 					strcpy(carros[i].marca,"Ferrari");
 					//modelo
 					strcpy(carros[i].modelo,"xst");
 					//cor
 					strcpy(carros[i].cor,"Amarelo");
 					//quilometragem
 					carros[i].quilometragem = 600;
 					//valor
 					carros[i].valor = 70000;
 					//tipo
 					strcpy(carros[i].tipo,"usado");
 					//ano e modelo
 					carros[i].data.fabricacao = 2013;
 					carros[i].data.modelo = 2013;
 			
 			break;
 			
 			case 3: //placa
 					strcpy(carros[i].placa,"DEF8S12");
 					//marca
 					strcpy(carros[i].marca,"Fiat");
 					//modelo
 					strcpy(carros[i].modelo,"uno");
 					//cor
 					strcpy(carros[i].cor,"Cinza");
 					//quilometragem
 					carros[i].quilometragem = 0;
 					//valor
 					carros[i].valor = 100000;
 					//tipo
 					strcpy(carros[i].tipo,"0 km");
 					//ano e modelo
 					carros[i].data.fabricacao = 2018;
 					carros[i].data.modelo = 2013;
 			
 			break;
 			
 			case 4://placa
 					strcpy(carros[i].placa,"TYF8S12");
 					//marca
 					strcpy(carros[i].marca,"Fiat");
 					//modelo
 					strcpy(carros[i].modelo,"uno");
 					//cor
 					strcpy(carros[i].cor,"Cinza");
 					//quilometragem
 					carros[i].quilometragem = 0;
 					//valor
 					carros[i].valor = 100000;
 					//tipo
 					strcpy(carros[i].tipo,"0 km");
 					//ano e modelo
 					carros[i].data.fabricacao = 2018;
 					carros[i].data.modelo = 2013;
 				
 			break;
		 }
	 }
 }
 
 void exibir(TAutomoveis carros[], int tam){
 	int i,a1,a2;
 	float valor_carro;
 	char modelo_carro[20];
 	
 	printf("modelo:\n");
 	gets(modelo_carro);
 	
 	printf("a1:\n");
 	scanf("%d",&a1);
	
	printf("a2:\n");
 	scanf("%d",&a2);
 	
 	printf("valor:\n");
 	scanf("%f",&valor_carro);
 	
 	for(i=0;i<tam;i++){
 		if(strcmp(carros[i].modelo,modelo_carro)==0 && carros[i].data.fabricacao >=a1 && carros[i].data.fabricacao <=a2 && carros[i].valor <= valor_carro){
 			puts(carros[i].placa);
 			puts(carros[i].marca);
 			puts(carros[i].cor);
 			puts(carros[i].modelo);
 			puts(carros[i].tipo);
 			printf("%f\n",carros[i].valor);
 			printf("%f\n",carros[i].quilometragem);
 			printf("%d\n",carros[i].data.fabricacao);
 			printf("%d\n",carros[i].data.modelo);
		 }
	 }
 }
 
 void reajustar(TAutomoveis carros[],int tam){
 	int i;
 	
	 for(i=0;i<tam;i++){
	 	if(strcmp(carros[i].tipo,"0 km")==0){
	 		carros[i].valor += (2.5/100)*(carros[i].valor);
		 }
	 }	
	 
 }
 
 void remover(TAutomoveis carros[], int *tam){
 	int i,j;
 	char placa_carro[10];
 	
 	printf("placa\n");
 	gets(placa_carro);
 	
 	for(i=0;i<*tam;i++){
 		if(strcmp(carros[i].placa,placa_carro) == 0){
 			for(j=i;j<*tam-1;j++){
 				carros[i]=carros[i+1];
			 }
			 *tam--;
		 }
	 }
 }
 
 void main(){
 	TAutomoveis carros[TAM];
 	int tam = TAM,i;
 	
 	//preencher os dados dos carros
 	preencher(carros,tam);
 	
 	for(i=0;i<tam;i++){
 		puts(carros[i].placa);
 		puts(carros[i].marca);
 		printf("%.3f\n",carros[i].quilometragem);
 		puts(carros[i].tipo);
 		printf("%.3f\n",carros[i].valor);
 		puts(carros[i].cor);
 		printf("%d\n",carros[i].data.fabricacao);
 		printf("%d\n\n",carros[i].data.modelo);
	 }
	 //exibir(carros,tam);
	 reajustar(carros,tam);
	 
	 printf("\npos reajuste\n");
	 
	 for(i=0;i<tam;i++){
 		puts(carros[i].placa);
 		puts(carros[i].marca);
 		printf("%.3f\n",carros[i].quilometragem);
 		puts(carros[i].tipo);
 		printf("%.3f\n",carros[i].valor);
 		puts(carros[i].cor);
 		printf("%d\n",carros[i].data.fabricacao);
 		printf("%d\n\n",carros[i].data.modelo);
		}
		
		remover(carros,&tam);
		
		printf("\npos remocao\n");
		
		for(i=0;i<tam;i++){
 		puts(carros[i].placa);
 		puts(carros[i].marca);
 		printf("%.3f\n",carros[i].quilometragem);
 		puts(carros[i].tipo);
 		printf("%.3f\n",carros[i].valor);
 		puts(carros[i].cor);
 		printf("%d\n",carros[i].data.fabricacao);
 		printf("%d\n\n",carros[i].data.modelo);
		}
 }
