#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
    char   *sentence;


    sentence = (char*)s;
    while(n > 0)
    {
        *sentence = '\0';
        sentence++;
        n--;
    }
}
/*

The bzero function places nbyte null bytes in the string s. 
This function is used to set all the socket structures with null values.

This function does not return anything.

Parameters
s − It specifies the string which has to be filled with null bytes. 
This will be a point to socket structure variable.


n − It specifies the number of bytes to be filled with null values.
 This will be the size of the socket structure.

*/
