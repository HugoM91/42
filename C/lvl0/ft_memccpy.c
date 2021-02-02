#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

    i = 0;
	if (!dst || !src)
		return (NULL);
	while (i < n)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		if (*(unsigned char*)(src + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
/*
The memccpy() function operates as efficiently as possible on memory areas. 
It does not check for overflow of any receiving memory area. 
Specifically, memccpy() copies bytes from memory area *src into *dst, stopping 
after the first occurrence of c has been copied, or after n bytes have been copied, 
whichever comes first.
*/
