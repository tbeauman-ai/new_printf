/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcsz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:33:44 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 14:17:50 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_zd(long d, int *flags)
{
	int		ret;
	int		ici;
	int		q;

	q = 0;
	ici = 0;
	ret = 0;
	easy_norml(flags, d, &ici, &ret);
	if (d < 0)
	{
		ici = 1;
		q = d == LONG_MIN ? 1 : 0;
		if (!q)
			ft_putchar('-');
		ret++;
		d = -d;
	}
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_long(d, 10) + ici && ret++ > -1)
			ft_putchar('0');
	while (flags[12]-- > length_long(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putlong_base(d, 10);
	ret += length_long(d, 10) - q;
	return (ret);
}

int		print_zo(size_t d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= length_unslong(d, 8));
	if (b)
		ft_putchar('0');
	ret = b;
	while (flags[12]-- > b + length_unslong(d, 8) && ret++ > -1)
		ft_putchar('0');
	ft_putunslong_base(d, 8);
	ret += length_unslong(d, 8);
	return (ret);
}

int		print_zu(size_t d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > length_unslong(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putunslong_base(d, 10);
	ret += length_unslong(d, 10);
	return (ret);
}

int		print_zx(size_t x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		ft_putstr("0x");
	ret = 2 * b;
	while (flags[12]-- > length_unslong(x, 16) && ret++ > -1)
		ft_putchar('0');
	ft_putunslong_base(x, 16);
	ret += length_unslong(x, 16);
	return (ret);
}

int		print_zbx(size_t x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		ft_putstr("0X");
	ret = 2 * b;
	while (flags[12]-- > length_unslong(x, 16) && ret++ > -1)
		ft_putchar('0');
	ft_putunslong_base_up(x, 16);
	ret += length_unslong(x, 16);
	return (ret);
}
