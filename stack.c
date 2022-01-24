#include "push_swap.h"

t_stack	*ft_stacknew(int number)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		return (NULL);
	 (*new_elem).number = number;
	 (*new_elem).index = 0;
	 (*new_elem).keep_in_stack = 0;
	 (*new_elem).next = NULL;
	 (*new_elem).prev = NULL;
	 return (new_elem);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		(*new).next = NULL;
		(*new).prev = NULL;
		*lst = new;
		return ;
	}
	if ((*lst)->prev == NULL)
	{
		(*lst)->next = new;
		(*lst)->prev = new;
		new->next = (*lst);
		new->prev = (*lst);
		*lst = new;
		return ;
	}
	(*new).next = *lst;
	(*new).prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	*lst = new;
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	last = (*lst)->prev;
	if (last == NULL)
	{
		(*lst)->next = new;
		(*lst)->prev = new;
		new->next = (*lst);
		new->prev = (*lst);
		return ;
	}
	last->next = new;
	(*lst)->prev = new;
	new->prev = last;
	new->next = (*lst);
}

int	ft_stacksize(t_stack *lst)
{
	int		size;
	t_stack	*first;

	if (lst == NULL)
		return (0);
	first = lst;
	size = 1;
	if (lst->next == NULL)
		return (size);
	while (lst->next != first)
	{
		size++;
		lst = (*lst).next;
	}
	return (size);
}
