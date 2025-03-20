#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

#define TAM_CLASSE 100

#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))

int main (int args, char* arg[])
{
	int i, n, abaixo;
	float nota[TAM_CLASSE];
	float maior = -1, menor = 11, media = 0;
	
	printf("Numero de alunos (maximo = %d):", TAM_CLASSE);
	scanf("%d", &n); 
	for (i = 0; i < n; i++)
	{
		printf("Nota do aluno %d: ", i);
		scanf("%f", &nota[i]);
		maior = MAX(maior,nota[i]);
		menor = MIN(menor,nota[i]);
		media = media + nota[i];			
	}	
	
	media = media / n;
	
	abaixo = 0;
	for (i = 0; i < n; i++)	
		if (nota[i] < media)
			abaixo++;
		
	printf("\n");
	printf("Maior nota obtida.................... %.1f\n", maior);
	printf("Menor nota obtida.................... %.1f\n", menor);
	printf("Media das notas obtidas.............. %.1f\n", media);
	printf("Alunos abaixo da media............... %.1f\n", abaixo);
	system("PAUSE");
	return 0;
	
	
	
	
}
