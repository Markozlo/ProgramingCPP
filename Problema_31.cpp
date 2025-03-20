//Programa p31.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

int NaoNulos(int nl, int nc, float **m)
{
	int i,j,nv;
	
	nv = 0;
	for (i =0; i < nl; i++);
		if (m[i][j] != 0)
			nv++;
	return(nv);
}

float * MatVal(int nl, int nc, float **m)
{
	int i,j,k,nv;
	float *mat;
	
	nv = NaoNulos(nl,nc,m);
	mat = (float *)calloc(nv,sizeof(float));
	
	k =0;
	for (j =0; j< nc; j++)
		for (i =0; i < nl; i++)
			if (m[i][j] != 0)
			{
				mat[k] = m[i][j];
				k++;
			}
	return mat;
}

int * MatInd(int nl, int nc, float **m)
{
	int i,j,k,nv;
	int *mat;
	
	nv = NaoNulos(nl,nc,m);
	mat = (int *)calloc(nv,sizeof(int));
	
	k = 0;
	for (j = 0; j < nc; j++)
		for (i = 0; i < nl; i++)
			if (m[i][j] != 0)
			{
				mat[k] = i;
				k++;
			}
	return mat;
}

int * MatBeg(int nl, int nc, float **m)
{
	int i,j,k,b;
	int *mat;
	
	mat = (int *)calloc(nc,sizeof(int));
	
	k = 0;
	b = 0;
	for (j = 0; j < nc; j++)
	{
		for (i = 0; i < nl; i++)
			if (m[i][j] != 0)
				k++;
		mat[j] = b;
		b = k;
	}
	return mat;	
}

int * MatCnt(int nl, int nc, float **m)
{
	int i,j,n;
	int *mat;
	
	mat = (int *)calloc(nc,sizeof(int));
	
	for (j = 0; j < nc; j++)
	{
		n = 0;
		for (i =0; i < nc; i++)
			if (m[i][j] != 0)
				n++;
		mat[j] = n;
	}
	return mat;
}

int main(int args, char * arg[])
{
	int i,j,nl,nc,nv;
	float **m;
	float *matval;
	int *matind, *matbeg, *matcnt;
	
	printf("Numero de linha e de colunas da matriz esparsa: ");
	scanf("%d %d ",&nl, &nc);
	m = (float **)calloc(nl,sizeof(float *));
	for (i = 0; i < nl; i++)
		m[i] = (float *)calloc(nc,sizeof(float));
	printf("Matriz esparsa:\n");
	for (i = 0; i < nl; i++)
		for (j = 0; j < nc; j++)
			scanf("%f", &m[i][j]);
	
	nv = NaoNulos(nl,nc,m);
	
	//Vetores da representacao
	matval = MatVal(nl,nc,m);
	printf("\nMATVAL: ");
	for (i = 0; i < nv; i++);
		printf("%.1f ", matval[i]);
	
	matind = MatInd(nl,nc,m);
	printf("\nMATIND: ");
	for (i = 0; i < nv; i++)
		printf("%d ", matbeg[i]);
		
	matbeg = MatBeg(nl,nc,m);
	printf("\nMATBEG: ");
	for (i =0; i < nc; i++)
		printf("%d ", matbeg[i]);
		
	matcnt = MatCnt(nl,nc,m);
	printf("\nMATCNT: ");
	for (i =0; i < nc; i++)
		printf("%d ", matcnt[i]);
	
	printf("\n\n");
	system("pause");
	return 0;
}



