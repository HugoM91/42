/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:13:28 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/12/02 16:47:14 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (*(str + i) != '\0')
	{
		if (((*(str + i) <= 'z' && *(str + i) >= 'a')) ||
			((*(str + i) <= 'Z' && *(str + i) >= 'A')))
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_str_is_alpha(char *str)
{
	return (check(str));
}
