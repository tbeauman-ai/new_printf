#include <stdio.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	void	*addr;

	// printf("LONG MIN LONG MAX\n");
	// printf("%p:%p\n", LONG_MIN, LONG_MAX);
	// ft_printf("%p:%p\n", LONG_MIN, LONG_MAX);
	
	printf("ULONGMAX -ULONG MAX\n");
	printf("pf:%d:",printf(" %p %p \n", ULONG_MAX, -ULONG_MAX));
	printf("ft:%d:", ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX));
	
	printf("0 0\n");
	printf("pf:%d:",printf(" %p %p \n", 0, 0));
	printf("ft:%d:",ft_printf(" %p %p \n", 0, 0));
	return (0);
}
