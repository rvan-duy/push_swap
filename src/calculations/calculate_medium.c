/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_medium.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 13:50:03 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 18:20:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "calculations.h"
#include "node.h"
#include <stdio.h>

// Insert number from b -> a
// if index < lowest index weird
// if index > max index weird
// if head index == index + 1 AND tail index == index - 1

static void	rotate_to_correct_index(t_node **stack_a, size_t index)
{
	t_node	*last_node;

	while (1)
	{
		last_node = node_last_get(stack_a);
		if ((*stack_a)->index > index && last_node->index < index)
			return ;
		operation_rotate(stack_a, "ra");
	}
}

// can be optimalized
static void	rotate_to_index(t_node **stack_a, size_t index)
{
	while ((*stack_a)->index != index)
		operation_rotate(stack_a, "ra");
}

static void	insert_all_back_to_a(t_node **stack_a, t_node **stack_b)
{
	size_t	stack_a_lowest_index;
	size_t	stack_a_highest_index;

	while (*stack_b)
	{
		stack_a_lowest_index = find_lowest_index_of_stack(stack_a);
		stack_a_highest_index = find_highest_index_of_stack(stack_a);
		if ((*stack_b)->index < stack_a_lowest_index)
		{
			rotate_to_index(stack_a, stack_a_lowest_index);
			operation_push(stack_a, stack_b, "pa");
		}
		else if ((*stack_b)->index > stack_a_highest_index)
		{
			rotate_to_index(stack_a, stack_a_highest_index);
			operation_push(stack_a, stack_b, "pa");
		}
		else
		{
			rotate_to_correct_index(stack_a, (*stack_b)->index);
			operation_push(stack_a, stack_b, "pa");
		}
	}
}

static void	push_all_except_max_to_b(t_data *data)
{
	while (data->stack_a_len > 3)
	{
		if (data->stack_a->index < data->max_index - 2)
		{
			operation_push(&data->stack_b, &data->stack_a, "pb");
			data->stack_a_len--;
			data->stack_b_len++;
		}
		else
		{
			operation_rotate(&data->stack_a, "ra");
		}
	}
}

void	calculate_medium(t_data *data)
{
	// printf("push_all_except_top_to_b\n");
	// printf("a:\n");
	// node_print(&data->stack_a);
	push_all_except_max_to_b(data);
	// printf("a:\n");
	// node_print(&data->stack_a);
	// printf("b:\n");
	// node_print(&data->stack_b);
	// printf("calculate_small\n");
	calculate_small(&data->stack_a);
	// printf("a:\n");
	// node_print(&data->stack_a);
	// printf("insert_all_back_to_a\n");
	insert_all_back_to_a(&data->stack_a, &data->stack_b);
	// printf("a:\n");
	// node_print(&data->stack_a);
	rotate_to_index(&data->stack_a, 0);
	// printf("a:\n");
	// node_print(&data->stack_a);
}
