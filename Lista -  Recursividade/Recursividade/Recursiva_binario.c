//Quest�o 03: Fazer uma fun��o recursiva que,
//dado um n�mero inteiro N, exiba o mesmo na
//base 2 (bin�ria).

void main()
{
	int n;
	
	printf("Digite um numero : ");
	scanf("%d",&n);
	
	binario(n);
}

int binario(n)
{
	int resp,soma;
	
	//printf("%d",n);
	
	if(n==0)
	{
		
		printf("%d",n);
	}else{
		resp= binario(n/2);
		soma=n%2;
		printf("%d",soma);
	}
	return;
}
