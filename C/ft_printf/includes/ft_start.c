/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:41:27 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/03/02 10:55:17 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int		ft_flagparse(const char *tra, int i, t_flags *flags, va_list args)
{
	while (tra[i])
	{
		if (!ft_isdigit(tra[i]) && !ft_istype(tra[i])
		&& !ft_isflags(tra[i]))
			break ;
		if (tra[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (tra[i] == '.')
			i = ft_flagdot(tra, i, flags, args);
		if (tra[i] == '-')
			*flags = ft_flagminus(*flags);
		if (tra[i] == '*')
			*flags = ft_flagwidth(args, *flags);
		if (ft_isdigit(tra[i]))
			*flags = ft_flagdigit(tra[i], *flags);
		if (ft_istype(tra[i]))
		{
			flags->type = tra[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_treat2(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_char(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_string(va_arg(args, char *), flags);
	else if (c == 'p')
		count = ft_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count = ft_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x')
		count += ft_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_percent(flags);
	return (count);
}

int		ft_treat(const char *traverse, va_list args)
{
	int			i;
	t_flags		flags;
	int			count;

	i = 0;
	count = 0;
	while (1)
	{
		flags = ft_flags();
		if (!traverse[i])
			break ;
		else if (traverse[i] == '%' && traverse[i + 1])
		{
			i = ft_flagparse(traverse, ++i, &flags, args);
			if (ft_istype(traverse[i]))
				count += ft_treat2((char)flags.type, flags, args);
			else if (traverse[i])
				count += ft_putchar2(traverse[i]);
		}
		else if (traverse[i] != '%')
			count += ft_putchar2(traverse[i]);
		i++;
	}
	return (count);
}
