#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int x;
	short int y;
	char a;
	unsigned char b;
	
	x = pow(2,31)-1; // maior int possivel
	y = pow(2,15)-1; //maoior short int possivel
	printf("x = %d	y = %d\n",x,y);
	x = x + 1;
	y = y + 1;
	printf("x = %d	y = %d\n",x,y);
	/*_________________
		Atribuir os maiores valores possiveis
		para as variaveis a e b.
		_______________________*/
	
	a = pow(2,7)-1;
	b = pow(2,15)-1;
	printf("a = %d	b = %d\n", a,b);
	a = a + 1;
	b = b + 1;
	printf("a = %d	b = %d\n",a,b);
	system ("PAUSE");
	return 0;

}
