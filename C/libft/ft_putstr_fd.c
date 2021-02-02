#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (str && *str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}