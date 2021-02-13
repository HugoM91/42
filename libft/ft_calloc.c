/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:33:12 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/02/13 10:33:14 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	i = 0;
	if (!(dst = malloc(total)))
		return (NULL);
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}
