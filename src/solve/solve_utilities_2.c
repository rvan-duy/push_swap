/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_utilities_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 10:56:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/01 12:08:41 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int	check_index_order(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	while (tmp->next != NULL && tmp->index == tmp->next->index - 1)
		tmp = tmp->next;
	if (tmp->next != NULL)
	{
		if (tmp->next->index != 0)
			return (NOT_ORDERED);
	}
	tmp = tmp->next;
	while (tmp->next != NULL && tmp->index == tmp->next->index - 1)
		tmp = tmp->next;
	if (tmp->next != NULL)
		return (NOT_ORDERED);
	return (ORDERED);
}
