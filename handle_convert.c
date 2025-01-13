/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:40:40 by tbeauman          #+#    #+#             */
/*   Updated: 2024/12/08 22:19:52 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    handle_percent(char **frm, t_flags *flags, int *ret)
{
    if (**frm == '%')
        (*ret) += print_percent(flags);
    else
    {
        (*frm)--;
        *ret += just_print_spaces(flags);
    }
}

int    handle_convert(char **frm, t_flags *flags, va_list *ap, int *ret)
{
    t_cvt  *cvt_fcts;
    char        *converters;
    int         i;

    converters = "cspdiuxX";
    cvt_fcts = (t_cvt *)malloc(8 * sizeof(t_cvt));
    if (!cvt_fcts)
        return (-1);
    init_ptr_tab(&cvt_fcts);
    while (i < 8)
    {
        if (**frm == converters[i])
        {
            *ret += cvt_fcts[i].cvt_f(ap, flags);
            free(cvt_fcts);
            return (1);
        }
        i++;
    }
    free(cvt_fcts);
    handle_percent(frm, flags, ret);
}