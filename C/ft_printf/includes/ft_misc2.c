#include "ft_printf.h"

int		ft_putchar2(int c)
{
	ft_putchar(c);
	return (1);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_width(int width, int minus, int has_zero)
{
	int count;

	count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}




