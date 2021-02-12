#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int   i;
	unsigned int   s_len;
	char           *dest;

    i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		if (!(dest = malloc(sizeof(char) * 1)))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/

