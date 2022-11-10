#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	index;
	size_t			size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		return (ft_strdup(""));
	if (size < len)
		len = size;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (s[index] && index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
