/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:46:20 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/09 10:14:55 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		n;
	int		i;

	i = 0;
	n = 0;
	ret = 0;
	while (*str == '\t' || *str == '\f' || *str == '\v' || *str == '\r' ||
			*str == '\n' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		n = *str == '-' ? 1 : 0;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		ret = 10 * ret + (str[i] - '0');
		i++;
	}
	return (n == 1 ? -ret : ret);
}