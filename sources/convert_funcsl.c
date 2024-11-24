/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcsl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:00:41 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 17:17:32 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_ld(va_list *ap, int *flags)
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
		ret += print_ld(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > length_long(ABS(d), 10)) +
				(prec > length_long(d, 10) ? prec :
				length_long(d, 10)) && ret++ > -1)
			ft_putchar(' ');
	if (!flags[2])
		ret += print_ld(d, flags);
	return (ret);
}

int		convert_lo(va_list *ap, int *flags)
{
	unsigned long	o;
	int				ret;

	ret = 0;
	o = va_arg(*ap, unsigned long);
	if (flags[13] && o == 0 && !flags[0])
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_lo(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_unslong(o, 8) && ret++ > -1)
			ft_putchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > length_unslong(o, 8) ? flags[12] :
			length_unslong(o, 8)) && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_lo(o, flags);
	return (ret);
}

int		convert_lu(va_list *ap, int *flags)
{
	unsigned long	u;
	int				ret;

	ret = 0;
	u = va_arg(*ap, unsigned long);
	if (flags[13] && u == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_lu(u, flags);
	while (flags[11]-- > (flags[12] > length_unslong(u, 10) ?
				flags[12] : length_unslong(u, 10))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_lu(u, flags);
	return (ret);
}

int		convert_lx(va_list *ap, int *flags)
{
	unsigned long	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(*ap, unsigned long);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unslong(x, 16)) ? flags[12] : length_unslong(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_lx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_lx(x, flags);
	return (ret);
}

int		convert_lbx(va_list *ap, int *flags)
{
	unsigned long	x;
	int				ret;
	int				ln;

	ret = 0;
	x = va_arg(*ap, unsigned long);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unslong(x, 16)) ? flags[12] : length_unslong(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		x += print_lbx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		x += print_lbx(x, flags);
	return (ret);
}
