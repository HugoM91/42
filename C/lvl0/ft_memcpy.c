#include "libft.h"

void
	*ft_memcpy(void *dst, const void *src, size_t n)
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
int	main(void)
{
	ft_memcpy("asd", "", 2);
}


/*
// Copies "numBytes" bytes from address "from" to address "to"
void * memcpy(void *to, const void *from, size_t numBytes);

*/