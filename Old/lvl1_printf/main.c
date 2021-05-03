
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*
void	print_ints(int num, ...)    
{
	va_list args;
	int i;
	int value;
	
	va_start(args, num);
	i = 0;
	while (i < num)
	{
		value = va_arg(args,int);
		printf("%d: %d\n", i, value);
		i++;
	}
	va_end(args);
}*/
///-------------
/*
int	ft_printf(const char *restrict format, ...)		EYwek - github
{
	t_flags	flags;
	int		bytes;
	va_list	args;
	char	*str;

	bytes = 0;
	flags.bytes = 0;
	flags.total_bytes = 0;
	va_start(args, format);
	str = (char*)format;
	while (*str)
		if (*str == '%')
		{
			str++;
			bytes += ft_handle(&str, args, &flags);
		}
		else
			bytes += ft_write_until_percentage(&str, &flags);
	va_end(args);
	if (flags.bytes > 0)
		write(STDOUT, flags.buffer, (size_t)flags.bytes);
	return (bytes);
}

*/


int	my_printf(const char *format, ...)
{
	va_list args;
	int	done;
	char	*substring;
	
//##se comecar por Jacob o programa imprime (return done) senao (return 0)
	substring = strstr(format, "Jacob");
	if (substring != format)
		return 0;
// ---------------------------------------

// Analisa as variaveis que passaram pelo utilizador ((const char *format, ...))
// args = ... 

	va_start(args, format);
	va_end(args);

// ??????


//##o que vai imprimir----------------
	write(STDOUT, flags.buffer, (size_t)flags.bytes);
	done = vfprintf (stdout, format, args);
	return done;
}

int	main(void)
{
	printf("\n%d",my_printf("Jacoba ola eu sou o Jacob"));
}



/* Conceitos a saber

printf
fprintf
stdout (tambem existe stderr)
FILE stream



*/
