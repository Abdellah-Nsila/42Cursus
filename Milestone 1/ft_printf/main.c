#include <stdio.h>
#include "ft_printf.h" // Include your ft_printf header
void put_it(int a, int b)
{
    printf("Return values: ft_printf = %d, printf = %d\n\n", a, b);
}
int main(void)
{
    int ret_ft, ret_orig;

    // Test 1-5: Characters
    ret_ft = ft_printf("Test 1: Char: %c\n", 'A');
    ret_orig = printf("Test 1: Char: %c\n", 'A');
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 2: Char (null): %c\n", '\0');
    ret_orig = printf("Test 2: Char (null): %c\n", '\0');
    put_it(ret_ft, ret_orig);

    // Test 6-10: Strings
    ret_ft = ft_printf("Test 6: String: %s\n", "Hello, World!");
    ret_orig = printf("Test 6: String: %s\n", "Hello, World!");
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 7: String (empty): %s\n", "");
    ret_orig = printf("Test 7: String (empty): %s\n", "");
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 8: String (null): %s\n", (char *)NULL);
    ret_orig = printf("Test 8: String (null): %s\n", (char *)NULL);
    put_it(ret_ft, ret_orig);

    // Test 11-15: Integers (signed)
    ret_ft = ft_printf("Test 11: Integer: %d\n", 42);
    ret_orig = printf("Test 11: Integer: %d\n", 42);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 12: Integer (negative): %d\n", -42);
    ret_orig = printf("Test 12: Integer (negative): %d\n", -42);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 13: Integer (zero): %d\n", 0);
    ret_orig = printf("Test 13: Integer (zero): %d\n", 0);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 14: Integer (INT_MAX): %d\n", 2147483647);
    ret_orig = printf("Test 14: Integer (INT_MAX): %d\n", 2147483647);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 15: Integer (INT_MIN): %d\n", -2147483648);
    ret_orig = printf("Test 15: Integer (INT_MIN): %d\n", -2147483648);
    put_it(ret_ft, ret_orig);

    // Test 16-20: Unsigned integers
    ret_ft = ft_printf("Test 16: Unsigned: %u\n", 42);
    ret_orig = printf("Test 16: Unsigned: %u\n", 42);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 17: Unsigned (zero): %u\n", 0);
    ret_orig = printf("Test 17: Unsigned (zero): %u\n", 0);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 18: Unsigned (UINT_MAX): %u\n", 4294967295);
    ret_orig = printf("Test 18: Unsigned (UINT_MAX): %u\n", 4294967295);
    put_it(ret_ft, ret_orig);

    // Test 21-25: Hexadecimal (lowercase)
    ret_ft = ft_printf("Test 21: Hexadecimal: %x\n", 255);
    ret_orig = printf("Test 21: Hexadecimal: %x\n", 255);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 22: Hexadecimal (zero): %x\n", 0);
    ret_orig = printf("Test 22: Hexadecimal (zero): %x\n", 0);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 23: Hexadecimal (UINT_MAX): %x\n", 4294967295);
    ret_orig = printf("Test 23: Hexadecimal (UINT_MAX): %x\n", 4294967295);
    put_it(ret_ft, ret_orig);

    // Test 26-30: Hexadecimal (uppercase)
    ret_ft = ft_printf("Test 26: Hexadecimal (uppercase): %X\n", 255);
    ret_orig = printf("Test 26: Hexadecimal (uppercase): %X\n", 255);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 27: Hexadecimal (zero): %X\n", 0);
    ret_orig = printf("Test 27: Hexadecimal (zero): %X\n", 0);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 28: Hexadecimal (UINT_MAX): %X\n", 4294967295);
    ret_orig = printf("Test 28: Hexadecimal (UINT_MAX): %X\n", 4294967295);
    put_it(ret_ft, ret_orig);

    // Test 31-35: Pointers
    int var = 42;
    ret_ft = ft_printf("Test 31: Pointer: %p\n", &var);
    ret_orig = printf("Test 31: Pointer: %p\n", &var);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 32: Pointer (null): %p\n", NULL);
    ret_orig = printf("Test 32: Pointer (null): %p\n", NULL);
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 33: Empry ptr: %p\n");
    ret_orig = printf("Test 33: Empry ptr: %p\n");
    put_it(ret_ft, ret_orig);

    ret_ft = ft_printf("Test 33.1: Empry ptr2: %p\n");
    ret_orig = printf("Test 33.1: Empry ptr2: %p\n");
    put_it(ret_ft, ret_orig);

    // Test 36-40: Percent
    ret_ft = ft_printf("Test 36: Percent: %%\n");
    ret_orig = printf("Test 36: Percent: %%\n");
    put_it(ret_ft, ret_orig);

    // Test 41-50: Mixed cases
    ret_ft = ft_printf("Test 41: Mixed: %d, %s, %c, %p, %%\n", 123, "test", 'A', &var);
    ret_orig = printf("Test 41: Mixed: %d, %s, %c, %p, %%\n", 123, "test", 'A', &var);
    put_it(ret_ft, ret_orig);

    return 0;
}
