#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
    
    i = 0;
	if (!dst)
		return (NULL);
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	return (dst);
}
/*
// Copies "numBytes" bytes from address "from" to address "to"
void * memcpy(void *to, const void *from, size_t numBytes);

*/