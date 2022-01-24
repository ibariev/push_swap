#include "push_swap.h"

t_stack	*find_suit(t_stack *stack_b, t_stack *stack_a)
{
	int	nbr;

	if (stack_a->prev == NULL)
		return (stack_a);
	nbr = stack_b->number;
	while (!(nbr < stack_a->number && nbr > stack_a->prev->number)
		&& !(nbr < stack_a->number && stack_a->number < stack_a->prev->number)
		&& !(nbr > stack_a->prev->number && stack_a->number
			< stack_a->prev->number))
		stack_a = stack_a->next;
	return (stack_a);
}

int	min_commmands(int rot, int rev_rot, int *res)
{
	if (rot < rev_rot)
	{
		*res = 1;
		return (rot);
	}
	else if (rot == rev_rot)
	{
		*res = 3;
		return (rot);
	}
	else
	{
		*res = 2;
		return (rev_rot);
	}
}

int	commands_to_top(t_stack *stack, t_stack *current, int *res)
{
	int		rot;
	int		rev_rot;
	t_stack	*top;

	rot = 0;
	rev_rot = 0;
	top = stack;
	while (stack != current)
	{
		rot++;
		stack = stack->next;
	}
	while (top != current)
	{
		rev_rot++;
		top = top->prev;
	}
	return (min_commmands(rot, rev_rot, res));
}

t_stack	*choose_elem(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;
	t_stack	*min_elem;
	int		min;
	int		n;
	int		res;

	top = *stack_b;
	min_elem = *stack_b;
	min = commands_to_top(top, *stack_b, &res)
		+ commands_to_top(*stack_a, find_suit(*stack_b, *stack_a), &res);
	if ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	while (*stack_b != top)
	{
		n = commands_to_top(top, *stack_b, &res)
			+ commands_to_top(*stack_a, find_suit(*stack_b, *stack_a), &res);
		if (n < min)
		{
			min = n;
			min_elem = *stack_b;
		}
		*stack_b = (*stack_b)->next;
	}
	return (min_elem);
}

void	from_b_to_a(t_stack **stack_a, t_stack **stack_b, t_cmds **ba)
{
	t_stack	*min_elem;

	while ((*stack_b) != NULL)
	{
		min_elem = choose_elem(stack_a, stack_b);
		prepare_stacks(stack_a, stack_b, ba, min_elem);
		push(stack_b, stack_a);
		ft_cmdadd_back(ba, ft_cmdnew("pa"));
	}
}
