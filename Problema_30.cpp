//Programa p30.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

typedef struct pessoa
{
	char nome[21];
	int idade;
	float peso,altura;
}

pessoa;

pessoa nova_pessoa()
{
	pessoa p;	
	fflush(stdin);
	printf("Nome .... ");
	gets(p.nome);
	printf("Idade .... ");
	scanf("%d ", &(p.idade));
	printf("Peso .... ");
	scanf("%f ", &(p.peso));
	printf("Altura ... ");
	scanf("%f ", &(p.altura));
	return p;
}

int main(int args,char *arg[])
{
	int i,n;
	pessoa *cad;
	
	printf("Numero de pessoas: ");
	scanf("%d ",&n);
	cad = (pessoa *)calloc(n,sizeof(pessoa));
	for (i = 0; i < n; i++)
	{
		printf("\nPessoa %d:\n", i+1);
		cad[i] = nova_pessoa();
	}	
	printf("\nCadastro atual:\n");
	printf("\nNome                            Idade     Peso     ALtura");
	printf("\n____________________________\n");
	for (i =0; i < n; i++)
		printf("\n%20s           %5d   %5.1f   %7.2f", cad[i].nome,cad[i].idade,cad[i].peso,cad[i].altura);
		printf("\n\n\n");
		system("PAUSE");
		return 0;
}








