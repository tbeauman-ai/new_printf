/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:05:39 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/09 14:20:00 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int		length_long(long n, long base)
{
	int		ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0 && base == 10)
	{
		ret++;
		if (n < -999999999999999999)
			return (20);
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

int		length_unsint(unsigned int n, unsigned int base)
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

int		length_unslong(unsigned long n, unsigned long base)
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

int		length_ull(unsigned long long n, unsigned long long base)
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
