#include <stdio.h>
#include <stdarg.h>


int	my_printf(const char *format, ...)
{
	va_list args;
	int	done;
	char	*substring;
    const char *str;
	
    //printf("%s\n", format);
    //printf("%s : %d , %d , %d", format, args);


	va_start(args, format);
    
    while (str) {
        str = va_arg(args, const char *);
        printf("INT %d\n", str);


    }

	va_end(args);

	return 42;
}


int main(void)
{
    my_printf("ola", 3,4 ,5,6,7,8,9,10);
}