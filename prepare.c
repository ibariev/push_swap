#include "push_swap.h"

void	equalize(int *res_a, int *res_b, t_move *info)
{
	if (*res_a == 3 && *res_b != 3)
		*res_a = *res_b;
	else if (*res_b == 3 && *res_a != 3)
		*res_b = *res_a;
	else
	{
		*res_a = 1;
		*res_b = 1;
	}
	info->res_a = *res_a;
	info->res_b = *res_b;
}

void	move_both(t_stack **stack_a, t_stack **stack_b,
							t_cmds **ba, t_move *info)
{
	while (info->n_a && info->n_b)
	{
		if (info->res_a == 1)
		{
			ft_cmdadd_back(ba, ft_cmdnew("rr"));
			rotate(stack_a);
			rotate(stack_b);
		}
		else
		{
			ft_cmdadd_back(ba, ft_cmdnew("rrr"));
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
		}
		(info->n_a)--;
		(info->n_b)--;
	}
}

void	move_a(t_stack **stack_a, t_cmds **ba, t_move *info)
{
	while (info->n_a)
	{
		if (info->res_a == 1)
		{
			ft_cmdadd_back(ba, ft_cmdnew("ra"));
			rotate(stack_a);
		}
		else
		{
			ft_cmdadd_back(ba, ft_cmdnew("rra"));
			reverse_rotate(stack_a);
		}
		(info->n_a)--;
	}
}

void	move_b(t_stack **stack_b, t_cmds **ba, t_move *info)
{
	while (info->n_b)
	{
		if (info->res_b == 1)
		{
			ft_cmdadd_back(ba, ft_cmdnew("rb"));
			rotate(stack_b);
		}
		else
		{
			ft_cmdadd_back(ba, ft_cmdnew("rrb"));
			reverse_rotate(stack_b);
		}
		(info->n_b)--;
	}
}

void	prepare_stacks(t_stack **stack_a, t_stack **stack_b, t_cmds **ba,
							t_stack *min_elem)
{
	int		res_a;
	int		res_b;
	t_move	info;

	info.n_a = commands_to_top(*stack_a, find_suit(min_elem, *stack_a), &res_a);
	info.n_b = commands_to_top(*stack_b, min_elem, &res_b);
	info.res_a = res_a;
	info.res_b = res_b;
	if (res_a == 3 || res_b == 3)
	{
		equalize(&res_a, &res_b, &info);
		move_both(stack_a, stack_b, ba, &info);
	}
	else if (res_a == res_b)
		move_both(stack_a, stack_b, ba, &info);
	move_a(stack_a, ba, &info);
	move_b(stack_b, ba, &info);
}
