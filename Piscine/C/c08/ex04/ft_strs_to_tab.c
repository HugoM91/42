/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 18:23:33 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/12/17 10:49:49 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		size;

	size = 0;
	while (str[size])
	{
		size++;
	}
	return (size);
}

void				ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

char				*ft_strdup(char *str)
{
	int		size;
	char	*dup;

	size = ft_strlen(str);
	dup = malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (0);
	ft_strcpy(dup, str);
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*asd;
	int				i;

	asd = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!asd)
		return (0);
	i = 0;
	while (i < ac)
	{
		asd[i].size = ft_strlen(av[i]);
		asd[i].str = av[i];
		asd[i].copy = ft_strdup(av[i]);
		i++;
	}
	asd[i].str = 0;
	return (asd);
}
