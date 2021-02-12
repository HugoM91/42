#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
    i = 0;
	if (!(dst = malloc(total)))
		return (NULL);
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}

/*
set memoru blocks to 0 instead of random values
*/
