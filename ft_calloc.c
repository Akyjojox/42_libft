#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	if (size == 0 || count == 0)
	{
		size = 1;
		count = 1;
	}
	else if ((SIZE_MAX / count) < size)
		return (NULL);
	result = (char *)malloc(size * count);
	if (!result)
		return (NULL);
	ft_bzero(result, (size * count));
	return (result);
}
