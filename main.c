
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	int ret;
	char *n = NULL;
	char c = 'a';
	char *p = &c;

	printf("%d\n",ft_printf("%%\n"));
	printf("%d\n",printf("%%\n"));
	printf("%d\n",ft_printf("%c\n",'a'));
	printf("%d\n",printf("%c\n",'a'));
	printf("%d\n",ft_printf("%s\n","Hell word!"));
	printf("%d\n",printf("%s\n","Hell word!"));
	printf("%d\n",ft_printf("%d\n",-1234));
	printf("%d\n",printf("%d\n",-1234));
	printf("%d\n",ft_printf("%i\n",-1234));
	printf("%d\n",printf("%i\n",-1234));
	printf("%d\n",ft_printf("%u\n",56789));
	printf("%d\n",printf("%u\n",56789));
	printf("%d\n",ft_printf("%x\n",1000));
	printf("%d\n",printf("%x\n",1000));
	printf("%d\n",ft_printf("%X\n",1000));
	printf("%d\n",printf("%X\n",1000));
	printf("%d\n",ft_printf("%p\n",p));
	printf("%d\n",printf("%p\n",p));

	ft_printf("\033[34m===========================\033[m\n");
	printf("%d\n",ft_printf("%d\n",0));
	printf("%d\n",printf("%d\n",0));
	printf("%d\n",ft_printf("%d\n",INT_MIN));
	printf("%d\n",printf("%d\n",INT_MIN));
	printf("%d\n",ft_printf("%s\n",""));
	printf("%d\n",printf("%s\n",""));
	printf("%d\n",ft_printf("%s\n",n));
	printf("%d\n",printf("%s\n",n));
	printf("%d\n",ft_printf("%c is pointed %p. %d is %s.\n",c,p,100,"hundred"));
	printf("%d\n",printf("%c is pointed %p. %d is %s.\n",c,p,100,"hundred"));

	// bonus
	printf("%d\n",ft_printf("%010d\n",123));
	printf("%d\n",printf("%010d\n",123));
	printf("%d\n",ft_printf("%-10d\n",123));
	printf("%d\n",printf("%-10d\n",123));
	printf("%d\n",ft_printf("%-2147483646d\n",123));
	printf("%d\n",printf("%-2147483646d\n",123));

	return 0;
}
