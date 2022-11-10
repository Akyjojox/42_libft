#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (*s1)
		result[index++] = *s1++;
	while (*s2)
		result[index++] = *s2++;
	result[index] = '\0';
	return (result);
}
