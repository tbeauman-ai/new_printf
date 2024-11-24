/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:05:11 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/09 17:50:13 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_nb_bytes(unsigned int car)
{
	unsigned int	n;

	if (0x80 > car)
		return (1);
	n = 2;
	while (0x0000007ff < car)
	{
		n++;
		car >>= 5;
	}
	return (n);
}

void			get_seq(unsigned int car, unsigned char *seq)
{
	unsigned int	nb_bytes;
	unsigned int	n;

	nb_bytes = get_nb_bytes(car);
	ft_bzero(seq, nb_bytes);
	if (0x80 > car)
	{
		seq[0] = car;
		return ;
	}
	n = 0;
	while (n < nb_bytes)
	{
		*seq >>= 1;
		*seq |= 0x80;
		n++;
	}
	while (0 < n)
	{
		n--;
		seq[n] |= 0x80 | (car & 0x0000003f);
		car >>= 6;
	}
	seq[0] |= car;
}

int				print_bc(unsigned int car)
{
	unsigned char	seq[4];
	int				i;

	i = -1;
	while (++i < 4)
		seq[i] = 0;
	get_seq(car, seq);
	i = 0;
	while (i < 4)
	{
		if (0 != seq[i])
			write(1, &seq[i], 1);
		i++;
	}
	return (get_nb_bytes(car));
}

int				print_bs(unsigned int *bs)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!bs)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (bs[i] != 0)
	{
		print_bc(bs[i]);
		ret += get_nb_bytes(bs[i]);
		i++;
	}
	return (ret);
}
