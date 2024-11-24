/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_shit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:25:03 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 18:05:55 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	easy_norm(int *flags, int d, int *ici, int *ret)
{
	if ((flags[3] || flags[4]) && d >= 0)
	{
		*ici = 1;
		if (flags[3])
			ft_putchar('+');
		else
			ft_putchar(' ');
		(*ret)++;
	}
}

void	easy_normj(int *flags, intmax_t d, int *ici, int *ret)
{
	if ((flags[3] || flags[4]) && d >= 0)
	{
		*ici = 1;
		if (flags[3])
			ft_putchar('+');
		else
			ft_putchar(' ');
		(*ret)++;
	}
}

void	easy_norml(int *flags, long d, int *ici, int *ret)
{
	if ((flags[3] || flags[4]) && d >= 0)
	{
		*ici = 1;
		if (flags[3])
			ft_putchar('+');
		else
			ft_putchar(' ');
		(*ret)++;
	}
}
