#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	index;
	size_t	index2;

	index = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[index] && index < len)
	{
		index2 = 0;
		while (s2[index2] == s1[index + index2] && (index + index2) < len)
			if (s2[++index2] == '\0')
				return ((char *)&s1[index]);
		index++;
	}
	return (0);
}
