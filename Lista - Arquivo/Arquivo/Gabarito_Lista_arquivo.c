/*
Lista V - Arquivos

Questão 01:
Desenvolver uma função que, dado um arquivo texto, verifique o número de caracteres no
mesmo.


//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int contaCaracteres (char nomeArq[]);

//main
void main ()
{
//declaração de variáveis
char nome[20];
int quant;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//chamando a função
quant = contaCaracteres (nome);

//exibindo o resultado
if (quant >= 0)
{
printf ("\n\nForam encontrados %d caracteres no arquivo %s", quant, nome);
}
else
{
printf ("Erro na abertura do arquivo!");
}
}

//implementação das funções
int contaCaracteres (char nomeArq[])
{
FILE *arq;
int cont = 0;
char caracter;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo e contando os caracteres do arquivo
while (fscanf (arq, "%c", &caracter) != EOF)
{
cont++;
}

//fechando o arquivo
fclose (arq);

//retornando a quantidade de caracteres do arquivo
return cont;
}
*/




/*
Lista V - Arquivos

Questão 02:
Desenvolver uma função que, dado um arquivo texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.


//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int contaCaracteres (char nomeArq[], char c);

//main
void main ()
{
//declaração de variáveis
char nome[20];
int quant;
char ch;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//lendo o caracter a ser buscado no arquivo
fflush (stdin);
printf ("Entre com o caracter a ser buscado: ");
scanf ("%c", &ch);

//chamando a função
quant = contaCaracteres (nome, ch);

//exibindo o resultado
if (quant >= 0)
{
printf ("\n\nForam encontrados %d ocorrencias do caracter '%c' no arquivo %s", quant, ch, nome);
}
else
{
printf ("Erro na abertura do arquivo!");
}
}

//implementação das funções
int contaCaracteres (char nomeArq[], char c)
{
FILE *arq;
int cont = 0;
char caracter;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo todos os caracteres do arquivo
while (fscanf (arq, "%c", &caracter) != EOF)
{
if (caracter == c) //verificando se é o caracter sendo buscado
{
cont++;
}
}

//fechando o arquivo
fclose (arq);

//retornando a quantidade de caracteres do arquivo
return cont;
}*/


/*	
Lista V - Arquivos

Questão 03:
Desenvolver uma função que, dado um arquivo texto, verifique o número de letras
existentes no mesmo (entendendo que no arquivo podem existir letras, algarismos e
símbolos).

//importação de bibliotecas
#include <stdio.h>

//protótipos das funções
int contaLetras (char nomeArq[]);

//main
void main ()
{
//declaração de variáveis
char nome[20];
int quant;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//chamando a função
quant = contaLetras (nome);

//exibindo o resultado
if (quant >= 0)
{
printf ("\n\nForam encontrados %d letras no arquivo %s", quant, nome);
}
else
{
printf ("Erro na abertura do arquivo!");
}
}

//implementação das funções
int contaLetras (char nomeArq[])
{
FILE *arq;
int cont = 0;
char caracter;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo todos os caracteres do arquivo
while (fscanf (arq, "%c", &caracter) != EOF)
{
caracter = toupper (caracter);

//verificando se está no intervalo de A a Z
if ((caracter >= 'A') && (caracter <= 'Z'))
{
cont++;
}
}

//fechando o arquivo
fclose (arq);

//retornando a quantidade de caracteres do arquivo
return cont;
}
*/

