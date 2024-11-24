/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:13:59 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 18:05:53 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_i(va_list *ap, int *flags)
{
	return (convert_d(ap, flags));
}

int		convert_o(va_list *ap, int *flags)
{
	int		ret;
	int		o;
	int		prec;

	prec = flags[12];
	ret = 0;
	o = va_arg(*ap, int);
	if (flags[13] && o == 0 && !flags[0])
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_o(o, flags);
	if (flags[1] && !prec && !flags[2])
		while (flags[11]-- > length_int(o, 8) && ret++ > -1)
			ft_putchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(prec > length_int(o, 8) ? prec : length_int(o, 8))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_o(o, flags);
	return (ret);
}

int		convert_bo(va_list *ap, int *flags)
{
	int		ret;
	long	o;

	ret = 0;
	o = va_arg(*ap, long);
	if (flags[13] && !flags[0] && o == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_bo(o, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_long(o, 8) && ret++ > -1)
			ft_putchar('0');
	while (flags[11]-- > (flags[0] && o != 0) +
			(flags[12] > length_long(o, 8) ? flags[12] : length_long(o, 8))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_bo(o, flags);
	return (ret);
}

int		convert_u(va_list *ap, int *flags)
{
	int				ret;
	unsigned int	u;

	ret = 0;
	u = va_arg(*ap, unsigned int);
	if (flags[13] && u == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_u(u, flags);
	while (flags[11]-- > (flags[12] > length_unsint(u, 10) ?
				flags[12] : length_unsint(u, 10))
			&& ret++ > -1)
		flags[1] ? ft_putchar('0') : ft_putchar(' ');
	if (!flags[2])
		ret += print_u(u, flags);
	return (ret);
}

int		convert_bu(va_list *ap, int *flags)
{
	int				ret;
	unsigned long	u;

	ret = 0;
	u = va_arg(*ap, unsigned long);
	if (flags[13] && u == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ret += print_bu(u, flags);
	while (flags[11]-- > (flags[12] > length_unslong(u, 10) ?
				flags[12] : length_unslong(u, 10))
			&& ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_bu(u, flags);
	return (ret);
}
