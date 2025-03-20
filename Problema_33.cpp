//Programa p33.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include<time.h>

#define TAM_MAX 50

int main(int args, char * arg[])
{
	int i,j,n;
	int **D;
	char op;
	FILE *arq;
	
	printf("Numero de nos do grafo: ");
	scanf("%d", &n);
	
	//Alocar memoria para a matriz de distancias
	D = (int **)calloc(n,sizeof(int *));
	for (i = 0; i < n; i++)
		D[i] = (int *)calloc(n,sizeof(int));
	
	//Gerar a matriz aleatoriamenete
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (i == j)
				D[i][j] = 0;
			else
			{
				D[i][j] = rand () % 100;
				D[j][i] = D[i][j];
			}
	
	//Exibir ou Gravar
	do
	{
		printf("\n(E)xibir ou (G)ravar a matriz gerada? ");
		op = toupper(getche());
		if ( op == 'E')
			arq = stdout;
		else 
		if ( op == 'G')
			arq = fopen("dados33.txt","w");			
	}
	while ((op != 'E') && (op != 'G'));
	
	printf("\n");
	fprintf(arq,"%d\n",n);
	for (i =0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			fprintf(arq,"%2d ",D[i][j]);
		fprintf(arq,"\n");
	}
	system("pause");
	return 0;
}
