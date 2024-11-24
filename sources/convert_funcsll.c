/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcsll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:12:56 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 17:17:51 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_lld(va_list *ap, int *flags)
{
	long long	d;
	int			ret;
	int			prec;

	prec = flags[12];
	ret = 0;
	d = va_arg(*ap, long long);
	if (flags[13] && d == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_jd(d, flags);
	if ((!flags[1] || flags[2] || prec) && flags[11])
		while (flags[11]-- > (flags[3] || flags[4])
				+ (d < 0 && prec > length_ll(ABS(d), 10)) +
				(prec > length_ll(d, 10) ? prec : length_ll(d, 10))
				&& ret++ > -1)
			ft_putchar(' ');
	if (!flags[2])
		ret += print_jd(d, flags);
	return (ret);
}

int		convert_llo(va_list *ap, int *flags)
{
	unsigned long long	o;
	int					ret;

	ret = 0;
	o = va_arg(*ap, unsigned long long);
	if (flags[13] && o == 0 && !flags[0])
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_jo(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_ull(o, 8) && ret++ > -1)
			ft_putchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > length_ull(o, 8) ? flags[12] : length_ull(o, 8))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_jo(o, flags);
	return (ret);
}

int		convert_llu(va_list *ap, int *flags)
{
	unsigned long long	u;
	int					ret;

	ret = 0;
	u = va_arg(*ap, unsigned long long);
	if (flags[13] && u == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_ju(u, flags);
	while (flags[11]-- > (flags[12] > length_ull(u, 10) ?
				flags[12] : length_ull(u, 10))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_ju(u, flags);
	return (ret);
}

int		convert_llx(va_list *ap, int *flags)
{
	unsigned long long	x;
	int					ret;
	int					ln;

	ret = 0;
	x = va_arg(*ap, unsigned long long);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_ull(x, 16)) ? flags[12] : length_ull(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_jx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_jx(x, flags);
	return (ret);
}

int		convert_llbx(va_list *ap, int *flags)
{
	unsigned long long	x;
	int					ret;
	int					ln;

	ret = 0;
	x = va_arg(*ap, unsigned long long);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_ull(x, 16)) ? flags[12] : length_ull(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_jbx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_jbx(x, flags);
	return (ret);
}
