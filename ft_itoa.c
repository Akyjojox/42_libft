#include "libft.h"

static int	ft_sizemalloc(long int size)
{
	int	len;

	len = 0;
	if (size == 0)
		return (1);
	if (size < 0)
	{
		size *= -1;
		len++;
	}
	while (size > 0)
	{
		size /= 10;
		len++;
	}
	return (len);
}

char	*ft_resultfill(char *result, long lnbr, size_t sizemalloc)
{
	if (lnbr == 0)
	{
		result[0] = 48;
		return (result);
	}
	if (lnbr < 0)
	{
		result[0] = '-';
		lnbr *= -1;
	}
	while (lnbr > 0)
	{
		result[sizemalloc--] = 48 + (lnbr % 10);
		lnbr /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	lnbr;
	size_t	sizemalloc;

	lnbr = n;
	sizemalloc = ft_sizemalloc(lnbr);
	result = (char *)malloc(sizeof(char) * (sizemalloc + 1));
	if (!result)
		return (NULL);
	result[sizemalloc--] = '\0';
	return (ft_resultfill(result, lnbr, sizemalloc));
}