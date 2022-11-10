#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	index;
	int	result;

	sign = 1;
	index = 0;
	result = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign *= -1;
		index++;
	}
	while (nptr[index] >= 48 && nptr[index] <= 57)
		result = result * 10 + (nptr[index++] - 48);
	return (result * sign);
}
