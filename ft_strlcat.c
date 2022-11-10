#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len_src;
	size_t	len_dest;

	index = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	if (size < len_dest || size == 0)
		return (size + len_src);
	while (src[index] && (index + len_dest < size - 1))
	{
		dst[index + len_dest] = src[index];
		index++;
	}
	dst[index + len_dest] = '\0';
	return (len_dest + len_src);
}
