#include <stdio.h>
#include "ft_printf.h"
void put_it(int a, int b)
{
    printf("Return values: ft_printf = %d, printf = %d\n\n", a, b);
}

int main(void)
{
    int ret_ft, ret_orig;

    ret_ft = ft_printf("Test 1.1: Char: %p\n", NULL);
    ret_orig = printf("Test 1.2: Char: %p\n", NULL);
    put_it(ret_ft, ret_orig);
    return 0;
}

