/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:47:13 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/03/02 10:48:09 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uint3(char *unsi_int, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
	count += ft_precs(unsi_int, ft_strlen(unsi_int));
	return (count);
}

int		ft_uint2(char *unsi_int, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		count += ft_uint3(unsi_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_width(flags.width, 0, 0);
	}
	else
		count += ft_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		count += ft_uint3(unsi_int, flags);
	return (count);
}

int		ft_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		count;

	count = 0;
	unsi = (unsigned int)(4294967295 + 1 + unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		count += ft_width(flags.width, 0, 0);
		return (count);
	}
	unsi_int = ft_u_itoa(unsi);
	count += ft_uint2(unsi_int, flags);
	free(unsi_int);
	return (count);
}
