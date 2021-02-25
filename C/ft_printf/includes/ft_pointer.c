#include "ft_printf.h"

char	*treat_base(unsigned long long ull_save, int base,
char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_save;
	int					count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}


int	ft_pointer2(char *pointer, t_flags flags)
{
	int count;

	count = 0;
	count += ft_precs("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_width(flags.dot, ft_strlen(pointer), 1);
		count += ft_precs(pointer, flags.dot);
	}
	else
		count += ft_precs(pointer, ft_strlen(pointer));
	return (count);
}

int			ft_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		count;

	count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		count += ft_precs("0x", 2);
		return (count += ft_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		count += ft_pointer2(pointer, flags);
	count += ft_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		count += ft_pointer2(pointer, flags);
	free(pointer);
	return (count);
}