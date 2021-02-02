/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:42:02 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/11/30 13:08:35 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writte2(char i, char j, char k)
{
	char	h;
	char	g;

	h = ',';
	g = ' ';
	if (i == '7' && j == '8' && k == '9')
	{
		h = ',';
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
	}
	else
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		write(1, &h, 1);
		write(1, &g, 1);
	}
}

void	writte(char i, char j, char k)
{
	while (i <= '9')
	{
		while (j <= '9')
		{
			if (i < j)
			{
				while (k <= '9')
				{
					if (j < k)
					{
						writte2(i, j, k);
					}
					k++;
				}
			}
			k = '2';
			++j;
		}
		j = '1';
		++i;
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '1';
	k = '2';
	writte(i, j, k);
}
