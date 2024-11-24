/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:28:48 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 16:04:24 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(char *s, int *flags)
{
	int		i;
	int		len;
	char	*nu;

	nu = "(null)";
	i = -1;
	if (!s)
	{
		if (flags[12] && flags[12] < 6 && flags[12] >= 0)
			len = flags[12];
		else
			len = 6;
		while (++i < len)
			ft_putchar(nu[i]);
		return (i);
	}
	if (flags[12] && flags[12] < (int)ft_strlen(s) && flags[12] >= 0)
		len = flags[12];
	else
		len = ft_strlen(s);
	while (++i < len)
		ft_putchar(s[i]);
	return (i);
}

int		print_d(int d, int *flags)
{
	int		ret;
	int		ici;
	int		q;

	q = 0;
	ici = 0;
	ret = 0;
	easy_norm(flags, d, &ici, &ret);
	if (d < 0)
	{
		ici = 1;
		q = d == -2147483648 ? 1 : 0;
		if (!q)
			ft_putchar('-');
		ret++;
		d = -d;
	}
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_int(d, 10) + ici && ret++ > -1)
			ft_putchar('0');
	while (flags[12]-- > length_int(d, 10) && ret++ > -1)
		ft_putchar('0');
	ft_putnbr(d);
	ret += length_int(d, 10) - q;
	return (ret);
}

int		print_bd(long d, int *flags)
{
	int		ret;
	int		q;
	int		ici;

	q = 0;
	ici = 0;
	ret = 0;
	easy_norm(flags, d, &ici, &ret);
	if (d < 0)
	{
		ici = 1;
		q = d == LONG_MIN ? 1 : 0;
		if (!q)
			ft_putchar('-');
		ret++;
		d *= -1;
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

int		print_o(int d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= length_int(d, 8));
	if (b)
		ft_putchar('0');
	ret = b;
	while (flags[12]-- > b + length_int(d, 8) && ret++ > -1)
		ft_putchar('0');
	if (d < 0)
		ft_putnegnbr_oct(d);
	else
		ft_putnbr_base(d, 8);
	ret += d < 0 ? 11 : length_int(d, 8);
	return (ret);
}

int		print_bo(long d, int *flags)
{
	int		ret;
	int		b;

	b = (d != 0) && flags[0] && (flags[12] <= length_long(d, 8));
	if (b)
		ft_putchar('0');
	ret = b;
	while (flags[12]-- > b + length_long(d, 8) && ret++ > -1)
		ft_putchar('0');
	if (d < 0)
		ft_putneglong_oct(d);
	else
		ft_putlong_base(d, 8);
	ret += d < 0 ? 22 : length_long(d, 8);
	return (ret);
}
