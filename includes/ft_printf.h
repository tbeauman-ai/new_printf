/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:50:23 by tbeauman          #+#    #+#             */
/*   Updated: 2024/11/24 17:16:10 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"
# include <convert_funs.h>
# include <unicode.h>
# include <stdint.h>
# define ABS(x) x < 0 ? -x : x

typedef struct	s_cvt
{
	int			(*convert_fun)(va_list *, int *);
}				t_cvt;
int				end_of_flags(char *frm);
int				ft_printf(const char *frm, ...);
void			flags_parse(char **frm, int **flags, va_list *ap);
void			atoi_parse(char **frm, int **flags, va_list *ap);
void			modifier_parse(char **frm, int **flags);
int				modifier_presence(int *flags);
int				length_int(int n, int base);
int				length_long(long n, long base);
int				length_unsint(unsigned int n, unsigned int base);
int				length_unslong(unsigned long n, unsigned long base);
int				length_ull(unsigned long long n, unsigned long long base);
int				length_ll(long long n, long long base);
int				uitab_len(unsigned int *s);
void			ft_putnbr_base(int n, int base);
void			ft_putnbr_base_uppercase(int n, int base);
void			ft_putlong_base(long n, long base);
void			ft_putunslong_base(unsigned long n, unsigned long base);
void			ft_putunslong_base_up(unsigned long n, unsigned long base);
void			ft_putull_base(unsigned long long n, unsigned long long base);
void			ft_putll_base(long long n, long long base);
void			ft_putull_base_up(unsigned long long n,
		unsigned long long base);
void			ft_putunsint_base(unsigned int n, unsigned int base);
void			ft_putunsint_base_up(unsigned int n, unsigned int base);
void			ft_putnegnbr_oct(int n);
void			ft_putneglong_oct(long n);
int				print_bc(unsigned int car);
int				print_bs(unsigned int *bs);
int				print_s(char *s, int *flags);
int				print_d(int d, int *flags);
int				print_bd(long d, int *flags);
int				print_o(int d, int *flags);
int				print_bo(long d, int *flags);
int				print_u(unsigned int d, int *flags);
int				print_bu(unsigned long d, int *flags);
int				print_p(long p, int *flags);
int				print_x(unsigned int x, int *flags);
int				print_bx(unsigned int x, int *flags);
int				print_jd(intmax_t d, int *flags);
int				print_jo(uintmax_t d, int *flags);
int				print_ju(uintmax_t d, int *flags);
int				print_jx(uintmax_t x, int *flags);
int				print_jbx(uintmax_t x, int *flags);
int				print_ld(long x, int *flags);
int				print_lo(unsigned long x, int *flags);
int				print_lu(unsigned long x, int *flags);
int				print_lx(unsigned long x, int *flags);
int				print_lbx(unsigned long x, int *flags);
int				print_zd(long d, int *flags);
int				print_zo(size_t x, int *flags);
int				print_zu(size_t x, int *flags);
int				print_zx(size_t x, int *flags);
int				print_zbx(size_t x, int *flags);
int				print_percent(int *flags);
int				just_print_spaces(int *flags);
void			easy_norm(int *flags, int d, int *ici, int *ret);
void			easy_normj(int *flags, intmax_t d, int *ici, int *ret);
void			easy_norml(int *flags, long d, int *ici, int *ret);

#endif
