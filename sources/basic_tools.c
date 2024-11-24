/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:34:32 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/11 12:55:42 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int n, int base)
{
	char	*base_digits;

	base_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (n >= base)
		ft_putnbr_base(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putnbr_base_uppercase(int n, int base)
{
	char	*base_digits;

	base_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (n >= base)
		ft_putnbr_base_uppercase(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putlong_base(long n, long base)
{
	char	*base_digits;

	base_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base == 10 && n < 0)
	{
		if (n == LONG_MIN)
		{
			ft_putstr("-9223372036854775808");
			return ;
		}
		ft_putchar('-');
		n *= -1;
	}
	if (n >= base)
		ft_putlong_base(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putunslong_base(unsigned long n, unsigned long base)
{
	char	*base_digits;

	base_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (n >= base)
		ft_putunslong_base(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putunsint_base(unsigned int n, unsigned int base)
{
	char	*base_digits;

	base_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (n >= base)
		ft_putunsint_base(n / base, base);
	ft_putchar(base_digits[n % base]);
}
