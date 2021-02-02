#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	
	i = 0;
	while(s[i] != '\0')
		i++;
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i--)
		if (*(s + i) == c)
			return ((char *)(s + i));
	return (NULL);
}
/*
The C library function char *strrchr(const char *str, int c) searches for the last occurrence of the character c (an unsigned char) in the string pointed to, by the argument str.

This function returns a pointer to the last occurrence of character in str. If the value is not found, the function returns a null pointer.
*/
