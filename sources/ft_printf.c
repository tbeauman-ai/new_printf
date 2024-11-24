/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:51:02 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 17:21:22 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		just_print_spaces(int *flags)
{
	int		n;

	n = flags[11];
	while (n--)
		ft_putchar(' ');
	return (flags[11]);
}

int		print_percent(int *flags)
{
	int		ret;

	ret = 0;
	if (flags[2])
		ft_putchar('%');
	while (flags[11]-- > 1 && ret++ > -1)
		flags[1] ? ft_putchar('0') : ft_putchar(' ');
	if (!flags[2])
		ft_putchar('%');
	ret++;
	return (ret);
}

void	found_percent(char **frm, int **flags, va_list *ap, int *ret)
{
	if (*((*frm) + 1) == 0)
		return ;
	(*frm)++;
	if (!end_of_flags(*frm))
		flags_parse(frm, flags, ap);
	else
		atoi_parse(frm, flags, ap);
	if ((*flags)[11] < 0)
	{
		(*flags)[11] *= -1;
		(*flags)[2] = 1;
	}
	if (**frm == 'j')
		(*flags)[9] = 1;
	else
		modifier_parse(frm, flags);
	(*frm)++;
	if (modifier_presence(*flags) && **frm != 'p')
		convert_w_mods(frm, *flags, ap, ret);
	else
		convert_handle(frm, *flags, ap, ret);
}

int		ft_printf(const char *frm, ...)
{
	int		ret;
	int		*flags;
	va_list	ap;

	ret = -1;
	flags = malloc(14 * sizeof(int));
	while (++ret < 14)
		flags[ret] = 0;
	va_start(ap, frm);
	ret = 0;
	while (*frm)
	{
		if (*frm == '%')
			found_percent((char**)&frm, &flags, &ap, &ret);
		else
		{
			ft_putchar(*frm);
			ret++;
		}
		frm++;
	}
	va_end(ap);
	free(flags);
	return (ret);
}