/*
Lista V - Arquivos

Questão 04:
Desenvolver uma função que, dado um arquivo texto contendo números, determine se estes
encontram-se ordenados crescentemente.


//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int verificaArquivo (char nomeArq[]);

//main
void main ()
{
//declaração de variáveis
char nome[20];
int resp;

//lendo o nome do arquivo
fflush (stdin);
printf ("Entre com o nome do arquivo: ");
gets (nome);

//chamando a função
resp = verificaArquivo (nome);

//exibindo o resultado
switch (resp)
{
case TRUE: printf ("\n\nOs elementos do arquivo %s encontram-se ordenados crescentemente", nome);
break;

case FALSE: printf ("\n\nOs elementos do arquivo %s nao encontram-se ordenados crescentemente", nome);
break;

default: printf ("\n\nErro na abertura do arquivo!");
}
}

//implementação das funções
int verificaArquivo (char nomeArq[])
{
FILE *arq;
float anterior, proximo;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//verificando se houve erro na abertura do arquivo
if (arq == NULL)
{
return -1; //erro na abertura do arquivo
}

//lendo o primeiro valor do arquivo
if (fscanf (arq, "%f", &anterior) != EOF)
{
//lendo os demais caracteres do arquivo
while (fscanf (arq, "%f", &proximo) != EOF)
{
//verificando se o anterior é maior do que o próximo. Se for, o arquivo
//não está ordenado
if (anterior > proximo)
{
return FALSE;
}

anterior = proximo;
}
}

//fechando o arquivo
fclose (arq);

return TRUE;
}*/


/*
Lista V - Arquivos

Questão 05:
Faça uma função que, dado um arquivo A contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos elementos de A, porém ordenados decrescentemente e
sem repetição.


//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int eliminaRepeticaoArquivo (char arqOriginal[], char arqNovo[]);
int pesquisar (float valor, char nomeArq[]);
int buscarMenorElemento (char nomeArq[], float *menor, float base);

//main
void main ()
{
//declaração de variáveis
char original[20], novo[20];
int resp;

//lendo os nomes dos dois arquivos
fflush (stdin);
printf ("Arquivo original: ");
gets (original);

fflush (stdin);
printf ("Arquivo novo: ");
gets (novo);

//chamando a função
resp = eliminaRepeticaoArquivo (original, novo);

//exibindo o resultado
if (resp == FALSE)
{
printf ("\nErro na abertura do arquivo!\n");
}
else
{
printf ("\nNovo arquivo gerado com sucesso!\n");
}
}

//implementação das funções
int eliminaRepeticaoArquivo (char arqOriginal[], char arqNovo[])
{
//declaração de variáveis
FILE *arqA, *arqB;
float valorA, menor, base = -9999;
int continuar;

//abrindo o arquivo original para que seus elementos sejam lidos
arqA = fopen (arqOriginal, "r");

//abrindo o arquivo novo para escrita; caso não exista, o mesmo será criado
//esta abertura servirá apenas para testar se houve algum tipo de erro na abertura deste
//arquivo e garantir que o mesmo seja criado, caso ainda não exista
arqB = fopen (arqNovo, "w");

//verificando se houve erro na abertura de algum arquivo
if ((arqA == NULL) || (arqB == NULL))
{
return FALSE; //erro na abertura
}

//fechando o arquivo novo, para que seja em seguida manipulado de forma distinta (leitura ou append)
fclose (arqB);

//buscando o menor elemento do arquivo (que seja maior do que a base)
continuar = buscarMenorElemento (arqOriginal, &menor, base);

while (continuar == TRUE)
{
//verificando se o elemento do arquivo A já foi inserido no arquivo B
if (pesquisar (menor, arqNovo) == FALSE)
{
arqB = fopen (arqNovo, "a");
fprintf (arqB, "%.1f\n", menor);
fclose (arqB);
}

//buscando o menor elemento do arquivo (que seja maior do que o último encontrado)
continuar = buscarMenorElemento (arqOriginal, &menor, menor);
}

fclose (arqA);

return TRUE;
}

//verificar se 'valor' encontra-se no arquivo de nome 'nomeArq', retornando TRUE ou FALSE
int pesquisar (float valor, char nomeArq[])
{
//declaração de variáveis
FILE *arq;
float numero;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//testando se houve erro na abertura do arquivo
if (arq == NULL)
{
return FALSE;
}

//lendo os números do arquivo em busca de 'valor'
while (fscanf (arq, "%f", &numero) != EOF)
{
if (numero == valor)
{
return TRUE; //'valor' encontrado no arquivo
}
}

//fechando o arquivo
fclose (arq);

//elemento não foi encontrado no arquivo
return FALSE;
}

//Dentre os valores do arquivo que sejam maior do que 'base', a função armazenará
//o menor deles no parâmetro 'menor'. Além disto, retornará FALSE se nenhum valor maior do
//que 'base' for encontrado.
int buscarMenorElemento (char nomeArq[], float *menor, float base)
{
//declaração de variáveis
FILE *arq;
float valor;
int alterou = FALSE;

//inicialização *menor com um valor alto
*menor = 99999;

//abrindo o arquivo para leitura
arq = fopen (nomeArq, "r");

//lendo todos os elementos do arquivo
while (fscanf (arq, "%f", &valor) != EOF)
{
if ((valor > base) && (valor < *menor))
{
*menor = valor;
alterou = TRUE;
}
}

//fechando o arquivo
fclose (arq);

return alterou;
}*/


