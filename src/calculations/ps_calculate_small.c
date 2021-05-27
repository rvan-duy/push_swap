/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_small.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:16:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 11:25:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * Calculates the least amount of operations for a small amount of numbers (3).
 * These solutions are hard coded
 */
void	ps_calculate_small(t_node **stack_a)
{
	if ((*stack_a)->index == 0 && (*stack_a)->next->index == 2)
	{
		ps_operation_rev_rotate(stack_a, "rra");
		ps_operation_swap(stack_a, "sa");
	}
	else if ((*stack_a)->index == 1)
	{
		if ((*stack_a)->next->index == 0)
			ps_operation_swap(stack_a, "sa");
		else
			ps_operation_rev_rotate(stack_a, "rra");
	}
	else if ((*stack_a)->index == 2)
	{
		if ((*stack_a)->next->index == 0)
			ps_operation_swap(stack_a, "ra");
		else
		{
			ps_operation_rotate(stack_a, "ra");
			ps_operation_swap(stack_a, "sa");
		}
	}
}
