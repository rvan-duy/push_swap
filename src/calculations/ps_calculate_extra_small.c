/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_extra_small.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 12:05:15 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/25 12:08:31 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "calculations.h"
#include "libft.h"

void	ps_calculate_extra_small(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (tmp->index == 1)
		ft_putendl_fd("sa", 1);
}
