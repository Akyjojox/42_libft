#include "libft.h"

static int	is_charset(char c, char const *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

static int	ft_sizemalloc(char *s1, char const *set)
{
	size_t	len;
	size_t	index;
	size_t	rindex;

	index = 0;
	rindex = 0;
	len = ft_strlen(s1);
	if (!is_charset(s1[0], set) && !is_charset(s1[len - 1], set))
		return (len);
	while (is_charset(s1[index], set))
		index++;
	if (len == index)
		return (0);
	while (is_charset(s1[len - rindex - 1], set))
		rindex++;
	return (len - (index + rindex));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	index;
	size_t	sizemalloc;
	size_t	count_charset;

	if (!s1 || !set)
		return (NULL);
	index = 0;
	count_charset = 0;
	sizemalloc = ft_sizemalloc((char *)s1, set);
	result = (char *)malloc(sizeof(char) * (sizemalloc + 1));
	if (!result)
		return (NULL);
	while (is_charset(s1[count_charset], set))
		count_charset++;
	while (index < sizemalloc)
	{
		result[index] = s1[count_charset + index];
		index++;
	}
	result[sizemalloc] = 0;
	return (result);
}
