#include<stdio.h> 
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>


typedef struct ordem {
	char*	to_print;
	int		lenght;
	char*	flag;
}	ordem;


void Myprintf(char *,...); 				//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.

int	ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	return (dest);
}

char*
        ft_toupper(char *str)
{
        int i;
        
        i = 0;
        while(str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            i++;
        }
        return(str);
}

char*
        ft_tolower(char *str)
{
        int i;
        
        i = 0;
        while(str[i])
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            i++;
        }
        return(str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char *str)
{
        int i;
        
        i = 0;
        while (str[i])
        {
                ft_putchar(str[i]);
                i++;
        }
        
} 

long int	ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int		ft_len(int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

int		ft_len_x(long long nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_d(int n, int base)
{
	int		len;
	char	*c;
	static char Representation[]= "0123456789abcdef";
	static char Representation2[]= "0123456789";
	int flag = 0;
	
	if ((int)n < 0)
	{
		flag = 1;
		n = n * -1;
	}
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	if (base == 10){
		while (len >= 0)
		{
			c[len] = Representation2[n % base];
			n = n / base;
			len--;
		}
	}
	else if (base == 16){
		while (len >= 0)
		{
			c[len] = Representation[n % base];
			n = n / base;
			len--;
		}
	}
	if (flag == 1)
		c = ft_strjoin("-", c);
	return (c);
}

char		*ft_itoa_x(unsigned long n, int base)
{
	int		len;
	char	*c;
	static char Representation[]= "0123456789abcdef";
	static char Representation2[]= "0123456789";

	len = ft_len_x(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	if (base == 10){
		while (len >= 0)
		{
			c[len] = Representation2[n % base];
			n = n / base;
			len--;
		}
	}
	else if (base == 16){
		while (len >= 0)
		{
			c[len] = Representation[n % base];
			n = n / base;
			len--;
		}
	}
	return (c);
}

int		ft_atoi(const char *str)
{
	int neg;
	int i;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

char	*ft_utoa(unsigned int n)
{
	char			*p;
	int				size;
	unsigned int	x;

	x = n;
	size = 0;
	while (x > 10)
	{
		x /= 10;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			p[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (p);
}

char	*format_x(char *c)
{
	int len = ft_strlen(c);
	char *dest;
	int i = 0;
	int h;
	int j = 0;

	dest=malloc(sizeof(char)*(len+1));
	while(i < len)
	{
		if(c[i] == '0' && i < 3)
			h = 0;
		else
		{
			dest[j] = c[i];
			j++;
		}
		i++;
	}
	dest[j]='\0';
	return (dest);
}

//-----------------------
void Myprintf(char* format,...) 
{ 
	char *traverse; 
	unsigned int i; 
	char *s; 
	long long l;
	int k = 0;
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 
	traverse = format;

	while(*traverse != '\0')
	{
		while( *traverse != '%' ) 
		{ 
 			ft_putchar(*traverse);
			traverse++; 
		}

		traverse++; 

		if (*traverse == '0')
		{
			traverse++;
			while (*traverse >= '0' && *traverse <= '9')
			{
				int h = ft_atoi(traverse);
				while(h > 0)
				{
					ft_putchar('0');
					h--;
				}
				traverse++;
				break;
			}	
		}
		if (*traverse == '.')
		{
			traverse++;
			while (*traverse >= '0' && *traverse <= '9')
			{
				int h = ft_atoi(traverse);
				while(h > 0)
				{
					ft_putchar('0');
					h--;
				}
				traverse++;
				break;
			}
		}
		if (*traverse == '%')
		{
			i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
			ft_putchar('%');
			break;
		}
		if (*traverse == 'c')
		{
			i = va_arg(arg,int); //Fetch Hexadecimal representation
			int len = 1;
			ft_putchar(i);
			break;
		}
		if (*traverse == 's')
		{
			s = va_arg(arg,char *); //Fetch Hexadecimal representation
			ft_strlen(s);
			ft_putstr(s);
			break;
		}
		if (*traverse == 'i' || *traverse == 'd')
		{
			i = va_arg(arg, unsigned int);
			ft_strlen(ft_itoa_d(i,10));
            ft_putstr(ft_itoa_d(i,10));
			break;
		}
		if (*traverse == 'x')
		{
			i = va_arg(arg,long long); //Fetch Hexadecimal representation
			ft_strlen(ft_itoa_x(i,16));
			ft_putstr(format_x(ft_itoa_x(i,16)));
			break;
		}
		if (*traverse == 'X')
		{
			i = va_arg(arg, long long); //Fetch Hexadecimal representation
			ft_putstr(format_x(ft_toupper(ft_itoa_x(i,16))));
			ft_strlen(ft_itoa_x(i,16));
			break;
		}
		if (*traverse == 'u')
		{
			i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
			ft_strlen(ft_itoa_x(i,10));
			ft_putstr(ft_itoa_x(i,10));
			break;
		}
		if (*traverse == 'p')
		{
			l = va_arg(arg,long long int); //Fetch Hexadecimal representation
			ft_strlen(ft_itoa_x(l,16));
			ft_putstr("0x");
			ft_putstr(format_x(ft_itoa_x(l,16)));
			break;
		}
		traverse++;
		if(*traverse == '\0')
			break;
	}

	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 

//---------------------------------------------------------------
int main() 
{ 
	char *c = "0sadsa asdas asda d";
	char *p = (char *)&c;

	char first_byte = p[0];
	char second_byte = p[1];

	int o = 18855;

	//printf("\n1 = %d , 2 = %d\n ", 1, 22);
	//Myprintf("1 = %05d dfddfsf %i ff", 20);
	//printf("%*.*d\n", 15, -2, 20);
	Myprintf("%05d", 20);
	return 0;
} 
/*

• It must not do the buffer management like the real printf
• It will manage the following conversions: cspdiuxX%
• It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
FLAGS

	- = Left-justify within the given field width; Right justification is the default (see width sub-specifier).
	0 = Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier).
	. = Precision
	* = The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.


 * % - The percent character, %
 * c - Single character (char) value
 * s - String constant or variable (char*)
 * d - Integer (int, short int, long int) - value
 * i - Integer (int, short int, long int) - value
 * x - Unsigned hexadecimal value, lowercase a–f, no leading 0 or x
 * X - Unsigned hexadecimal value, uppercase A–F, no leading 0 or X
 * 
 * 
 * p - Pointer  
 * u - Unsigned integer (unsigned int, unsigned short int, unsigned, long int) value
 * 
 * https://www.cprogramming.com/tutorial/printf-format-strings.html
 * 
 * 
 * 
 * #######   The Minus Sign Flag: -
Finally, the minus sign will cause the output to be left-justified. This is important if you are using the width specifier and you want the padding to appear at the end of the output instead of the beginning:
1
printf( "|%-5d|%-5d|\n", 1, 2 );
displays:
1
|1    |2    |
With the padding at the end of the output
###### The Zero Flag: 0
Using 0 will force the number to be padded with 0s. This only really matters if you use the width setting to ask for a minimal width for your number. For example, if you write:
1
printf( "%05d\n", 10 );
You would get:
1
00010:
https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160

 */
