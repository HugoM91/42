/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:51:29 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/03/02 10:51:31 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_char(char c, t_flags flags);
int					ft_string(char *str, t_flags flags);
int					ft_percent(t_flags flags);
int					ft_flagdot(const char *save, int start, t_flags *flags,
va_list args);
int					ft_hexa3(char *hexa, t_flags flags);
int					ft_hexa2(char *hexa, t_flags flags);
int					ft_hexa(unsigned int ui, int lower, t_flags flags);
int					ft_int4(char *str, t_flags flags);
int					ft_int3(char *d_i, int save_i, t_flags flags);
int					ft_int2(char *d_i, int save_i, t_flags flags);
int					ft_int(int i, t_flags flags);
int					ft_estim(long n);
char				*ft_gen(char *rtn, long nbr, int len, int isneg);
char				*treat_base(unsigned long long ull_save, int base,
char *rtn, int count);
void				ft_putchar(char c);
int					ft_putchar2(int c);
char				*ft_u_itoa(unsigned int n);
char				*ft_itoa(int n);
int					ft_istype(int c);
int					ft_isflags(int c);
char				*ft_str_tolower(char *str);
int					ft_putchar2(int c);
int					ft_precs(char *str, int prec);
int					ft_width(int width, int minus, int has_zero);
char				*ft_ull_base(unsigned long long ull, int base);
int					ft_pointer2(char *pointer, t_flags flags);
int					ft_pointer(unsigned long long ull, t_flags flags);
int					ft_flagparse(const char *tra, int i, t_flags *flags,
va_list args);
int					ft_treat2(int c, t_flags flags, va_list args);
int					ft_treat(const char *traverse, va_list args);
int					ft_uint3(char *unsi_int, t_flags flags);
int					ft_uint2(char *unsi_int, t_flags flags);
int					ft_uint(unsigned int unsi, t_flags flags);
t_flags				ft_flagminus(t_flags flags);
t_flags				ft_flagdigit(char c, t_flags flags);
t_flags				ft_flagwidth(va_list args, t_flags flags);

#endif
