#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*s2;

	index = 0;
	s2 = (unsigned char *)s;
	while (index < n)
	{
		if (s2[index] == (unsigned char)c)
			return ((void *)s + index);
		index++;
	}
	return (0);
}
