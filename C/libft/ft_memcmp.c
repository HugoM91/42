#include "libft.h"

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}
/*
The memcmp() function compares the first n bytes (each interpreted as unsigned char)
of the memory areas s1 and s2. RETURN VALUE top. 
The  memcmp() prototype int memcmp( const void* lhs, const void* rhs, size_t count ); 
The memcmp() function takes three arguments: lhs, rhs and count. 
This function first interprets the objects pointed to by lhs and rhs as arrays of unsigned char.
Then it compares the first count characters of lhs and rhs lexicographically. 
It is defined in <cstring
*/
