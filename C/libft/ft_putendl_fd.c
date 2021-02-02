#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd((char*)s, fd);
	ft_putchar_fd('\n', fd);
}