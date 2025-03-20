//Programa p32.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

int main(int args, char * arg[])
{
	int i,j,nl,nc;
	int **ma, **mb, **ms;
	FILE *arq;
	
	arq = fopen("dados32.txt", "r");
	if (arq == NULL)
	{
		printf("Erro ao abrir o arquivo de dados\n");
		system("pause");
		return 1;
	}
	
	//Leitura das dimensoes a partir do arquivo
	fscanf(arq,"%d %d",&nl,&nc);
	
	//Alocar memoriapara as matrizes
	ma = (int **)calloc(nl,sizeof(int **));
	for (i =0; i < nl; i++)
		ma[i] = (int *)calloc(nc,sizeof(int));
	mb = (int **)calloc(nl,sizeof(int *));
	for (i =0; i < nl; i++)
		mb[i] = (int *)calloc(nc,sizeof(int));
	
	//Ler as matrizes a partir  do arquivo
	for (i =0; i < nl; i++)
		for (j =0; j < nc; j++)
			fscanf(arq,"%d", &ma[i][j]);
	for (i=0; i < nl; i++)
		for (j = 0; j < nc; j++)
			fscanf(arq,"%d",&mb[i][j]);
	
	fclose (arq);
	
	//Mostrar as matrizes lidas
	printf("Matrizes dadas:\n");
	for (i = 0; i < nl; i++)
	{
		for (j = 0; j < nc; j++)
			printf("%2d ", ma[i][j]);
		printf("		");
		for (j = 0; j < nc; j++)
			printf("%2d ", mb[i][j]);
		printf("\n");
	}
	
	//Alocar memoria para matriz soma
	ms = (int **)calloc(nl,sizeof(int *));
	for (i = 0; i < nl; i++)
		ms[i] = (int *)calloc(nc,sizeof(int));
	
	//Calcular Matriz soma
	for (i = 0; i < nl; i++)
		for (j = 0; j < nc; j++)
			ms[i][j] = ma[i][j] + mb[i][j];
			
	//Mostrar matriz soma
	printf("\nMatriz soma: \n");
	for (i = 0; i < nl; i++)
	{
		for (j = 0; j < nc; j++)
			printf("%2d ", ms[i][j]);
		printf("\n");	
	}	
	printf("\n");
	system("pause");
	return 0;
}
