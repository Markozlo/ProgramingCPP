//Programa p24.c
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double soma (char v[], ...)
{
	va_list p_args;
	double resultado = 0;
	
	va_start (p_args, v);
	while (*v)
	{
		if (*v == '%')
		{
			v++;
			switch (*v)
			{
				case 'd': resultado += va_arg(p_args,int);break;
				case 'f': resultado += va_arg(p_args,double);break;
			}
		}
		v++;
	}
	va_end(p_args);
	return resultado;
}

//void main()
int main(int args, char* arg[])

{
	printf ("Soma de ...\n");
	printf (" 1 numero = %7.2f\n", soma ("%f",1.1));
	printf (" 2 numeros = %7.2f\n", soma ("%f %d",1.1,3));
	printf (" 3 numeros = %7.2f\n", soma ("%f %d %d",1.1,3,5));
	printf (" 4 numeros = %7.2f\n", soma ("%f %d %d %f",1.1,3,5,7.7));
	system("PAUSE");	
}






