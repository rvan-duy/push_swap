/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_small.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 15:16:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 15:45:32 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "calculations.h"
#include "libft.h"

/* Calculates the least amount of operations for a small amount of numbers (3).
 * These solutions are hard coded
 */
void	ps_calculate_small(t_node **stack_a)
{
	t_node	*tmp_stack_a;

	tmp_stack_a = *stack_a;
	if (tmp_stack_a->index == 0 && tmp_stack_a->next->index == 2)
	{
		ft_putendl_fd("rra", 1);
		ft_putendl_fd("sa", 1);
	}
	else if (tmp_stack_a->index == 1)
	{
		if (tmp_stack_a->next->index == 0)
			ft_putendl_fd("sa", 1);
		else
			ft_putendl_fd("rra", 1);
	}
	else if (tmp_stack_a->index == 2)
	{
		if (tmp_stack_a->next->index == 0)
			ft_putendl_fd("ra", 1);
		else
		{
			ft_putendl_fd("ra", 1);
			ft_putendl_fd("sa", 1);
		}
	}
}
