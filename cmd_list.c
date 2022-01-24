#include "push_swap.h"

t_cmds	*ft_cmdnew(char *cmd)
{
	t_cmds	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	 (*new_elem).cmd = cmd;
	 (*new_elem).next = NULL;
	 return (new_elem);
}

t_cmds	*ft_cmdlast(t_cmds *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_cmdadd_back(t_cmds **lst, t_cmds *new)
{
	t_cmds	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_cmdlast(*lst);
	last->next = new;
}

int	ft_cmdsize(t_cmds *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = (*lst).next;
	}
	return (size);
}

void	ft_cmddel_last(t_cmds **lst)
{
	t_cmds	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	temp = *lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}
