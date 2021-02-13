/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:26:26 by hmalaqui          #+#    #+#             */
/*   Updated: 2021/02/13 10:37:41 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *tmp;
    size_t    i;

    i = 0;
    if (!s)
        return (0);
    if (start >= ft_strlen(s))
    {
        if (!(tmp = malloc(1)))
            return (0);
        tmp[0] = '\0';
        return (tmp);
    }
    if (!(tmp = malloc(len + 1)))
        return (0);
    while (i < len && s[start + i])
    {
        tmp[i] = s[start + i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
