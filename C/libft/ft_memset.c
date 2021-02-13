/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:32:33 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/02/13 12:24:00 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *b_char;
  
	b_char = (char *)b;

	if (b == NULL)
		return (NULL);
	while (*b_char && len > 0)
	{
		*b_char = (unsigned char)c;
		b_char++;
		len--;
	}
	return (b);
}
