/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 13:41:47 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 14:32:29 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		end_of_flags(char *frm)
{
	if (*frm != '#' && *frm != '0' && *frm != '-' && *frm != '+' && *frm != ' ')
		return (1);
	else
		return (0);
}

void	atoi_parse(char **frm, int **flags, va_list *ap)
{
	(*flags)[11] = **frm == '*' ? va_arg(*ap, int) : ft_atoi(*frm);
	if ((*flags)[11] || **frm == '*')
		(*frm) += **frm == '*' ? 1 : length_int((*flags)[11], 10);
	if (**frm == '.')
	{
		if (*(*frm + 1) == '*')
		{
			if (((*flags)[12] = va_arg(*ap, int)) == 0)
				(*flags)[13] = 1;
			(*frm) += 2;
		}
		else
		{
			(*frm)++;
			if (**frm >= '0' && **frm <= '9')
			{
				(*flags)[12] = ft_atoi(*frm);
				if ((*flags)[12] == 0)
					(*flags)[13] = 1;
				(*frm) += length_int((*flags)[12], 10);
			}
			else
				(*flags)[13] = 1;
		}
	}
}

void	flags_parse(char **frm, int **flags, va_list *ap)
{
	if (**frm == '#')
		(*flags)[0] = 1;
	if (**frm == '0')
		(*flags)[1] = 1;
	if (**frm == '-')
		(*flags)[2] = 1;
	if (**frm == '+')
		(*flags)[3] = 1;
	if (**frm == ' ')
		(*flags)[4] = 1;
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
}

void	modifier_parse(char **frm, int **flags)
{
	if (**frm == 'z')
		(*flags)[10] = 1;
	else if (**frm == 'h')
	{
		if (*(*frm + 1) == 'h')
		{
			(*flags)[5] = 1;
			(*frm)++;
		}
		else
			(*flags)[6] = 1;
	}
	else if (**frm == 'l')
	{
		if (*(*frm + 1) == 'l')
		{
			(*flags)[7] = 1;
			(*frm)++;
		}
		else
			(*flags)[8] = 1;
	}
	else
		(*frm)--;
}

int		modifier_presence(int *flags)
{
	int		ret;

	ret = flags[5] + flags[6] + flags[7] + flags[8] + flags[9] + flags[10];
	return (ret);
}
