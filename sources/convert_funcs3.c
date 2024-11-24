/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funcs3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:14:04 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 14:56:23 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_x(va_list *ap, int *flags)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(*ap, int);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unsint(x, 16)) ? flags[12] : length_unsint(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_x(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_x(x, flags);
	return (ret);
}

int		convert_bx(va_list *ap, int *flags)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(*ap, int);
	if (flags[13] && x == 0)
		return (just_print_spaces(flags));
	ln = (flags[12] > length_unsint(x, 16)) ? flags[12] : length_unsint(x, 16)
		+ 2 * (flags[0] && x != 0);
	if (flags[2])
		ret += print_bx(x, flags);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > ln && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > ln && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_bx(x, flags);
	return (ret);
}

int		convert_c(va_list *ap, int *flags)
{
	int		ret;
	int		c;

	ret = flags[11] ? flags[11] : 1;
	c = va_arg(*ap, int);
	if (flags[2])
		ft_putchar(c);
	while (flags[11]-- > 1)
		ft_putchar(' ');
	if (!flags[2])
		ft_putchar(c);
	return (ret);
}

int		convert_bc(va_list *ap, int *flags)
{
	int					ret;
	unsigned int		bc;

	ret = 0;
	bc = va_arg(*ap, unsigned int);
	if (flags[2])
		ret += print_bc(bc);
	while (flags[11]-- > (int)get_nb_bytes(bc) && ret++)
		ft_putchar(' ');
	if (!flags[2])
		ret += print_bc(bc);
	return (ret);
}

int		convert_b(va_list *ap, int *flags)
{
	int		ret;
	int		b;

	ret = 0;
	b = va_arg(*ap, int);
	if (flags[13] && b == 0)
		return (just_print_spaces(flags));
	if (flags[2])
		ft_putnbr_base(b, 2);
	if (flags[1] && !flags[12] && !flags[2])
		while (flags[11]-- > length_int(b, 2) && ret++ > -1)
			ft_putchar('0');
	while (!flags[1] && flags[11]-- > length_int(b, 2) && ret++ > -1)
		ft_putchar(' ');
	if (!flags[2])
		ft_putnbr_base(b, 2);
	ret += length_int(b, 2);
	return (ret);
}
