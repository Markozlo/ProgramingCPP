//Programa p37.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include<time.h>

#define MAX 80

typedef struct cliente
{
	int nconta;
	char nome[20];
	float limite; 
	float saldo;
}cliente;

FILE *arq ;
cliente cli;

char  opcao_menu ()
{
	system ("cls");
	printf ("(A)bertura de conta \n") ;
	printf ("(L)istagem de saldo \n");
	printf ("(D)eposito \n");
	printf ("(S)aque \n");
	printf ("(F)im \n");
	printf (" > ");
	return (toupper(getche()));
}

int encontra_conta(int n)
{
	fread(&cli,sizeof(cliente),1,arq); 
	while(!feof(arq))
	{
		if (cli.nconta == n)	
		{
			fseek(arq,-sizeof(cliente),SEEK_CUR);
			return 1;
		}
		fread (&cli,sizeof(cliente),1,arq);
	}
	return 0;
}

void abertura_conta()
{
	int num;
	arq = fopen("banco.dat","a+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf("Escolha o numero da contar: "); 
	scanf("%d", &num);
	if (encontra_conta(num) == 1)
		printf("\nEsta conta ja'axiste ! \n"); 
	else
	{
		cli.nconta = num;
		printf("Digite os seguintes dados: \n");
		printf("Nome do cliente .... ");
		fflush(stdin);
		gets(cli.nome);
		printf("Limite de credito ... ");
		scanf("%f", &cli.limite);
		printf("Saldo inicial ..... ");
		scanf("%f", &cli.saldo);
		fwrite(&cli,sizeof(cliente),1,arq);
		printf("Conta %d aberta.\n",num);
	}
	fclose(arq);
}

void listagem_saldo()
{
	int num;
	arq = fopen("banco.dat","r+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n"); 
		return;
	}
	printf("\n");
	printf("Numero da conta:");
	scanf ("%d", &num);
	if (encontra_conta(num) == 0)
		printf("\nEsta conta nao existe! \n"); 
		else
		{
			fread(&cli,sizeof(cliente),1,arq);
			printf ("\n");
			printf("--------+-----------+-----------+--------\n");			
			printf( "CONTA  |  CLIENTE  |  CREDITO  |  SALDO    \n");
			printf("--------+-----------+-----------+--------\n");			
			printf("%05d  |  %20s  |%9.2f | %9.2f  \n",cli.nconta,cli.nome,cli.limite,cli.saldo);
			printf("--------+-----------+-----------+--------\n");			
		}
	fclose(arq);
}

void deposito()
{
	int num;
	float valor;
	
	arq = fopen("banco.dat", "r+b"); 
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n"); 
		return;
	}
	printf("\n");
	printf("Numero da conta .... "); 
	scanf("%d", &num);
	if (encontra_conta(num) == 0)
		printf("\nEsta conta nao existe! \n");
	else
	{
		fread(&cli,sizeof(cliente),1,arq); 
		printf("Valor do deposito ... "); 
		scanf("%f", &valor);
		cli.saldo = cli.saldo + valor;
		fseek(arq,-sizeof(cliente),SEEK_CUR); 
		fwrite(&cli,sizeof(cliente),1,arq); 
		printf("Deposito efetuado.\n");
	}
	fclose(arq);
}

void saque()
{
	int num;
	float valor;
	
	arq = fopen("banco.dat", "r+b");
	if (arq == NULL)
	{
		printf("\Erro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf("Numero da conta .... ");
	scanf("%d", &num);
	if (encontra_conta(num) == 0)
		printf("\nEsta conta nao existe");
	else
	{
		fread (&cli,sizeof(cliente),1,arq); 
		printf("Valor do saque ...."); 
		scanf ("%f", &valor);
		if (cli.saldo+cli.limite >= valor)
		{
			cli.saldo = cli.saldo - valor;
			fseek(arq,-sizeof (cliente),SEEK_CUR ); 
			fwrite (&cli,sizeof(cliente),1,arq);
			printf ("Saque efetuado.\n");
		}
		else
			printf ("\nSaque excede o limite (MAX = %.2f)\n", cli.saldo + cli.limite);
	}
	fclose (arq);
}

int main (int args, char * arg [])
{
	char op;
	do
	{
		op = opcao_menu ();
		switch (op)
		{
			case 'A': abertura_conta (); break;
			case 'L': listagem_saldo(); break; 
			case 'D': deposito(); break;
			case 'S': saque(); break;
		}
		printf ("\n");
		system ("pause");
	}
	while (op != 'F');
	return 0;
}

