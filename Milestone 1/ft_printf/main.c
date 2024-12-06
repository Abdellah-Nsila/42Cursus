#include "ft_printf.h"
#include "stdlib.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void intToStr(int num, char *str) {

    int i = 0, isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; 

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}

int main()
{
	int d;
	char str[20];

	close(1);
	setvbuf(stdout, NULL, _IONBF, 0);
	d = ft_printf("hello\nuuu%s", " world");
	intToStr(d, str);
	int i = 0;
	while(str[i])
		write(2, &str[i++],1);
	
	//printf("hello ");
	//printf("world");
	//printf("hello\n");
	//fflush(stdout);
	//write(1, "w", 1);
}