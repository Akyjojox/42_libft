#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*tmp;
	unsigned char	*dst;

	tmp = (unsigned char *)src;
	dst = (unsigned char *)dest;
	index = 0;
	if (tmp < dst)
		while (n--)
			dst[n] = tmp[n];
	else
	{
		while (n > index)
		{
			dst[index] = tmp[index];
			index++;
		}
	}
	return (dst);
}
