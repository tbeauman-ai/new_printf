/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:04:50 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/11 13:16:08 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunslong_base_up(unsigned long n, unsigned long base)
{
	char	*base_digits;

	base_digits = "0123456789ABCDEFGHIJKL";
	if (n >= base)
		ft_putunslong_base_up(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putull_base(unsigned long long n, unsigned long long base)
{
	char	*base_digits;

	base_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (n >= base)
		ft_putull_base(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putll_base(long long n, long long base)
{
	char	*base_digits;

	if (base == 10 && n < 0)
	{
		if (n == LLONG_MIN)
		{
			ft_putstr("-9223372036854775808");
			return ;
		}
		ft_putchar('-');
		n *= -1;
	}
	base_digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (n >= base)
		ft_putll_base(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putull_base_up(unsigned long long n, unsigned long long base)
{
	char	*base_digits;

	base_digits = "0123456789ABCDEFGHIJKL";
	if (n >= base)
		ft_putull_base_up(n / base, base);
	ft_putchar(base_digits[n % base]);
}

void	ft_putunsint_base_up(unsigned int n, unsigned int base)
{
	char	*base_digits;

	base_digits = "0123456789ABCDEFGHIJKL";
	if (n >= base)
		ft_putunsint_base_up(n / base, base);
	ft_putchar(base_digits[n % base]);
}
