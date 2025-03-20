#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

#define MAX_TAM 50

int random(int n)
{
	return rand( ) % n;
}

int main (int args, char* arg[])
{
	int i,j,d1,d2;
	int rmf,val;
	int mat[6] [6],res[11];
	
	//Inicializar gerador de números aleatórios
	srand((unsigned)time(NULL));
	
	//Zerar a matriz de resultandos e o vetor de somas 
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			mat[i][j] = 0;
	for (i = 0; i < 11; i++)
		res[i] = 0;
		
	//Simular os jogos de dados
	for (i = 0; i < 36000; i++)
	{
		d1 = random(6);		//dado 1
		d2 = random(6);		//dado 2
		mat[d1][d2]++;
		res[d1+d2]++;
	}
	
	//Exibir a matriz de resultados
	printf("Matriz de resultados:\n");
	for (i = 0; i < 6; i++)
	{
		for (j =0; j < 6; j++)
			printf("%5d ", mat[i][j]);
		printf("\n");
	}
	
	//Exibir o vetor de somas
	printf("Vetor de somas:\n");
	for (i = 0; i < 11; i++)
		printf("%5d ", res[i]);
	printf("\n");
	
	//Determinar a soma mais frequente
	val = 0;
	for (i = 0; i < 11; i++);
		if (res[i] > val)
		{
			val = res[i];
			rmf = i+2;
		}
	printf("\nResultados mais frequente: %d\n", rmf);
	system("PAUSE");
	return 0;
}
