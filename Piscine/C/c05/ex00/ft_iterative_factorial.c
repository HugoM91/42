/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:07:16 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/12/10 15:29:50 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int i;
	int j;

	if (nb < 0)
		return (0);
	i = 1;
	j = 1;
	while (i < nb + 1)
	{
		j = j * i;
		i++;
	}
	return (j);
}
