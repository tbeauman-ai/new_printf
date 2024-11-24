/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:17:40 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 17:46:55 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_ptr_tab(t_cvt **cvt_fcts)
{
	(*cvt_fcts)[0].convert_fun = &convert_s;
	(*cvt_fcts)[1].convert_fun = &convert_bs;
	(*cvt_fcts)[2].convert_fun = &convert_p;
	(*cvt_fcts)[3].convert_fun = &convert_d;
	(*cvt_fcts)[4].convert_fun = &convert_bd;
	(*cvt_fcts)[5].convert_fun = &convert_i;
	(*cvt_fcts)[6].convert_fun = &convert_o;
	(*cvt_fcts)[7].convert_fun = &convert_bo;
	(*cvt_fcts)[8].convert_fun = &convert_u;
	(*cvt_fcts)[9].convert_fun = &convert_bu;
	(*cvt_fcts)[10].convert_fun = &convert_x;
	(*cvt_fcts)[11].convert_fun = &convert_bx;
	(*cvt_fcts)[12].convert_fun = &convert_c;
	(*cvt_fcts)[13].convert_fun = &convert_bc;
	(*cvt_fcts)[14].convert_fun = &convert_b;
}

void	convert_handle(char **frm, int *flags, va_list *ap, int *ret)
{
	char	*converters;
	t_cvt	*cvt_fcts;
	int		i;

	i = 0;
	converters = "sSpdDioOuUxXcCb";
	cvt_fcts = malloc(15 * sizeof(t_cvt));
	init_ptr_tab(&cvt_fcts);
	while (i < 15)
	{
		if (**frm == converters[i])
		{
			*ret += cvt_fcts[i].convert_fun(ap, flags);
			free(cvt_fcts);
			return ;
		}
		i++;
	}
	free(cvt_fcts);
	if (**frm == '%')
		(*ret) += print_percent(flags);
	else
	{
		(*frm)--;
		*ret += just_print_spaces(flags);
	}
}

void	init_ptr_tab3(t_cvt **cvt_fcts)
{
	(*cvt_fcts)[24].convert_fun = &convert_jd;
	(*cvt_fcts)[25].convert_fun = &convert_jd;
	(*cvt_fcts)[26].convert_fun = &convert_jo;
	(*cvt_fcts)[27].convert_fun = &convert_ju;
	(*cvt_fcts)[28].convert_fun = &convert_jx;
	(*cvt_fcts)[29].convert_fun = &convert_jbx;
	(*cvt_fcts)[30].convert_fun = &convert_zd;
	(*cvt_fcts)[31].convert_fun = &convert_zd;
	(*cvt_fcts)[32].convert_fun = &convert_zo;
	(*cvt_fcts)[33].convert_fun = &convert_zu;
	(*cvt_fcts)[34].convert_fun = &convert_zx;
	(*cvt_fcts)[35].convert_fun = &convert_zbx;
}

void	init_ptr_tab2(t_cvt **cvt_fcts)
{
	(*cvt_fcts)[0].convert_fun = &convert_hhd;
	(*cvt_fcts)[1].convert_fun = &convert_hhd;
	(*cvt_fcts)[2].convert_fun = &convert_hho;
	(*cvt_fcts)[3].convert_fun = &convert_hhu;
	(*cvt_fcts)[4].convert_fun = &convert_hhx;
	(*cvt_fcts)[5].convert_fun = &convert_hhbx;
	(*cvt_fcts)[6].convert_fun = &convert_hd;
	(*cvt_fcts)[7].convert_fun = &convert_hd;
	(*cvt_fcts)[8].convert_fun = &convert_ho;
	(*cvt_fcts)[9].convert_fun = &convert_hu;
	(*cvt_fcts)[10].convert_fun = &convert_hx;
	(*cvt_fcts)[11].convert_fun = &convert_hbx;
	(*cvt_fcts)[12].convert_fun = &convert_lld;
	(*cvt_fcts)[13].convert_fun = &convert_lld;
	(*cvt_fcts)[14].convert_fun = &convert_llo;
	(*cvt_fcts)[15].convert_fun = &convert_llu;
	(*cvt_fcts)[16].convert_fun = &convert_llx;
	(*cvt_fcts)[17].convert_fun = &convert_llbx;
	(*cvt_fcts)[18].convert_fun = &convert_ld;
	(*cvt_fcts)[19].convert_fun = &convert_ld;
	(*cvt_fcts)[20].convert_fun = &convert_lo;
	(*cvt_fcts)[21].convert_fun = &convert_lu;
	(*cvt_fcts)[22].convert_fun = &convert_lx;
	(*cvt_fcts)[23].convert_fun = &convert_lbx;
	init_ptr_tab3(cvt_fcts);
}

void	convert_w_mods(char **frm, int *flags, va_list *ap, int *ret)
{
	char	*converters;
	t_cvt	*cvt_fcts;
	int		i;

	i = 0;
	converters = "diouxX";
	cvt_fcts = malloc(36 * sizeof(t_cvt));
	init_ptr_tab2(&cvt_fcts);
	while (i < 36)
	{
		if (**frm == converters[i % 6] && flags[i / 6 + 5])
		{
			*ret += cvt_fcts[i].convert_fun(ap, flags);
			free(cvt_fcts);
			return ;
		}
		i++;
	}
	free(cvt_fcts);
	if (**frm == '%')
		(*ret) += print_percent(flags);
	else
	{
		(*frm)--;
		(*ret) += just_print_spaces(flags);
	}
}
