#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX_TAM 50

int random(int n)
{
	return rand( ) % n;
}

int existe (int n, int v[], int k)
{
	int i;
	
	for (i = 0; i < n; i++)
		if (v[i] == k)
			return 1;
	return 0;
}

int main (int args, char* arg[])
{
	int i, j, n, r;
	int vet[MAX_TAM], pos[MAX_TAM], v_ord[MAX_TAM];
	
	//Inicializar gerador de numeros aleatórios
	srand((unsigned)time(NULL));
	
	//Gerar o vetor inicial
	n = random(MAX_TAM) +1;			//tamanho do vetor
	i = 0;
	do
	{
		r = random(100) +1;
		if (existe(i,vet,r) == 0)
		{
			vet[i] = r;
			i++;
		}
	}
	while (i < n);
	printf("Vetor inicial:\n");
	for (i = 0; i < n; i++);
		printf("%d ", vet[i]);
	printf("\n\n");
	
	//Determinar posição no vetor ordenado
	for (i = 0; i < n; i++)
	{
		pos[i] = 0;
		for (j = 0; j < n; j++);
			if (vet[i] > vet[j])
				pos[i]++;
		v_ord[pos[i]] = vet[i];
	}
	
	//Exibir o vetor ordenado
	printf("Vetor ordenado:\n");
	for (i = 0; i < n; i++)
		printf("%d ", v_ord[i]);
	printf("\n\n");
	system("PAUSE");
	return 0;
}
