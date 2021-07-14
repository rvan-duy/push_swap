/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_medium.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 13:50:03 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 18:20:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "solve.h"
#include "node.h"

static void	push_all_except_3_to_b(t_data *data)
{
	while (data->stack_a_len > 3)
	{
		operation_push(&data->stack_b, &data->stack_a, "pb");
		data->stack_a_len--;
		data->stack_b_len++;
	}
}

static size_t	find_middle_index(t_data *data)
{
	t_node	*tmp;
	t_node	*tmp_last_node;

	tmp = data->stack_a->next;
	tmp_last_node = node_get_last(&data->stack_a);
	if (tmp->prev->index > data->stack_b->index
		&& tmp_last_node->index < data->stack_b->index)
		return (tmp->prev->index);
	while (tmp->next)
	{
		if (tmp->prev->index < data->stack_b->index
			&& tmp->index > data->stack_b->index)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (tmp->index);
}

static void	insert_all_back_to_a(t_data *data)
{
	size_t	lowest_index;
	size_t	highest_index;
	size_t	middle_index;

	while (data->stack_b_len > 0)
	{
		lowest_index = find_lowest_index_of_stack(&data->stack_a);
		highest_index = find_highest_index_of_stack(&data->stack_a);
		if (data->stack_b->index < lowest_index
			|| data->stack_b->index > highest_index)
		{
			if (data->stack_a->index != lowest_index)
				rotate_a_to_index(&data->stack_a, lowest_index, \
										data->stack_a_len);
		}
		else
		{
			middle_index = find_middle_index(data);
			if (middle_index != data->stack_a->index)
				rotate_a_to_index(&data->stack_a, middle_index, \
									data->stack_a_len);
		}
		push_top_b_to_a(data);
	}
}

void	solve_medium(t_data *data)
{
	push_all_except_3_to_b(data);
	if (check_index_order(&data->stack_a) == NOT_ORDERED)
		solve_small(&data->stack_a);
	insert_all_back_to_a(data);
	if (data->stack_a->index != SOLVED)
		rotate_a_to_index(&data->stack_a, 0, data->stack_a_len);
}
