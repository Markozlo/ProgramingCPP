/*
5.	Escreva uma função que receba quatro notas de um aluno por parâmetro. 
Calcule e retorne sua Média Aritmética.
*/

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(int args, char * arg[])
{
	float nota1,nota2,nota3,nota4,Media;
	
	printf("Insira as notas do aluno: \n");
	scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4 );
	Media = (nota1+nota2+nota3+nota4)/4;
	printf("\nO resultado da media e: %.2f \n", Media);
	system("PAUSE");
	
}
