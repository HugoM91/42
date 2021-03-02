/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:54:12 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/03/02 10:54:17 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	const char	*traverse;
	va_list		args;
	int			count;

	traverse = ft_strdup(format);
	count = 0;
	va_start(args, format);
	count += ft_treat(traverse, args);
	va_end(args);
	free((char *)traverse);
	return (count);
}
