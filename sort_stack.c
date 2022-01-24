#include "push_swap.h"

void	fill_index(int *array, t_stack **stack_a, int size)
{
	int		i;
	int		j;
	t_stack	*temp;

	i = 0;
	temp = *stack_a;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (temp->number == array[j])
			{
				temp->index = j;
				break ;
			}
			j++;
		}
		temp = temp->next;
		i++;
	}
}

void	insertion_sort(int *array, int size)
{
	int	i;
	int	k;
	int	temp;

	i = 1;
	while (i < size)
	{
		k = i;
		while (k > 0 && array[k] < array[k - 1])
		{
			temp = array[k];
			array[k] = array[k - 1];
			array[k - 1] = temp;
			k--;
		}
		i++;
	}
}

void	create_stacks(t_stack **stack_1, t_stack **stack_2, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_stackadd_back(stack_1, ft_stacknew(arr[i]));
		ft_stackadd_back(stack_2, ft_stacknew(arr[i]));
		i++;
	}
	insertion_sort(arr, size);
	fill_index(arr, stack_1, size);
	fill_index(arr, stack_2, size);
}

t_cmds	*sort_stack(t_stack **stack_a, int size,
					int (*ft_markup)(t_stack *, t_markup_params *))
{
	t_stack			*stack_b;
	t_cmds			*cmd_list;
	t_markup_params	m_params;

	if (size < 2)
		return (NULL);
	stack_b = NULL;
	markup(*stack_a, size, &m_params, ft_markup);
	cmd_list = from_a_to_b(stack_a, &stack_b, m_params, ft_markup);
	from_b_to_a(stack_a, &stack_b, &cmd_list);
	align_a(stack_a, &cmd_list);
	return (cmd_list);
}
