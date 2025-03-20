//Programa Programa39.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sys\stat.h>
#include <fcntl.h>

#define MAX 256

typedef struct disponivel
{
	int nvezes;
}disponivel;

typedef struct emprestado
{
	int leitor;
	int dia;
	int mes;
	int ano;
}emprestado;

typedef  struct livro
{
	int num;
	char tit [21];
	int status;
	union
	{
		disponivel disp;
		emprestado empr;
	};
}livro;
	
FILE *arq;
livro liv;

char opcao_menu()
{
	system("cls");
	printf ("(A)tualizar acervo\n");
	printf ("(L)istar acervo\n");
	printf ("(E)mprestar livro\n");
	printf ("(R)eceber livro\n");
	printf ("(F)im\n");
	printf (" > ");
	return (toupper(getche ()));
}

int encontra_livro(int n)
{
	fread(&liv,sizeof(livro),1,arq);
	while (!feof(arq))
	{
		if (liv.num == n)
		{
			fseek(arq,-sizeof(livro),SEEK_CUR);
			return 0;
		}
		fread (&liv,sizeof(livro),1,arq);
	}
	return 0;
}

void atualizar_acervo()
{
	int num;
	
	arq = fopen("acervo.dat","a+b");
	if (arq == NULL)
	{
		printf ("\nErro ao abrir arquivo\n");
		return;
	}
	printf ("\n");
	printf ("Numero do livro:"); 
	scanf  ("%d", &num);
	if (encontra_livro(num) == 1)
		printf("Ja existe livro com este numero!\n");
	else
	{
		liv.num = num;
		printf ("Titulo do livro:");
		fflush (stdin); 
		gets(liv.tit);
		liv.status = 0;    //livro disponível
		liv.disp.nvezes = 0; //número de empréstimos
		fwrite (&liv,sizeof(livro),1,arq);
		printf("Livro %d incorporado ao acervo.\n",num);
	}
	fclose(arq);
}

void listar_acervo()
{
	#define MAX_LINHAS 5
	int lin,pag;
	
	arq = fopen("acervo.dat","r+b");
	if (arq == NULL)
	{
		printf("\Erro ao abrir arquivo\n");	
		return;
	}
	
	pag = 0;
	lin = MAX_LINHAS;
	fread(&liv,sizeof(livro),1,arq);
	while (!feof(arq))
	{
		if (lin == MAX_LINHAS)
		{
			lin = 0;
			pag++;
			system("Cls");
			printf("LISTAGEM DO ACERVO %24s Pag. %03d\n"," " ,pag); 
			printf("+--------- +--------+------+------+\n");
			printf("|   NUM    |TITULO  | STT  |INFORMACAO  |\n");
			printf("+--------- +--------+------+------+\n");
		}
		lin++;
		printf("| %05d | %20s | ",liv.num,liv.tit);
		if (liv.status == 0)
		{
			printf(" D    |    E:%04d		|\n",liv.disp.nvezes);
		}
		else
		{
			printf("  E  |  D:%02d/%02d/%04d  |  \n",liv.empr.dia,liv.empr.mes,liv.empr.ano);
		}
		fread(&liv,sizeof(livro),1,arq);
		if (feof(arq)   ||   (lin == MAX_LINHAS))
		{
			printf("+--------- +--------+------+------+\n");
			if (!feof(arq))
				system("Pause");
		}
	}
	fclose(arq);
}

void emprestar()
{
	int num;
	
	arq = fopen("acervo.dat","r+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n"); 
		return;
	}
	printf("\n");
	printf("Numero do livro .....  ");
	scanf("%d",&num);
	if (encontra_livro(num)==0)
		printf("Este livro nao existe!\n");
	else
	{
		fread (&liv,sizeof(livro),1,arq);
		if (liv.status == 1)
			printf("Livro ja emprestado (devolucao ate %02d,/%02d/%04d)\n",
					liv.empr.dia,liv.empr.mes,liv.empr.ano);
		else
		{
			liv.status = 1;
			liv.empr.leitor = liv.disp.nvezes + 1;
			printf("Data de devolucao ... ");
			scanf("%d/%d/%d",&liv.empr.dia,&liv.empr.mes,&liv.empr.ano);
			fseek(arq,-sizeof(livro),SEEK_CUR);
			fwrite(&liv,sizeof(livro),1,arq);
			printf("Emprestimo OK!\n");
		}
	}
	fclose(arq);
}

void receber()
{
	int num;
	
	arq = fopen("acervo.dat","r+b");
	if (arq == NULL)
	{
		printf("\nErro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf("Numero do livro .... ");
	scanf("%d",&num);
	if (encontra_livro(num) == 0)
		printf("Este livro nao existe");
	else
	{
		liv.status = 0;
		liv.disp.nvezes = liv.empr.leitor;
		fseek(arq,-sizeof(livro),SEEK_CUR);
		fwrite(&liv,sizeof(livro),1,arq);
		printf("Devolucao OK!\n");
	}
	fclose(arq);
}

int main(int args, char *argv[])
{
	char op;
	
	do
	{
		op = opcao_menu();
		switch (op)
		{
			case 'A' : atualizar_acervo();break;
			case 'L' : listar_acervo();break;
			case 'E' : emprestar();break;
			case 'R' : receber();break;
		}
		printf("\n");
		system("Pause");
	}
	while (op != 'F');
	return 0;
}
