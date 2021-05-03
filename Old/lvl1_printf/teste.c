#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/*
int (integer values) uses %d
float (floating point values) uses %f
char (single character values) uses %c
character strings (arrays of characters, discussed later) use %s 
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char    identify_type(char input, int nr)
{
    int i = 0;
    char ret;
    
    if (input == 'd')
        ft_putchar('D');
    else if (input == 's')
        ft_putchar('S');
    else if (input == 'f')
        ft_putchar('F');
    else if (input == 'c')
        ft_putchar('C');
    
    return ret;
}

int licious_printf(const char *format, ...)
{
    int i = 0;
    int j = 0;

    while(format[i]!='\0')
    {
        if (format[i] == '%')
        {
            i++;
            identify_type(format[i], j);
            j++;
        }
        else 
        {
            j++;
            ft_putchar(format[i]);
        }
        i++;
    }
	return 42;
}


int	my_printf(const char *format, ...)
{
	va_list args;
    const char *str;
	
	va_start(args, format);
    // apanha as variaveis ...
    while (str) {
        str = va_arg(args, const char *);
        printf("INT %d\n", str);
        printf("---------------------------\n");
    }
    // apanha o format
    //int i = 0;
    
    //printf("%d ", args[0]);
    
    va_end(args);
    return 42;
}


int main(void)
{
    int l = 6888;
    int l2 = 1000;
    char* k = "adeys";
    
    //licious_printf("\n%s and a %f", k,k);
    //printf("\n%ds ola %s\n", l,k);
    my_printf("\n%ds and %d ola %s", l,l2,k,'\0');
}