/*
Lista V - Arquivos

Questão 06:
Desenvolver uma função que, dados dois arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:

- arqA e arqB contém números reais, um por linha, ordenados crescentemente e sem
repetição no arquivo;
- arqC deve conter todos os números dos dois arquivos originais;
- Assim como arqA e arqB, arqC também não possuirá repetições de elementos e estes
deverão estar ordenados de forma crescente.


//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int uniao (char arquivo1[], char arquivo2[], char arqUniao[]);

//main
void main ()
{
//declaração de variáveis
char A[20], B[20], C[20];
int resp;

//lendo os nomes dos arquivos
fflush (stdin);
printf ("Nome do arquivo A: ");
gets (A);

fflush (stdin);
printf ("Nome do arquivo B: ");
gets (B);

fflush (stdin);
printf ("Nome do arquivo que armazenara a uniao dos dois arquivos: ");
gets (C);

//chamando a função
resp = uniao (A, B, C);

//exibindo o resultado
if (resp == FALSE)
{
printf ("\nErro na abertura dos arquivos!\n");
}
else
{
printf ("\nArquivo '%s' gerado com sucesso!\n", C);
}
}

//implementação das funções
int uniao (char arquivo1[], char arquivo2[], char arqUniao[])
{
//declaração de variáveis
FILE *arqA, *arqB, *arqC;
float valorA, valorB;
int controleA, controleB;

//abrindo os três arquivos
arqA = fopen (arquivo1, "r");
arqB = fopen (arquivo2, "r");
arqC = fopen (arqUniao, "w");

//verificando se houve erro na abertura de algum arquivo
if ((arqA == NULL) || (arqB == NULL) || (arqC == NULL))
{
return FALSE; //erro na abertura
}

//as variáveis controle verificarão se algum arquivo (ou os dois) chegou ao final
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);

//verificando se algum arquivo chegou ao final
while ((controleA != EOF) && (controleB != EOF))
{
//verificando se o último valor lido do primeiro arquivo é menor do que o último
//lido do segundo
if (valorA < valorB)
{
//guarda-se o menor no arquivo união
fprintf (arqC, "%.1f\n", valorA);

//lendo o próximo valor do arquivo A
controleA = fscanf (arqA, "%f", &valorA);
}
else
{
//verificando se o último valor lido do segundo arquivo é menor do que o
//último lido do primeiro
if (valorB < valorA)
{
//guarda-se o menor no arquivo união
fprintf (arqC, "%.1f\n", valorB);

//lendo o próximo valor do arquivo B
controleB = fscanf (arqB, "%f", &valorB);
}
else
{
//se chegou aqui, os dois valores são iguais. Então, apenas um deles será
//escrito no arquivo união, eliminando, assim, a repetição
fprintf (arqC, "%.1f\n", valorA);

//lendo os próximos valores dos dois arquivos
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);
}
}
}

//se saiu do while, um dos arquivos (ou os dois) terminou. Então, é necessário
//transferir para o arquivo união os elementos do arquivo que ainda não foi totalmente
//lido

//primeiro, verificando se pelo menos um dos arquivos ainda possui elementos
if ((controleA != EOF) || (controleB != EOF))
{
//se o arquivo A terminou, copiar para C os elementos pendentes de B
if (controleA == EOF)
{
fprintf (arqC, "%.1f\n", valorB);

while (fscanf (arqB, "%f", &valorB) != EOF)
{
fprintf (arqC, "%.1f\n", valorB);
}
}
else
{
//se o arquivo B terminou, copiar para C os elementos pendentes de A
fprintf (arqC, "%.1f\n", valorA);

while (fscanf (arqA, "%f", &valorA) != EOF)
{
fprintf (arqC, "%.1f\n", valorA);
}
}
}

//fechando os arquivos
fclose (arqA);
fclose (arqB);
fclose (arqC);

return TRUE;
}*/


