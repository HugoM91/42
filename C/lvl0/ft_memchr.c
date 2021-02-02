#include "libft.h"

void
	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

    i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (*(unsigned char*)(s + i) == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
/*
The C library function void *memchr(const void *str, int c, size_t n)
 searches for the first occurrence of the character c (an unsigned char)
  in the first n bytes of the string pointed to, by the argument str.

int main () 
{
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
Let us compile and run the above program that will produce the following result −

String after |.| is - |.tutorialspoint.com|
*/

