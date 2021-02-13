/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:28:26 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/02/13 10:36:12 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i--)
		if (*(s + i) == c)
			return ((char *)(s + i));
	return (NULL);
}
