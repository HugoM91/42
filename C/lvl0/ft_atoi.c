#include "libft.h"

static int	get_return(unsigned long long ret, int neg, const char *nptr)
    {
        int count;

        count = 0;
        while (*nptr <= '1' || *nptr >= '9')
            nptr++;
        while (ft_isdigit(*(nptr + count)))
            count++;
        if (count >= 19)
            return (neg == -1 ? 0 : -1);
        if (ret > 9223372036854775807)
            return (neg == -1 ? 0 : -1);
        else
            return (ret * neg);
    }

int			ft_atoi(const char *nptr)
    {
        unsigned long long	ret;
        int					len;
        int					x;
        int					neg;

        neg = 1;
        x = -1;
        len = 0;
        ret = 0;
        while (ft_isspace(*nptr))
            nptr++;
        while (nptr[len])
            len++;
        while (++x <= len)
        {
            if (ft_isdigit(nptr[x]))
                ret = (ret * 10) + (nptr[x] - '0');
            else if (x == 0 && (nptr[x] == '-' || nptr[x] == '+'))
                neg = nptr[x] == '-' ? -1 : 1;
            else
                return (get_return(ret, neg, nptr));
        }
        return (get_return(ret, neg, nptr));
    }