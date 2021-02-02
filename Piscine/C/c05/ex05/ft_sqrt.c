/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 10:08:04 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/12/12 09:16:33 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	attempt(int nb, int now, int prev)
{
	if (now * now == nb && now * now <= 2147483647)
		return (now);
	else if (now == prev)
		return (0);
	else
		return (attempt(nb, (now + (nb / now)) / 2, now));
}

int	ft_sqrt(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
		return (attempt(nb, nb / 2, 2));
}
