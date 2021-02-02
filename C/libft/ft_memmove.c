#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i++;
		}
	}
	return (dst);
}
/*

The C library function void *memmove(void *str1, const void *str2, size_t n) 
copies n characters from str2 to str1, but for overlapping memory blocks, 
memmove() is a safer approach than memcpy().


memcpy vs memmove
main
{
    char a[16];
    char b[16];

    memcpy(a,b,16);           // valid
    memmove(a,b,16);          // Also valid, but slower than memcpy.
    memcpy(&a[0], &a[1],10);  // Not valid since it overlaps.
    memmove(&a[0], &a[1],10); // valid. 
}
*/
