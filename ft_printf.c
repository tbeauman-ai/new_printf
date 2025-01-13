/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:58 by tbeauman          #+#    #+#             */
/*   Updated: 2024/12/08 22:14:24 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	end_of_flags(char *frm)
{
	if (*frm != '#' && *frm != '0' && *frm != '-' && *frm != '+' && *frm != ' '
		&& *frm != '.')
		return (1);
	else
		return (0);
}

int		length_int(int n, int base)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0 && base == 10)
	{
		ret++;
		if (n < -999999999)
			return (11);
		else
			n *= -1;
	}
	while (n)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

void     parse_number(char **frm, t_flags *flags)
{
    flags->number = ft_atoi(*frm);
    if (flags->number)
        (*frm) += length_int(flags->number, 10);
    if (**frm == '.')
    {
        (*frm)++;
        if (**frm >= '0' && **frm <= '9')
        {
            flags->precision = ft_atoi(*frm);
            if (flags->precision)
                flags->dot = 1;
            (*frm) += length_int(flags->precision, 10);
        }
        else
            flags->dot = 1;
    }
}

void    parse_flags(char **frm, t_flags *flags, va_list *ap)
{
	if (**frm == '#')
        flags->sharp = 1;
	if (**frm == '0')
        flags->zero = 1;
	if (**frm == '-')
        flags->minus = 1;
	if (**frm == '+')
        flags->plus = 1;
	if (**frm == ' ')
        flags->space = 1;
	(*frm)++;
    if (!end_of_flags(*frm))
        parse_flags(frm, flags, ap);
    else
        parse_number(frm, flags);
    if (flags->number < 0)
    {
        flags->number *= -1;
        flags->minus = 1;
    }
}

int	found_percent(char **frm, t_flags *flags, va_list *ap, int *ret)
{
	if (*((*frm) + 1) == 0)
		return (0);
	(*frm)++;
	if (!end_of_flags(*frm))
        parse_flags(frm, flags, ap);
    else
        parse_number(frm, flags);
    if (flags->number < 0)
    {
        flags->number *= -1;
        flags->minus = 1;
    }
    (*frm)++;
    if (handle_convert(frm, flags, ap, ret) == -1)
        return (-1);
    return (1);
}

void	init_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->sharp = 0;
	flags->space = 0;
	flags->zero = 0;
    flags->number = 0;
    flags->precision = 0;
}

int	ft_printf(const char *frm, ...)
{
	int		ret;
	va_list	ap;
	t_flags	flags;

	init_flags(&flags);
	va_start(ap, frm);
	ret = 0;
	while (*frm)
	{
		if (*frm == '%' && found_percent((char **)&frm, &flags, &ap, &ret) == -1)
			return (-1);
		else if (++ret)
			ft_putchar_fd(*frm, 1);
		frm++;
	}
	va_end(ap);
	return (ret);
}
