/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:32:33 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/02/13 10:41:21 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	if (!(dest = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void	*ft_memset(void *b, char c, int len)
{
	char *b_char; 
		
	*b_char = (char *)b;
	if (b == NULL) 
		return NULL;

	while(*b_char && len > 0)
	{
 		*b_char = c;
		b_char++;
		len--;
	}

	return (b);
}
