//Programa p36.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include<time.h>

#define MAX 80

char opcao_menu()
{
	system("cls");
	printf("(N)ovo aluno\n");
	printf("(L)istar notas\n");
	printf("(M)odificar notas\n"); 
	printf("(F)im\n");
	printf(" > ");
	return (toupper(getche()));
}

void listar_notas()
{
	int num,notas; 
	float n1,n2,media; 
	char *nome;
	char buf[MAX];
	FILE *arq;
	
	arq = fopen("dados36.txt","r");
	if (arq == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf("NUM    |  NOME   |   Nl   |   N2   \n");
	printf("-------+---------+--------+--------\n");
	notas = 0;
	media = 0;
	fgets(buf,MAX,arq);
	while(!feof(arq))
	{
		num = atoi(strtok(buf,","));
		nome = strtok(NULL ,",");
		n1  = atof (strtok(NULL ,","));
		n2  = atof (strtok(NULL ,","));
		printf ("%03d  |  %20s  |  %4.lf  |  %4.1f\n",num,nome,n1,n2);
		notas = notas +   2;
		media = media + n1 + n2; 
		fgets(buf,MAX ,arq);
	}
	printf("-------+---------+--------+--------\n");
	media = media/notas;
	printf("Media das notas = %4.1f\n", media);
	fclose( arq);
}

void novo_aluno()
{
	int num;
	float n1,n2;
	char nome[20];
	FILE *arq;
	
	arq = fopen ("dados35.txt","a");
	if (arq == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf("Digite os dados do novo aluno: \n");
	printf("Numero ... ");
	scanf("%d", &num);
	printf("Nome .... ");
	fflush(stdin);
	gets(nome);
	printf("Nota l ... ");
	scanf("%f",&n1);
	printf("Nota 2 ... ");
	scanf("%f ",&n2);
	fprintf (arq,"%d, %s, %.lf, %. lf\n",num,nome,n1,n2);
	fclose (arq);
}

void modificar_notas()
{
	int num,na,achei;
	float n1,n2 ; 
	char *nome; 
	char buf[MAX];
	FILE *arq ,*tmp;
	
	arq = fopen("dados36.txt","r"); 
	if ( arq == NULL)
	{
		printf("Erro ao abrir arquivo\n");
		return;
	}
	printf ("\n");
	printf ("Digite	o numero do aluno:	");
	scanf ("%d", &na);
	achei =  0;
	fgets(buf,MAX,arq);
	while (!feof(arq))
	{
		num  = atoi(strtok(buf,","));
		nome = strtok(NULL,",");
		n1   = atof(strtok(NULL,","));
		n2   = atof(strtok(NULL,","));
		if  (num == na)
		{
			achei = 1;
			printf("\n");
			printf( "NUM  |  NOME  |  N1  |  N2    \n");
			printf("------+--------+------+--------\n");
			printf("%03d  |  %20s  |%4.lf | %4.lf  \n",num,nome,n1,n2);
			printf("------+--------+------+--------\n");
			printf("Digite as novas notas:\n"); 
			printf("Nota 1 ... ");
			scanf("%f", &n1); 
			printf("Nota 2 ... "); 
			scanf("%f", &n2);
			fprintf(tmp,"%d,%s,%.lf,%.lf\n",num,nome,n1,n2);
		}
		else
			fprintf(tmp,"%d,%s,%.lf,%.lf\n",num,nome,n1,n2);
		fgets(buf,MAX,arq);
	}
	fclose(arq); 
	fclose(tmp);
	if (achei == 0)
		printf("Aluno %d nao existe.",na);
	else
	{
		remove ("dados36.txt");
		rename ("temp.txt","dados36.txt");
	}
}

int main()
{
	char op;
	
	do
	{
		op = opcao_menu();
		switch(op)
		{
			case 'L' : listar_notas(); break;
			case 'N' : novo_aluno(); break;
			case 'M' : modificar_notas(); break;
		}
		printf("\n");
		system("pause");
	}
	while (op != 'F');
	return 0;
}

