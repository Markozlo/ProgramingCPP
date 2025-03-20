/* 
5. Faça um programa que leia: o ano atual, o ano de nascimento de uma pessoa, calcule e mostre
sua idade. Em seguida mostre se ela já tem idade para votar (16 anos ou mais) e para
conseguir a Carteira de Habilitação (18 anos ou mais)
*/

#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	
	int anoAtual,anoNasc,idade;
	
	cout << "\nDigite ano atual e o ano de nascimento: \n";
	cin >> anoAtual;
	cin >> anoNasc;
	
	idade = anoAtual - anoNasc;	
	cout << "\nA idade eh: \n" << idade;
		
	if (idade > 15)
	{
		if (idade > 17)
		{
			cout << "\nJa pode votar e conseguir carteira de habilitacao\n";
		}
		else
		{
			cout << "\nPodera apenas votar!\n";
		}
	}
	 else
	 {
	 	cout << "\nIdade menor que 16 anos\n";
	 }
	
	getch();
	return 0;
}

