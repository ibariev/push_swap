#include "push_swap.h"

void	swap(t_stack **lst)
{
	t_stack	*first;
	t_stack	*second;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = (*lst)->next;
	if (first->next->next == first)
	{
		*lst = second;
		return ;
	}
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	second->prev->next = second;
	first->next->prev = first;
	*lst = second;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (from == NULL || *from == NULL || to == NULL)
		return ;
	first = *from;
	if (first->next == NULL)
	{
		ft_stackadd_front(to, first);
		*from = NULL;
		return ;
	}
	if (first->next->next == first)
	{
		first->next->next = NULL;
		first->next->prev = NULL;
		*from = first->next;
		ft_stackadd_front(to, first);
		return ;
	}
	first->next->prev = first->prev;
	first->prev->next = first->next;
	*from = first->next;
	ft_stackadd_front(to, first);
}

void	rotate(t_stack **lst)
{
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	*lst = (*lst)->next;
}

void	reverse_rotate(t_stack **lst)
{
	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	*lst = (*lst)->prev;
}
