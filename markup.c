#include "push_swap.h"

int	markup_gt(t_stack *head, t_markup_params *m_params)
{
	int		max;
	int		sequence_len;
	t_stack	*temp;

	head->keep_in_stack = 1;
	max = head->number;
	temp = head->next;
	sequence_len = 1;
	while (temp != head)
	{
		if (temp->number > max)
		{
			sequence_len++;
			max = temp->number;
			temp->keep_in_stack = 1;
		}
		else
			temp->keep_in_stack = 0;
		temp = temp->next;
	}
	m_params->head = head;
	m_params->head_index = head->index;
	m_params->sequence_len = sequence_len;
	return (sequence_len);
}

int	markup_index(t_stack *head, t_markup_params *m_params)
{
	int		cur_index;
	int		sequence_len;
	t_stack	*temp;

	head->keep_in_stack = 1;
	cur_index = head->index;
	temp = head->next;
	sequence_len = 1;
	while (temp != head)
	{
		if (temp->index == cur_index + 1)
		{
			sequence_len++;
			cur_index = temp->index;
			temp->keep_in_stack = 1;
		}
		else
			temp->keep_in_stack = 0;
		temp = temp->next;
	}
	m_params->head = head;
	m_params->head_index = head->index;
	m_params->sequence_len = sequence_len;
	return (sequence_len);
}

void	markup(t_stack *stack_a, int size, t_markup_params *m_params,
					int (*ft_markup)(t_stack *, t_markup_params *))
{
	int		i;
	int		max_sequence;
	int		current_sequence;
	int		index_max;
	t_stack	*head;

	i = 0;
	max_sequence = 0;
	index_max = stack_a->index;
	while (i < size)
	{
		current_sequence = ft_markup(stack_a, m_params);
		if (current_sequence > max_sequence
			|| (current_sequence == max_sequence && stack_a->index < index_max))
		{
			max_sequence = current_sequence;
			head = stack_a;
			index_max = stack_a->index;
		}
		stack_a = stack_a->next;
		i++;
	}
	ft_markup(head, m_params);
}
