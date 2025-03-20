//Programa p35.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include<time.h>

#define MAX 80

char opcao_menu()
{
	system ("cls");
	printf ("(N)ovo aluno\n");
	printf ("(L)istar notas\n");
	printf ("(F)im\n");
	printf (" > ");
	return (toupper(getche()));
}

void listar_notas()
{
	int num,notas; 
	float n1,n2,media; 
	char *nome;
	char buf[MAX];
	FILE *arq;
	
	arq = fopen("dados35.txt", "r");
	if (arq == NULL )
	{
		printf ("Erro ao abrir arquivo\n");
		return;
	}
	printf("\n");
	printf( "NUM  |  NOME  |  N1  |  N2    \n");
	printf("------+--------+------+--------\n");
	notas = 0;
	media = 0;
	
	fgets(buf,MAX,arq);
	while (!feof(arq))
	{
		num = atof(strtok(buf,","));					
		nome = strtok(NULL, ",") ;					
		n1 = atof(strtok(NULL ,","));					
		n2 = atof(strtok(NULL ,","));
		printf("%03d | %20s | %4.lf |  %4.lf\n",num,nome ,n1,n2);		
		notas = notas + 2 ;
		media = media + n1 + n2;
		fgets(buf,MAX,arq);
	}
	
	printf("------+--------+------+--------\n");
	media = media / notas;
	printf("Media das notas = %4.lf \n",media);
	fclose(arq);
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

int main(int args, char * arg ())
{
	char op;

	do
	{
		op = opcao_menu();
		if (op == 'L')
			listar_notas();
		if (op == 'N' )
			novo_aluno();
		printf("\n");
		system("pause");
	}
	while (op != 'F'); 
	return 0;
}
