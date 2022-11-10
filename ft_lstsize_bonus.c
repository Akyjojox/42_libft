#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	index;

	index = 0;
	while (lst != NULL)
	{
		index++;
		lst = lst->next;
	}
	return (index);
}
