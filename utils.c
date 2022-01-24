#include "push_swap.h"

void	free_all(t_stack *stack_1, t_stack *stack_2, int *arr)
{
	int		i;
	int		size;
	t_stack	*temp;

	size = ft_stacksize(stack_1);
	i = -1;
	while (++i < size)
	{
		temp = stack_1->next;
		free(stack_1);
		stack_1 = temp;
	}
	size = ft_stacksize(stack_2);
	i = -1;
	while (++i < size)
	{
		temp = stack_2->next;
		free(stack_2);
		stack_2 = temp;
	}
	free(arr);
}

void	free_cmd(t_cmds *cmd_list)
{
	t_cmds	*temp;

	while (cmd_list != NULL)
	{
		temp = cmd_list->next;
		free(cmd_list);
		cmd_list = temp;
	}
}

void	print_best(t_cmds *cmd_list_gt, t_cmds *cmd_list_index)
{
	int		size_gt;
	int		size_index;
	t_cmds	*temp;

	size_gt = ft_cmdsize(cmd_list_gt);
	size_index = ft_cmdsize(cmd_list_index);
	if (size_gt < size_index)
	{
		temp = cmd_list_gt;
		while (temp != NULL)
		{
			ft_putendl_fd(temp->cmd, 1);
			temp = temp->next;
		}
	}
	else
	{
		temp = cmd_list_index;
		while (temp != NULL)
		{
			ft_putendl_fd(temp->cmd, 1);
			temp = temp->next;
		}
	}
}
