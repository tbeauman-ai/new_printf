/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:48:04 by tbeauman          #+#    #+#             */
/*   Updated: 2024/12/08 22:29:30 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_s(va_list *ap, t_flags *flags)
{
	int		ret;
	char	*s;
	int		lw;

	ret = 0;
	if (flags->dot)
	{
		while (flags->number-- && ret++ > -1)
			ft_putchar(' ');
		return (ret);
	}
	s = va_arg(*ap, char *);
	if (flags->precision && flags->precision < (int)ft_strlen(s) && flags->precision >= 0)
		lw = flags->precision;
	else//if (s)
		lw = ft_strlen(s);
	// else
	// 	lw = 6;
	if (flags->minus)
		ret += print_s(s, flags);
	while (flags->number-- > lw && ret++ > -1)
		ft_putchar(' ');
	if (!flags->minus)
		ret += print_s(s, flags);
	return (ret);
}

int		convert_p(va_list *ap, t_flags *flags)
{
	int		ret;
	unsigned long	p;

	ret = 0;
	p = va_arg(*ap, long);
	if (flags->minus)
		ret += print_p(p, flags);
	while (flags->number-- > length_long(p, 16) + 2 && ret++ > -1)
		ft_putchar_fd(' ', 1);
	if (!flags->minus)
		ret += print_p(p, flags);
	return (ret);
}

int		convert_d(va_list *ap, t_flags *flags)
{
	int		d;
	int		ret;
	int		prec;

	prec = flags->precision;
	ret = 0;
	d = va_arg(*ap, int);
	if (flags->dot && d == 0)
		return (0);
	if (flags->minus)
		ret += print_d(d, flags);
	if ((!flags->zero || flags->minus || prec) && flags->number)
		while (flags->number-- > (flags->plus || flags->space)
				+ (d < 0 && prec > length_int(ABS(d), 10)) +
				(prec > length_int(d, 10) ? prec :
				length_int(d, 10)) && ret++ > -1)
			ft_putchar_fd(' ', 1);
	if (!flags->minus)
		ret += print_d(d, flags);
	return (ret);
}

int		convert_i(va_list *ap, t_flags *flags)
{
	return (convert_d(ap, flags));
}

int		convert_u(va_list *ap, t_flags *flags)
{
	int				ret;
	unsigned int	u;

	ret = 0;
	u = va_arg(*ap, unsigned int);
	if (flags->dot && u == 0)
		return (just_print_spaces(flags));
	if (flags->minus)
		ret += print_u(u, flags);
	while (flags->number-- > (flags->precision > length_unsint(u, 10) ?
				flags->precision : length_unsint(u, 10))
			&& ret++ > -1)
		if (flags->zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	if (!flags->minus)
		ret += print_u(u, flags);
	return (ret);
}