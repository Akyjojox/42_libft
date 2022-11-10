#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		index;

	index = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	while (s[index] != '\0')
	{
		result[index] = s[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
