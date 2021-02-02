#include "libft.h"

char
	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
	return (NULL);
}

/*
The C library function char *strchr(const char *str, int c) searches for the
 first occurrence of the character c (an unsigned char) in the string pointed
  to by the argument str.

This returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found.

*/

