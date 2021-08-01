/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_utils_1.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 11:49:25 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/30 16:50:06 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include "operations.h"
#include "node.h"

size_t	find_lowest_index_of_stack(t_node **head)
{
	size_t	lowest_index;
	t_node	*tmp_head;

	tmp_head = *head;
	lowest_index = tmp_head->index;
	while (tmp_head)
	{
		if (lowest_index > tmp_head->index)
			lowest_index = tmp_head->index;
		tmp_head = tmp_head->next;
	}
	return (lowest_index);
}

size_t	find_highest_index_of_stack(t_node **head)
{
	size_t	highest_index;
	t_node	*tmp_head;

	tmp_head = *head;
	highest_index = tmp_head->index;
	while (tmp_head)
	{
		if (highest_index < tmp_head->index)
			highest_index = tmp_head->index;
		tmp_head = tmp_head->next;
	}
	return (highest_index);
}

int	calculate_fastest_route_to_index(t_node **stack, size_t index, \
										size_t stack_len)
{
	size_t	i;
	t_node	*first_node_tmp;
	t_node	*last_node_tmp;

	i = 0;
	first_node_tmp = (*stack);
	last_node_tmp = node_get_last(stack);
	while (i < (stack_len / 2) + 1)
	{
		if (first_node_tmp->index == index)
			return (ROTATE);
		if (last_node_tmp->index == index)
			return (REV_ROTATE);
		first_node_tmp = first_node_tmp->next;
		last_node_tmp = last_node_tmp->prev;
	}
	return (ROTATE);
}

void	rotate_a_to_index(t_node **stack_a, size_t index, size_t stack_len)
{
	const int	operation = calculate_fastest_route_to_index(stack_a, \
													index, stack_len);

	if (operation == ROTATE)
	{
		while ((*stack_a)->index != index)
			operation_rotate(stack_a, "ra");
	}
	else if (operation == REV_ROTATE)
	{
		while ((*stack_a)->index != index)
			operation_rev_rotate(stack_a, "rra");
	}
}

void	push_top_b_to_a(t_data *data)
{
	operation_push(&data->stack_a, &data->stack_b, "pa");
	data->stack_a_len++;
	data->stack_b_len--;
}
