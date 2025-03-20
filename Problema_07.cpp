#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int idade1,idade2,maior_idade;
	int mais_velho,mais_leve;
	float peso1,peso2,menor_peso;
	printf("Digite a idade e o peso da pessoa 1: ");
	scanf("%d %f", &idade1,&peso1);
	printf("Digite a idade e o peso da pessoa 2: ");
	scanf("%d %f", &idade2,&peso2);
	if (idade1 > idade2)
	{
		maior_idade = idade1;
		mais_velho = 1;
	}
	else
	{
		maior_idade = idade2;
		mais_velho = 2;
	}
	if (peso1 < peso2)
	{
		menor_peso = peso1;
		mais_leve = 1;
	}
	else
	{
		menor_peso = peso2;
		mais_leve = 2;
	}
	printf("Maior idade = %d (da pessoa %d)\n",
		maior_idade,mais_velho);
	printf("Menor peso = %.1f (da pessoa %d)\n",
		menor_peso,mais_leve);
	system ("PAUSE");
	return 0;
}
