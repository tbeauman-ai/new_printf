/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:30:07 by tbeauman          #+#    #+#             */
/*   Updated: 2024/12/08 22:30:57 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(char *s, t_flags *flags)
{
	int		i;
	int		len;
	char	*nu;

	nu = "(null)";
	i = -1;
	if (!s)
	{
		if (flags[12] && flags[12] < 6 && flags[12] >= 0)
			len = flags[12];
		else
			len = 6;
		while (++i < len)
			ft_putchar(nu[i]);
		return (i);
	}
	if (flags[12] && flags[12] < (int)ft_strlen(s) && flags[12] >= 0)
		len = flags[12];
	else
		len = ft_strlen(s);
	while (++i < len)
		ft_putchar(s[i]);
	return (i);
}
