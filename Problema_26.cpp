//Programa p26.c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

#define TAM_MAX 50

void quicksort (int v[], int primeiro, int ultimo)
{
	int i,j;
	int m,aux;
	
	i = primeiro;
	j = ultimo;
	m = v[(i+j)/2];
	do
	{
		while (v[i] < m) i++;
		while (v[j] < m) j--;
		if (i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	}
	while (i <=j);
	if (primeiro < j)
		quicksort(v,primeiro,j);
	if (ultimo > i)
		quicksort (v,i,ultimo);
}

int main(int args, char * arg[])
{
	int i,n,a[TAM_MAX];
	
	//Inicializar gerador de numeros aleatorios
	srand((unsigned)time(NULL));
	
	//Vetor gerado aleatoriamente
	n = (rand() % TAM_MAX) +1;
	printf("Vetor original: ");
	for (i = 0;i < n; i++)
	{
		a[i] = (rand() % 100);
		printf("%d ", a[i]);
	}
	printf("\n");
	
	//Classificar vetor
	quicksort(a,0,n-1);
	printf("Vetor ordenado: ");
	for (i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}




