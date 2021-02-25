

//------------------------------------------------------------------



//------------------------------------------------------------------
int		ft_treat_percent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrprec("%", 1);
	char_count += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrprec("%", 1);
	return (char_count);
}



//------------------------------------------------------------------
static int		ft_in_put_part_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstrprec(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		ft_put_part_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_hexa(hexa, flags);
	return (char_count);
}

int				ft_treat_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_put_part_hexa(hexa, flags);
	free(hexa);
	return (char_count);
}


//------------------------------------------------------------------

static int	ft_in_put_part_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
	char_count += ft_putstrprec(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

static int	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	return (char_count);
}

int			ft_treat_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	unsi_int = ft_u_itoa(unsi);
	char_count += ft_put_part_uint(unsi_int, flags);
	free(unsi_int);
	return (char_count);
}


//------------------------------------------------------------------

static int	ft_in_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	char_count += ft_putstrprec(d_i, ft_strlen(d_i));
	return (char_count);
}

static int	ft_put_part_int(char *d_i, int save_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(d_i, save_i, flags);
	return (char_count);
}

int			ft_treat_int(int i, t_flags flags)
{
	char	*d_i;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
	{
		char_count += ft_treat_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putstrprec("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	d_i = ft_itoa(i);
	char_count += ft_put_part_int(d_i, save_i, flags);
	free(d_i);
	return (char_count);
}

//------------------------------------------------------------------

static int	ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(pointer), 1);
		char_count += ft_putstrprec(pointer, flags.dot);
	}
	else
		char_count += ft_putstrprec(pointer, ft_strlen(pointer));
	return (char_count);
}

int			ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_treat_width(flags.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += ft_treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}

//------------------------------------------------------------------

static int		ft_put_part_int(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int				ft_treat_string(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.width, flags.dot, 0);
	else
		char_count += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}


//------------------------------------------------------------------
int		ft_treat_char(char c, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	char_count = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}

