/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:19:11 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/12/02 16:54:36 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		passa(char str)
{
	if (str <= 'z' && str >= 'a')
	{
		return (1);
	}
	else if (str <= 'Z' && str >= 'A')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(str + i) != '\0')
	{
		if (j == 0 && passa(*(str + i)))
		{
			if (*(str + i) <= 'z' && *(str + i) >= 'a')
			{
				*(str + i) = *(str + i) - 32;
				j = 1;
			}
		}
		else if (j == 1 && *(str + i) >= 'A' && *(str + i) >= 'Z')
		{
			*(str + i) = *(str + i) + 32;
		}
		else if (!(passa(*(str + i))))
			j = 0;
		i++;
	}
	return (str);
}
