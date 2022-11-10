#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*news2;
	unsigned char	*news1;

	index = 0;
	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	while (index < n)
	{
		if (news1[index] != news2[index])
			return (news1[index] - news2[index]);
		index++;
	}
	return (0);
}
