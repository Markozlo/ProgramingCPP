//Programa p40.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

typedef struct data
{
	unsigned dia:5;
	unsigned mes:4;
	unsigned ano:12;
}data;

typedef struct datas
{
	data nascimento;
	data inicio;
	data saida;
}datas;

FILE *arq;
datas func;

char opcao_menu()
{
	system("cls");
	printf(" (C)adastrar funcionario\n");
	printf(" (M)odificar datas\n");
	printf(" (L)istar arquivo\n");
	printf(" (F)im\n");
	printf(" > ");
	return (toupper(getche()));
}

void ler_data(char *s, data *d)
{
	unsigned dia,mes,ano;
	
	printf("%s",s);
	scanf("%d/%d/%d",&dia,&mes,&ano);
	(*d).dia = dia;
	(*d).mes = mes;
	(*d).ano = ano;
}

int num_registros()
{
	fseek(arq,0,SEEK_END);
	return(ftell(arq)/sizeof(datas));
}

void cadastrar_func()
{
	int num;
	
	arq = fopen("datas.dat","a+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n");
		return;
	}
	memset(&func,0,sizeof(datas));
	fwrite(&func,sizeof(datas),1,arq);
	num = num_registros();
	printf("\nFuncionario %d cadastrado!\n",num);
	fclose(arq);
}

void modificar_datas()
{
	int num;
	
	arq = fopen("data.dat","r+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf("Numero do funcionario: ");
	scanf("%d",&num);
	if ((num >= 1) && (num <= num_registros()))
	{
		ler_data(" Nascimento...............",&func.nascimento);
		ler_data(" Inicio na empresa........",&func.inicio);
		ler_data(" Saida da empresa.........",&func.saida);
		
		fseek(arq,(num-1)*sizeof(datas),SEEK_SET);
		fwrite(&func,sizeof(datas),1,arq);
		printf("Data registradas! \n");		
	}
	else
		printf("Funcionario nao existe");
	fclose(arq);
}

void listar_arquivo()
{
	#define MAX_LINHAS 5
	int num,lin,pag;
	
	arq = fopen("data.dat","r+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo");
		return;
	}
	
	num = 0;
	pag = 0;
	lin = MAX_LINHAS;
	fread(&func,sizeof(datas),1,arq);
	while(!feof(arq))
	{
		if (lin == MAX_LINHAS)
		{
			lin = 0;
			pag++;
			system("Cls");
			printf("LISTAGEM DO ARQUIVO DE DATAS    Pag. %03d\n",pag);
			printf("+-------+-------------+---------+-------+\n");
			printf("|FUNC   |NASCIMENTO   |INICIO   |SAIDA  |\n");
			printf("+-------+-------------+---------+-------+\n");
		}
		num++;
		lin++;
		printf("|%04d   |%02d/%02d/%04d|%02d/%02d/%04d|%02d/%02d/%04d|\n",
				num,func.nascimento.dia,func.nascimento.mes,func.nascimento.ano,
				func.inicio.dia,func.inicio.mes,func.inicio.ano,
				func.saida.dia,func.saida.mes,func.saida.ano
				);
		fread(&func,sizeof(datas),1,arq);
		if (feof(arq)  || (lin == MAX_LINHAS))
		{
			printf("+-------+-------------+---------+-------+\n");
			if(!feof(arq))
				system("Pause");
		}
	}
	fclose(arq);
}

int main(int args, char *argv[])
{
	char op;
	
	do
	{
		op = opcao_menu();
		switch(op)
		{
			case 'C' : cadastrar_func();break;
			case 'M' : modificar_datas();break;
			case 'L' : listar_arquivo();break;
		}
		printf("\n");
		system("Pause");
	}
	while (op != 'F');
	return 0;	
}

