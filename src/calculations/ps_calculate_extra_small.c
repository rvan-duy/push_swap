/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_extra_small.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 12:05:15 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 11:24:15 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ps_calculate_extra_small(t_node **stack_a)
{
	if ((*stack_a)->index == 1)
		ps_operation_swap(stack_a, "sa");
}
