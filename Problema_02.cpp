#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv)
{
	float d,p,s,t;
	
	d= 500;	//deposito inicial
	//apos primeiro mes
	p = d + 0.01*d;
	//apos segundo mes
	s = p + 0.01*p;
	//apos terceiro mes
	t = s + 0.01*s;
	printf("Valor da conta = %.2f\n",t);
	system ("PAUSE");
	return 0;
	
}
