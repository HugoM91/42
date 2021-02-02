#include <stdio.h>
#include <stdlib.h>
char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	if (!(dest = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void	*ft_memset(void *b, char c, int len)
{
    char *b_char = (char *)b;

    if (b == NULL) return NULL;

    while(*b_char && len > 0)
    {
        *b_char = c;
        b_char++;
        len--;
    }

    return b; //as this pointer has not changed
}
/*
memset() is used to fill a block of memory with a particular value.
The syntax of memset() function is as follows :

// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting 
//         from ptr to be filled
void *memset(void *ptr, int x, size_t n);

Note that ptr is a void pointer, so that we can pass any type of pointer to this function.
*/