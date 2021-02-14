#include<stdio.h> 
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>

void Myprintf(char *,...); 				//Our printf function
char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.

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

int			ft_len(long int nbr)
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

char		*ft_itoa(int n, int base)
{
	int		len;
	char	*c;
	static char Representation[]= "0123456789abcdef";
	static char Representation2[]= "0123456789";

	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	if (base == 10){
		while (len >= 0)
		{
			c[len] = '0' + (n % base);
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


void Myprintf(char* format,...) 
{ 
	char *traverse; 
	unsigned int i; 
	char *s; 
	
	//Module 1: Initializing Myprintf's arguments 
	va_list arg; 
	va_start(arg, format); 

	for(traverse = format; *traverse != '\0'; traverse++) 
	{

		while( *traverse != '%' ) 
		{ 
 			ft_putchar(*traverse);
			traverse++; 
		} 
		
		traverse++; 
		
		//Module 2: Fetching and executing arguments
		switch(*traverse) 
		{ 
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						ft_putchar(i);
						break;
            case 's': s = va_arg(arg,char *); 		//Fetch string
						ft_putstr(s);
						break;
			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						printf("VALOR DO I %u\n", i);
						if(i<0) 
						{ 
							i = -i;
						} 
						printf("ITOA RESULT %s\n", ft_itoa(i,10));
                        ft_putstr(ft_itoa(i,10));
						break; 
            case 'i' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						
						if(i<0) 
						{ 
							i = -i;
						} 
                        ft_putstr(ft_itoa(i,10));
						break; 
			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						ft_putstr(ft_itoa(i,16));
						
						break; 
            case 'X': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						ft_putstr(ft_toupper(ft_itoa(i,16)));
						break;
			case 'u': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						ft_putstr(ft_itoa(i,10));
						break;
		}	
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 


int main() 
{ 
	int a = 425;
	int b = 99999;
	Myprintf("%d", a); 
	printf("\n0 - %02d\n", 1);
	printf( "- - %-5d - %-5d\n", 1, 2 );
	printf( ". - %.5d - %.5d\n", 1, 2 );
	printf( "* - %*5d - %*57d\n", 1, 2 );
	return 0;
} 
/*
 * % - The percent character, %
 * c - Single character (char) value
 * s - String constant or variable (char*)
 * d - Integer (int, short int, long int) - value
 * p - Memory location or address in hexadecimal (pointer)
 * i - Integer (int, short int, long int) - value
 * x - Unsigned hexadecimal value, lowercase a–f, no leading 0 or x
 * X - Unsigned hexadecimal value, uppercase A–F, no leading 0 or X
 * 
 * 
 * u - Unsigned integer (unsigned int, unsigned short int, unsigned, long int) value
 * 
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
00010




 */
