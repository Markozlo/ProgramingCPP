//Programa p29.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

float maior_nota(float **tab,int nlin, int ncol, int *numal, int *numav)
{
	int i,j;
	float m = -1.0;
	
	for (i = 0; i < nlin; i++)
		for (j = 0; j < ncol; j++)
			if (tab[i][j] > m)
			{
				m = tab[i][j];
				*numal = i;
				*numav = j;
			}
	return m;
}

float media_classe(float **tab, int nlin, int ncol)
{
	int i,j;
	float m = 0;
	
	for (i = 0; i < nlin; i++)
		for (j = 0; j < ncol; j++)
			m = m + tab[i][j];
	m = m / (i+j);		
	return m;
}

int main(int args, char*arg[])
{
	int i,j,nalunos,navalia;
	int numal,numav;
	float mnota,media;
	float **tabela;
	printf("Numero de alunos ....... ");
	scanf("%d ",&nalunos);
	printf("Numero de avaliacoes ... ");
	scanf("%d ",&navalia);
	
	//Alocar memoria para a tabela de notas
	tabela = (float**)calloc(nalunos,sizeof(float *));
	for (i = 0; i < nalunos; i++)
	tabela[i] = (float *)calloc(navalia,sizeof(float));
	
	//Iniializar gerador de numeros aleatorios
	srand((unsigned)time(NULL));
	
	//Preencher a tabela om notas aleatorias
	for (i = 0; i <nalunos; i++)
		for (j =0; j < navalia; j++)
			tabela[i][j] = rand() % 11;
			
	//Mostrar a tabela de notas
	printf("\nTabela de notas: \n");
	for (i= 0; i < nalunos; i++)
	{
		printf("%3d",i);
		for (j =0; j< navalia; j++)
			printf("%10.1f ",tabela[i][j]);
		printf("\n");
	}
	
	//Exibir a maior nota obtida e a media da classe 
	mnota = maior_nota(tabela,nalunos,navalia,&numal,&numav);
	printf("\nMaior nota = %.1f",mnota);
	printf(" - Obtida pelo aluno %d na avaliacao %d",numal,numav);
	media = media_classe(tabela,nalunos,navalia);
	printf("\nMedia das notas obtidas nas avaliacoes = %.1f",media);
	printf("\n");
	system("PAUSE");
	return 0;
}







