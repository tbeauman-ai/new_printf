/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:49:18 by tbeauman          #+#    #+#             */
/*   Updated: 2024/12/08 21:57:05 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_x(va_list *ap, t_flags *flags)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(*ap, int);
	if (flags->dot && x == 0)
		return (just_print_spaces(flags));
	ln = (flags->precision > length_unsint(x, 16)) ? flags->precision : length_unsint(x, 16)
		+ 2 * (flags->sharp && x != 0);
	if (flags->minus)
		ret += print_x(x, flags);
	if (flags->zero && !flags->precision && !flags->minus)
		while (flags->number-- > ln && ret++ > -1)
			ft_putchar_fd('0', 1);
	while (!flags->zero && flags->number-- > ln && ret++ > -1)
		ft_putchar_fd(' ', 1);
	if (!flags->minus)
		ret += print_x(x, flags);
	return (ret);
}

int		convert_bx(va_list *ap, t_flags *flags)
{
	int					ret;
	unsigned int		x;
	int					ln;

	ret = 0;
	x = va_arg(*ap, int);
	if (flags->dot && x == 0)
		return (just_print_spaces(flags));
	ln = (flags->precision > length_unsint(x, 16)) ? flags->precision : length_unsint(x, 16)
		+ 2 * (flags->sharp && x != 0);
	if (flags->minus)
		ret += print_bx(x, flags);
	if (flags->zero && !flags->precision && !flags->minus)
		while (flags->number-- > ln && ret++ > -1)
			ft_putchar_fd('0', 1);
	while (!flags->zero && flags->number-- > ln && ret++ > -1)
		ft_putchar_fd(' ', 1);
	if (!flags->minus)
		ret += print_bx(x, flags);
	return (ret);
}

int		convert_c(va_list *ap, t_flags *flags)
{
	int		ret;
	int		c;

	ret = flags->number ? flags->number : 1;
	c = va_arg(*ap, int);
	if (flags->minus)
		ft_putchar_fd(c, 1);
	while (flags->number-- > 1)
		ft_putchar_fd(' ', 1);
	if (!flags->minus)
		ft_putchar_fd(c, 1);
	return (ret);
}