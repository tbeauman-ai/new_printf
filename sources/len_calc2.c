/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_calc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 20:16:09 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/11 12:57:47 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_ll(long long n, long long base)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

int		uitab_len(unsigned int *s)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		ret += get_nb_bytes(s[i]);
		i++;
	}
	return (ret);
}
