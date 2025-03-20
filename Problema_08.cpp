#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maiorValor(int idade1, int idade2)
{
	if (idade1 > idade2)
		return idade1;
	else
		return idade2;
}

int maiorQuem(int idade1, int idade2)
{
	if (idade1 > idade2)
		return 1;
	else
		return 2;
}

int menorValor(float peso1, float peso2)
{
	if (peso1 < peso2)
		return peso1;
	else
		return peso2;
}

int menorQuem(float peso1, float peso2)
{
	if (peso1< peso2)
		return 1;
	else
		return 2;
}

int main(int argc, char *argv[])
{
	int idade1,idade2,maior_idade;
	int mais_velho,mais_leve;
	float peso1,peso2,menor_peso;
	printf("Digite a idade e o peso da pessoa 1: ");
	scanf("%d %f", &idade1,&peso1);
	printf("Digite a idade e o peso da pessoa 2: ");
	scanf("%d %f", &idade2,&peso2);
	//Substitui todas as condições
	maior_idade = maiorValor(idade1,idade2);
	mais_velho  = maiorQuem(idade1,idade2);
	menor_peso  = menorValor(peso1,peso2);
	mais_leve   = menorQuem(peso1,peso2);
	//fim das subrotinas
	printf("Maior idade = %d (da pessoa %d)\n",
		maior_idade,mais_velho);
	printf("Menor peso = %.1f (da pessoa %d)\n",
		menor_peso,mais_leve);
	system ("PAUSE");
	return 0;
}