/*
Lista V - Arquivos

Questão 07:
Desenvolver uma função que, dados dois arquivos textos arqA e arqB, crie um novo
arquivo arqC, considerando que:

- arqA e arqB contém números reais, um por linha, ordenados crescentemente e sem
repetição no arquivo;
- arqC deve conter apenas os números comuns aos dois arquivos originais;
- Assim como arqA e arqB, arqC também não possuirá repetições de elementos e estes
deverão estar ordenados de forma crescente.


//importação de bibliotecas
#include <stdio.h>

//definição de constantes
#define TRUE 1
#define FALSE 0

//protótipos das funções
int interseccao (char arquivo1[], char arquivo2[], char arqInterseccao[]);

//main
void main ()
{
//declaração de variáveis
char A[20], B[20], C[20];
int resp;

//lendo os nomes dos arquivos
fflush (stdin);
printf ("Nome do arquivo A: ");
gets (A);

fflush (stdin);
printf ("Nome do arquivo B: ");
gets (B);

fflush (stdin);
printf ("Nome do arquivo que armazenara a interseccao dos dois arquivos: ");
gets (C);

//chamando a função
resp = interseccao (A, B, C);

//exibindo o resultado
if (resp == FALSE)
{
printf ("\nErro na abertura dos arquivos!\n");
}
else
{
printf ("\nArquivo '%s' gerado com sucesso!\n", C);
}
}

//implementação das funções
int interseccao (char arquivo1[], char arquivo2[], char arqInterseccao[])
{
//declaração de variáveis
FILE *arqA, *arqB, *arqC;
float valorA, valorB;
int controleA, controleB;

//abrindo os três arquivos
arqA = fopen (arquivo1, "r");
arqB = fopen (arquivo2, "r");
arqC = fopen (arqInterseccao, "w");

//verificando se houve erro na abertura de algum arquivo
if ((arqA == NULL) || (arqB == NULL) || (arqC == NULL))
{
return FALSE; //erro na abertura
}

//as variáveis controle verificarão se algum arquivo (ou os dois) chegou ao final
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);

//verificando se algum arquivo chegou ao final
while ((controleA != EOF) && (controleB != EOF))
{
//verificando se o último valor lido do primeiro arquivo é menor do que o último
//lido do segundo
if (valorA < valorB)
{
//lendo o próximo valor do arquivo A
controleA = fscanf (arqA, "%f", &valorA);
}
else
{
//verificando se o último valor lido do segundo arquivo é menor do que o
//último lido do primeiro
if (valorB < valorA)
{
//lendo o próximo valor do arquivo B
controleB = fscanf (arqB, "%f", &valorB);
}
else
{
//se chegou aqui, os dois valores são iguais. Então, este valor deve ser
//inserido na interseccao (uma única vez)
fprintf (arqC, "%.1f\n", valorA);

//lendo os próximos valores dos dois arquivos
controleA = fscanf (arqA, "%f", &valorA);
controleB = fscanf (arqB, "%f", &valorB);
}
}
}

//se saiu do while, um dos arquivos (ou os dois) terminou. Então, énão há mais
//nada a fazer necessário, além de fechar os arquivos

//fechando os arquivos
fclose (arqA);
fclose (arqB);
fclose (arqC);

return TRUE;
}*/
