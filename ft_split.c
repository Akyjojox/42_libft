#include "libft.h"

static int	is_charset(char c, char str)
{
	return (c == str);
}

static char	*ft_strndup(char *str, size_t size)
{
	char	*result;
	size_t	index;

	index = 0;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while (str[index] && index < size)
	{
		result[index] = str[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

static int	ft_sizemalloc(char const *str, char c)
{
	size_t	len;
	size_t	index;

	len = 0;
	index = 0;
	if (!is_charset(c, str[0]) && str[0] != '\0')
		len++;
	while (str[index])
	{
		if (is_charset(c, str[index]) && !is_charset(c, str[index + 1])
			&& str[index + 1] != '\0')
			len++;
		index++;
	}
	return (len);
}

char	**ft_free_result(char **result)
{
	size_t	index;

	index = 0;
	while (result[index] == NULL)
	{
		free(result[index]);
		index++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	tab[3];

	if (s == NULL)
		return (NULL);
	ft_bzero(tab, sizeof(tab));
	result = (char **)malloc(sizeof(char *) * (ft_sizemalloc(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[tab[0]])
	{
		while (is_charset(c, s[tab[0]]))
			tab[0]++;
		tab[1] = tab[0];
		while (!is_charset(c, s[tab[0]]) && s[tab[0]] != '\0')
			tab[0]++;
		if ((tab[0] - tab[1]) > 0)
		{
			result[tab[2]] = ft_strndup((char *)&s[tab[1]], tab[0] - tab[1]);
			if (result[tab[2]++] == NULL)
				return (ft_free_result(result));
		}
	}
	result[ft_sizemalloc(s, c)] = 0;
	return (result);
}
