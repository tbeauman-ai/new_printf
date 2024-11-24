/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcsj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:06:09 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 15:57:56 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_jd(intmax_t d, int *flags)
{
	int		ret;
	int		ici;
	int		q;

	q = 0;
	ici = 0;
	ret = 0;
	easy_normj(flags, d, &ici, &ret);
	if (d < 0)
	{
		ici = 1;
		q = d == LLONG_MIN ? 1 : 0;
		if (!q)
			ft_putchar('-');
		ret++;
		d = -d;
	}
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_ll(d, 10) + ici && ret++ > -1)
			ft_putchar('0');
	while (flags[12]-- > length_ll(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putll_base(d, 10);
	ret += length_ll(d, 10);
	return (ret);
}

int		print_jo(uintmax_t d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= length_ull(d, 8));
	if (b)
		ft_putchar('0');
	ret = b;
	while (flags[12]-- > b + length_ull(d, 8) && ret++ > -1)
		ft_putchar('0');
	ft_putull_base(d, 8);
	ret += length_ull(d, 8);
	return (ret);
}

int		print_ju(uintmax_t d, int *flags)
{
	int		ret;

	ret = 0;
	while (flags[12]-- > length_ull(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putull_base(d, 10);
	ret += length_ull(d, 10);
	return (ret);
}

int		print_jx(uintmax_t x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		ft_putstr("0x");
	ret = 2 * b;
	while (flags[12]-- > length_ull(x, 16) && ret++ > -1)
		ft_putchar('0');
	ft_putull_base(x, 16);
	ret += length_ull(x, 16);
	return (ret);
}

int		print_jbx(uintmax_t x, int *flags)
{
	int		ret;
	int		b;

	b = (x != 0) && flags[0];
	if (b)
		ft_putstr("0X");
	ret = 2 * b;
	while (flags[12]-- > length_ull(x, 16) && ret++ > -1)
		ft_putchar('0');
	ft_putull_base_up(x, 16);
	ret += length_ull(x, 16);
	return (ret);
}
