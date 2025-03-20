#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

#define PRODUTOS 200
#define CLIENTES 50

int random(int n)
{
	return rand( ) % n;
}

int main (int args, char* arg[])
{
	int i,j,p,npro,ncli;
	int compra[CLIENTES];
	float preco[PRODUTOS];
	float total;
	
	//Inicializar gerador de n�meros aleat�rios
	srand((unsigned)time(NULL));
	
	//Pre�os dos produtos
	npro = 1 + random(PRODUTOS);	//n�mero de produtos
	for (i = 0; i < npro; i++)
	{
		p = 5 + random(96);
		preco[i] = p;				//pre�o do produto
	}
	
	//Simular movimeneto de um dia
	ncli = 1 + random(CLIENTES);	//n�mero de clientes
	printf("Simulacao para :\n %3d produtos\n %3d clientes\n", npro, ncli);
	for (i = 0; i < ncli; i++)
	{
		j = random(npro);			//n�mero de produtos
		compra[i] = j;
	}
	
	// Exibir resultado da simula��o
	total = 0;
	printf("____________________________\n");
	printf("Cliente		Produto				Valor (R$)\n");
	printf("_____________________________\n");
	for (i = 0; i < ncli; i++)
	{
		printf(" %3d		%3d				%7.2f\n", i, compra[i], preco[compra[i]]);
		total += preco[compra[i]];
	}
	printf("____________________________\n");
	printf("TOTAL DE VENDAS		%7.2f\n", total);
	
	system("PAUSE");
	return 0;
}
