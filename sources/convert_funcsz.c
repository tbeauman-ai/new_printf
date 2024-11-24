/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcsz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 10:00:17 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 17:17:44 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_zd(va_list *ap, int *flags)
{
	long	d;
	int		ret;
	int		prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*ap, long);
	if (flags[13] && d == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_zd(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > length_long(ABS(d), 10)) +
				(prec > length_long(d, 10) ? prec :
				length_long(d, 10)) && ret++ > -1)
			ft_putchar(' ');
	if (!flags[2])
		ret += print_zd(d, flags);
	return (ret);
}

int		convert_zo(va_list *ap, int *flags)
{
	size_t	o;
	int		ret;

	ret = 0;
	o = va_arg(*ap, size_t);
	if (flags[13] && o == 0 && !flags[0])
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_zo(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_unslong(o, 8) && ret++ > -1)
			ft_putchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > length_unslong(o, 8) ? flags[12] :
			length_unslong(o, 8)) && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_zo(o, flags);
	return (ret);
}

int		convert_zu(va_list *ap, int *flags)
{
	size_t	u;
	int		ret;

	ret = 0;
	u = va_arg(*ap, size_t);
	if (flags[13] && u == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_zu(u, flags);
	while (flags[11]-- > (flags[12] > length_unslong(u, 10) ?
				flags[12] : length_unslong(u, 10))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_zu(u, flags);
	return (ret);
}

int		convert_zx(va_list *ap, int *flags)
{
	size_t	x;
	int		ret;
	int		ln;

	ret = 0;
	x = va_arg(*ap, size_t);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unslong(x, 16)) ? flags[12] : length_unslong(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_zx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_zx(x, flags);
	return (ret);
}

int		convert_zbx(va_list *ap, int *flags)
{
	size_t	x;
	int		ret;
	int		ln;

	ret = 0;
	x = va_arg(*ap, size_t);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unslong(x, 16)) ? flags[12] : length_unslong(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_zbx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_zbx(x, flags);
	return (ret);
}
