#include "push_swap.h"

void	align_a(t_stack **stack_a, t_cmds **align)
{
	t_stack	*smallest;
	int		n;
	int		res;

	smallest = *stack_a;
	while (smallest->index != 0)
		smallest = smallest->next;
	n = commands_to_top(*stack_a, smallest, &res);
	if (res == 1 || res == 3)
	{
		while (--n >= 0)
		{
			ft_cmdadd_back(align, ft_cmdnew("ra"));
			rotate(stack_a);
		}
	}
	else
	{
		while (--n >= 0)
		{
			ft_cmdadd_back(align, ft_cmdnew("rra"));
			reverse_rotate(stack_a);
		}
	}
}

int	swap_is_needed(t_stack *stack_a, t_markup_params *m_params,
						int (*ft_markup)(t_stack *, t_markup_params *))
{
	int		new_sequence;
	int		old_sequence;

	old_sequence = m_params->sequence_len;
	swap(&stack_a);
	new_sequence = ft_markup(m_params->head, m_params);
	swap(&stack_a);
	ft_markup(m_params->head, m_params);
	if (new_sequence > old_sequence)
		return (1);
	else
		return (0);
}

int	stack_has_false(t_stack *stack_a)
{
	t_stack	*first;

	first = stack_a;
	if (stack_a->keep_in_stack == 0)
		return (1);
	stack_a = stack_a->next;
	while (stack_a != first)
	{
		if (stack_a->keep_in_stack == 0)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

t_cmds	*from_a_to_b(t_stack **stack_a, t_stack **stack_b,
						t_markup_params m_params,
						int (*ft_markup)(t_stack *, t_markup_params *))
{
	t_cmds	*ab;

	ab = NULL;
	while (stack_has_false(*stack_a))
	{
		if (swap_is_needed(*stack_a, &m_params, ft_markup))
		{
			swap(stack_a);
			ft_markup(m_params.head, &m_params);
			ft_cmdadd_back(&ab, ft_cmdnew("sa"));
		}
		else if ((*stack_a)->keep_in_stack == 0)
		{
			push(stack_a, stack_b);
			ft_cmdadd_back(&ab, ft_cmdnew("pb"));
		}
		else
		{
			rotate(stack_a);
			ft_cmdadd_back(&ab, ft_cmdnew("ra"));
		}
	}
	return (ab);
}
