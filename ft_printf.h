/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:49:17 by tbeauman          #+#    #+#             */
/*   Updated: 2024/12/08 22:15:45 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct  s_flags
{
    int     sharp;
    int     minus;
    int     space;
    int     zero;
    int     plus;
    int     dot;
    int     number;
    int     precision;
}               t_flags;
typedef struct  s_cvt
{
	int			(*cvt_f)(va_list *, int *);
}               t_cvt;

int		convert_c(va_list *ap, t_flags *flags);
int		convert_s(va_list *ap, t_flags *flags);
int		convert_p(va_list *ap, t_flags *flags);
int		convert_d(va_list *ap, t_flags *flags);
int		convert_i(va_list *ap, t_flags *flags);
int		convert_u(va_list *ap, t_flags *flags);
int		convert_x(va_list *ap, t_flags *flags);
int		convert_bx(va_list *ap, t_flags *flags);
int	ft_printf(const char *frm, ...);
int    handle_convert(char **frm, t_flags *flags, va_list *ap, int *ret);


#endif