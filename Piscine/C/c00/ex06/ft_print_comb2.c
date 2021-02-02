/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmalaqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:32:20 by hmalaqui          #+#    #+#             */
/*   Updated: 2020/11/30 10:39:46 by hmalaqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_space_coma(int i)
{
	i == 1 ? write(1, ", ", 2) : write(1, " ", 1);
}

int		sum_nums(int arr[4])
{
	int res;

	res = arr[0] + arr[1] + arr[2] + arr[3];
	return (res);
}

void	print_func(int nums[4])
{
	int num1;
	int num2;
	int num3;
	int num4;

	num1 = nums[0] + '0';
	num2 = nums[1] + '0';
	num3 = nums[2] + '0';
	num4 = nums[3] + '0';
	write(1, &num1, 1);
	write(1, &num2, 1);
	print_space_coma(0);
	write(1, &num3, 1);
	write(1, &num4, 1);
	if (!(sum_nums(nums) == 35))
	{
		print_space_coma(1);
	}
}

void	do_while(int nums[4])
{
	while (nums[0] <= 9)
	{
		while (nums[1] <= 8)
		{
			while (nums[2] <= 9)
			{
				while (nums[3] <= 9)
				{
					if (!(nums[0] == nums[2] && nums[1] == nums[3]))
					{
						print_func(nums);
					}
					nums[3] = nums[3] + 1;
				}
				nums[2] = nums[2] + 1;
				nums[3] = nums[1] + 1;
			}
			nums[1] = nums[1] + 1;
			nums[2] = nums[0];
		}
		nums[0] = nums[0] + 1;
		nums[1] = 0;
	}
}

void	ft_print_comb2(void)
{
	int arr[4];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 1;
	do_while(arr);
}