/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_small.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:16:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/30 18:03:57 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * Calculates the least amount of operations for a small amount of numbers (3).
 * These solutions are hard coded
 */

void	ps_calculate_small(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->next->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		ps_operation_rotate(stack, "ra");
	else if ((*stack)->value > (*stack)->next->value)
	{
		ps_operation_swap(stack, "sa");
		if ((*stack)->value > (*stack)->next->next->value)
			ps_operation_rev_rotate(stack, "rra");
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		ps_operation_swap(stack, "sa");
		ps_operation_rotate(stack, "ra");
	}
	else if ((*stack)->next->next->value < (*stack)->value)
		ps_operation_rev_rotate(stack, "rra");
}
