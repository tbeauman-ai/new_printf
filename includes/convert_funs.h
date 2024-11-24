/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_funs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:17:56 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/28 18:24:37 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_FUNS_H
# define CONVERT_FUNS_H

void	convert_handle(char **frm, int *flags, va_list *ap, int *ret);
int		convert_s(va_list *ap, int *flags);
int		convert_bs(va_list *ap, int *flags);
int		convert_p(va_list *ap, int *flags);
int		convert_d(va_list *ap, int *flags);
int		convert_bd(va_list *ap, int *flags);
int		convert_i(va_list *ap, int *flags);
int		convert_o(va_list *ap, int *flags);
int		convert_bo(va_list *ap, int *flags);
int		convert_u(va_list *ap, int *flags);
int		convert_bu(va_list *ap, int *flags);
int		convert_x(va_list *ap, int *flags);
int		convert_bx(va_list *ap, int *flags);
int		convert_c(va_list *ap, int *flags);
int		convert_bc(va_list *ap, int *flags);
int		convert_b(va_list *ap, int *flags);
void	convert_w_mods(char **frm, int *flags, va_list *ap, int *ret);
int		convert_hhd(va_list *ap, int *flags);
int		convert_hho(va_list *ap, int *flags);
int		convert_hhu(va_list *ap, int *flags);
int		convert_hhx(va_list *ap, int *flags);
int		convert_hhbx(va_list *ap, int *flags);
int		convert_hd(va_list *ap, int *flags);
int		convert_ho(va_list *ap, int *flags);
int		convert_hu(va_list *ap, int *flags);
int		convert_hx(va_list *ap, int *flags);
int		convert_hbx(va_list *ap, int *flags);
int		convert_lld(va_list *ap, int *flags);
int		convert_llo(va_list *ap, int *flags);
int		convert_llu(va_list *ap, int *flags);
int		convert_llx(va_list *ap, int *flags);
int		convert_llbx(va_list *ap, int *flags);
int		convert_ld(va_list *ap, int *flags);
int		convert_lo(va_list *ap, int *flags);
int		convert_lu(va_list *ap, int *flags);
int		convert_lx(va_list *ap, int *flags);
int		convert_lbx(va_list *ap, int *flags);
int		convert_jd(va_list *ap, int *flags);
int		convert_jo(va_list *ap, int *flags);
int		convert_ju(va_list *ap, int *flags);
int		convert_jx(va_list *ap, int *flags);
int		convert_jbx(va_list *ap, int *flags);
int		convert_zd(va_list *ap, int *flags);
int		convert_zo(va_list *ap, int *flags);
int		convert_zu(va_list *ap, int *flags);
int		convert_zx(va_list *ap, int *flags);
int		convert_zbx(va_list *ap, int *flags);

#endif
