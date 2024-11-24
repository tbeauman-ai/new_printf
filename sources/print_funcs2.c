/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:52:42 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 18:41:50 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_u(unsigned int d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > length_unsint(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putunsint_base(d, 10);
	ret += length_unsint(d, 10);
	return (ret);
}

int		print_bu(unsigned long d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > length_unslong(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putunslong_base(d, 10);
	ret += length_unslong(d, 10);
	return (ret);
}

int		print_p(unsigned long p, int *flags)
{
	int		ret;

	ret = 0;
	if (p == 0)
	{
		ft_putstr("(nil)");
		ret += 5;
		return (ret);
	}
	ft_putstr("0x");
	if (flags[13] && p == 0)
		return (2);
	if (flags[12] && p == 0)
		while (flags[12]-- > 1 && ret++ > -1)
			ft_putchar('0');
	ft_putunslong_base(p, 16);
	ret += 2 + length_unslong(p, 16);
	return (ret);
}

int		print_x(unsigned int x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		ft_putstr("0x");
	ret = 2 * b;
	while (flags[12]-- > length_unsint(x, 16) && ret++ > -1)
		ft_putchar('0');
	ft_putunsint_base(x, 16);
	ret += length_unsint(x, 16);
	return (ret);
}

int		print_bx(unsigned int x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		ft_putstr("0X");
	ret = 2 * b;
	while (flags[12]-- > length_unsint(x, 16) && ret++ > -1)
		ft_putchar('0');
	ft_putunsint_base_up(x, 16);
	ret += length_unsint(x, 16);
	return (ret);
}
