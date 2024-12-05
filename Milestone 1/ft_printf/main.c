#include <stdio.h>
#include "ft_printf.h"

//TODO Please recode the others functions first xd

int main()
{	
	int var = 42;
	printf("%c\n", 'a');
	printf("%s\n", "Hello World");
	printf("%p\n",&var);
	printf("%d\n", 10);
	printf("%i\n", 10);
	printf("%u\n", 99);
	printf("%x\n", 10);
	printf("%X\n", 10);
	printf("%%\n");

	ft_printf("%c\n", 'a');
	ft_printf("%s\n", "Hello World");
	ft_printf("%d\n", 10);
	ft_printf("%p\n",&var);
	ft_printf("%i\n", 10);
	ft_printf("%u\n", 99);
	ft_printf("%x\n", 10);
	ft_printf("%X\n", 10);
	ft_printf("%%\n");
}