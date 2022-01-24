#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_gt;
	t_stack	*stack_index;
	t_cmds	*cmd_list_gt;
	t_cmds	*cmd_list_index;
	int		*array;

	stack_gt = NULL;
	stack_index = NULL;
	array = parse(argc, argv);
	create_stacks(&stack_gt, &stack_index, array, argc - 1);
	cmd_list_gt = sort_stack(&stack_gt, argc - 1, markup_gt);
	cmd_list_index = sort_stack(&stack_index, argc - 1, markup_index);
	print_best(cmd_list_gt, cmd_list_index);
	free_all(stack_gt, stack_index, array);
	free_cmd(cmd_list_gt);
	free_cmd(cmd_list_index);
}
