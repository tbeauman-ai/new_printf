/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:20:01 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/11 15:23:09 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

void	ft_putnegnbr_oct(int n)
{
	int		i;

	i = 0;
	ft_putnbr_base((n & 0xc0000000) >> 30, 8);
	n <<= 2;
	while (i < 10)
	{
		ft_putnbr_base((n & 0xe0000000) >> 29, 8);
		n <<= 3;
		i++;
	}
}

void	ft_putneglong_oct(long n)
{
	int		i;

	i = 0;
	ft_putnbr_base((n & 0x8000000000000000) >> 63, 8);
	n <<= 1;
	while (i < 21)
	{
		ft_putnbr_base((n & 0xe000000000000000) >> 61, 8);
		n <<= 3;
		i++;
	}
}
