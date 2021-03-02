/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_string_per.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:52:29 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/03/02 10:53:12 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_precs("%", 1);
	count += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_precs("%", 1);
	return (count);
}

int		ft_int4(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_width(flags.dot, ft_strlen(str), 0);
		count += ft_precs(str, flags.dot);
	}
	else
		count += ft_precs(str, ft_strlen(str));
	return (count);
}

int		ft_string(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_int4(str, flags);
	if (flags.dot >= 0)
		count += ft_width(flags.width, flags.dot, 0);
	else
		count += ft_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_int4(str, flags);
	return (count);
}

int		ft_char(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
