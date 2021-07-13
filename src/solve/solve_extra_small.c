/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_extra_small.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 12:05:15 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/28 16:28:07 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

// Just swaps stack_a, idk what else to tell you ¯\_(ツ)_/¯

void	solve_extra_small(t_node **stack_a)
{
	if ((*stack_a)->index == 1)
		operation_swap(stack_a, "sa");
}
