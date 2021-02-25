#include<stdarg.h>
#include <stdio.h>
#include<unistd.h>

//  ----------------------------------------------------------------
typedef	struct		s_flags
{
	int				already_print;
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}                   t_flags;

t_flags     ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}
//  ----------------------------------------------------------------

int		ft_isType(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_isFlags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putchar2(int c)
{
	ft_putchar(c);
	return (1);
}

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
//  ----------------------------------------------------------------

t_flags		ft_flagMinus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flagDigit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		ft_flagWidth(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			ft_flagDot(const char *save, int start,
			t_flags *flags, va_list args)
{
	int i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[i]))
			flags->dot = (flags->dot * 10) + (save[i++] - '0');
	}
	return (i);
}
//	###############---------------------------------------------------------------



//  ###############----------------------------------------------------------------

int			ft_flag_parse(const char *traverse, int i, t_flags *flags, va_list args)
{
	while (traverse[i])
	{
		if (!ft_isdigit(traverse[i]) && !ft_isType(traverse[i])
		&& !ft_isFlags(traverse[i]))
			break ;
		if (traverse[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (traverse[i] == '.')
			i = ft_flagDot(traverse, i, flags, args);
		if (traverse[i] == '-')
			*flags = ft_flagMinus(*flags);
		if (traverse[i] == '*')
			*flags = ft_flagWidth(args, *flags);
		if (ft_isdigit(traverse[i]))
			*flags = ft_flagDigit(traverse[i], *flags);
		if (ft_isType(traverse[i]))
		{
			flags->type = traverse[i];
			break ;
		}
		i++;
	}
	return (i);
}


int		ft_treatment(int c, t_flags flags, va_list args)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_treat_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count = ft_treat_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = ft_treat_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_treat_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += ft_treat_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_treat_percent(flags);
	return (char_count);
}

//  ----------------------------------------------------------------


void myprintf(char* format,...) 
{ 
	const char *traverse; 
	int i; 
    t_flags		flags;

	va_list arg; 
    int char_count;

    char_count = 0;
	va_start(arg, format); 
    traverse = format;
    
    while(1)
    {
        flags = ft_init_flags();
        if (!traverse[i])
            break;

        else if (traverse[i] == '%' && traverse[i + 1])
		{
			i = ft_flag_parse(traverse, ++i, &flags, arg);
			if (ft_isType(traverse[i]))
				char_count += ft_treatment((char)flags.type, flags, arg);
			else if (traverse[i])
				char_count += ft_putchar2(traverse[i]);
		}

        else if (traverse[i] != '%')
			char_count += ft_putchar2(traverse[i]);
    }
	va_end(arg); 
}

//  ----------------------------------------------------------------

int main()
{
    printf("ola %d %d",5, 10);
    //myprintf("ola sou o  %d %d",5, 10);
}