#include "ft_printf.h"


int		ft_isType(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_isFlags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

char	*ft_str_tolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}


int		ft_precs(char *str, int prec)
{
	int count;

	count = 0;
	while (str[count] && count < prec)
		ft_putchar(str[count++]);
	return (count);
}

