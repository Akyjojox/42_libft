#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (del == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		if ((*lst)->content != NULL)
			del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
