#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int					number;
	int					index;
	int					keep_in_stack;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct s_markup_params
{
	t_stack				*head;
	int					head_index;
	int					sequence_len;
}						t_markup_params;

typedef struct s_cmds
{
	char				*cmd;
	struct s_cmds		*next;
}						t_cmds;

typedef struct s_move
{
	int					n_a;
	int					n_b;
	int					res_a;
	int					res_b;
}						t_move;

t_stack	*ft_stacknew(int number);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
int		ft_stacksize(t_stack *lst);
t_cmds	*ft_cmdnew(char *cmd);
t_cmds	*ft_cmdlast(t_cmds *lst);
void	ft_cmdadd_back(t_cmds **lst, t_cmds *new);
int		ft_cmdsize(t_cmds *lst);
void	ft_cmddel_last(t_cmds **lst);
void	swap(t_stack **lst);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **lst);
void	reverse_rotate(t_stack **lst);
int		*parse(int argc, char **argv);
void	create_stacks(t_stack **stack_1, t_stack **stack_2, int *arr, int size);
void	insertion_sort(int *array, int size);
void	fill_index(int *array, t_stack **stack_a, int size);
t_cmds	*sort_stack(t_stack **stack_a, int size,
			int (*ft_markup)(t_stack *, t_markup_params *));
void	markup(t_stack *stack_a, int size, t_markup_params *m_params,
			int (*ft_markup)(t_stack *, t_markup_params *));
int		markup_gt(t_stack *head, t_markup_params *m_params);
int		markup_index(t_stack *head, t_markup_params *m_params);
t_cmds	*from_a_to_b(t_stack **stack_a, t_stack **stack_b,
			t_markup_params m_params,
			int (*ft_markup)(t_stack *, t_markup_params *));
int		stack_has_false(t_stack *stack_a);
int		swap_is_needed(t_stack *stack_a, t_markup_params *m_params,
			int (*ft_markup)(t_stack *, t_markup_params *));
void	from_b_to_a(t_stack **stack_a, t_stack **stack_b, t_cmds **ba);
t_stack	*choose_elem(t_stack **stack_a, t_stack **stack_b);
int		commands_to_top(t_stack *stack, t_stack *current, int *res);
int		min_commmands(int rot, int rev_rot, int *res);
t_stack	*find_suit(t_stack *stack_b, t_stack *stack_a);
void	equalize(int *res_a, int *res_b, t_move *info);
void	move_both(t_stack **stack_a, t_stack **stack_b,
			t_cmds **ba, t_move *info);
void	move_a(t_stack **stack_a, t_cmds **ba, t_move *info);
void	move_b(t_stack **stack_b, t_cmds **ba, t_move *info);
void	prepare_stacks(t_stack **stack_a, t_stack **stack_b, t_cmds **ba,
			t_stack *min_elem);
void	align_a(t_stack **stack_a, t_cmds **align);
t_cmds	*optimize(t_cmds *list);
void	add_list(int len, t_cmds **new, t_cmds **list);
void	free_all(t_stack *stack_1, t_stack *stack_2, int *arr);
void	free_cmd(t_cmds *cmd_list);
void	print_best(t_cmds *cmd_list_gt, t_cmds *cmd_list_index);

#endif