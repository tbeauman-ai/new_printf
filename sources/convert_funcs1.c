/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num_tools1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:43:53 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 17:32:31 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_s(va_list *ap, int *flags)
{
	int		ret;
	char	*s;
	int		lw;

	ret = 0;
	if (flags[13])
	{
		while (flags[11]-- && ret++ > -1)
			ft_putchar(' ');
		return (ret);
	}
	s = va_arg(*ap, char *);
	if (flags[12] && flags[12] < (int)ft_strlen(s) && flags[12] >= 0)
		lw = flags[12];
	else
		lw = s ? ft_strlen(s) : 6;
	if (flags[2])
		ret += print_s(s, flags);
	while (flags[11]-- > lw && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_s(s, flags);
	return (ret);
}

int		convert_bs(va_list *ap, int *flags)
{
	int				ret;
	unsigned int	*bs;

	ret = 0;
	if (flags[13])
	{
		while (flags[11]-- && ret++ > -1)
			ft_putchar(' ');
		return (ret);
	}
	bs = va_arg(*ap, unsigned int *);
	if (flags[2])
		ret += print_bs(bs);
	while (flags[11]-- > uitab_len(bs) && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_bs(bs);
	return (ret);
}

int		convert_p(va_list *ap, int *flags)
{
	int		ret;
	long	p;

	ret = 0;
	p = va_arg(*ap, long);
	if (flags[2])
		ret += print_p(p, flags);
	while (flags[11]-- > length_long(p, 16) + 2 && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_p(p, flags);
	return (ret);
}

int		convert_d(va_list *ap, int *flags)
{
	int		d;
	int		ret;
	int		prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*ap, int);
	if (flags[13] && d == 0)
		return (0);
	if (flags[2])
		ret += print_d(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > length_int(ABS(d), 10)) +
				(prec > length_int(d, 10) ? prec :
				length_int(d, 10)) && ret++ > -1)
			ft_putchar(' ');
	if (!flags[2])
		ret += print_d(d, flags);
	return (ret);
}

int		convert_bd(va_list *ap, int *flags)
{
	int		ret;
	long	bd;

	ret = 0;
	bd = va_arg(*ap, long);
	if (flags[13] && bd == 0)
		return (0);
	if (flags[2])
		ret += print_bd(bd, flags);
	if (!flags[1] && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (bd < 0 && flags[12] > length_long(bd, 10))
				+ (flags[12] > length_long(bd, 10) ?
					flags[12] : length_long(bd, 10))
				&& ret++ > -1)
			ft_putchar(' ');
	if (!flags[2])
		ret += print_bd(bd, flags);
	return (ret);
}
