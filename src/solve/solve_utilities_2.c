/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_utilities_2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/14 10:56:30 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/14 11:01:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"

int	check_index_order(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack)->next;
	while (tmp != NULL && tmp->index > tmp->prev->index)
		tmp = tmp->next;
	if (tmp->index != 0)
		return (NOT_ORDERED);
	tmp = tmp->next;
	while (tmp != NULL && tmp->index > tmp->prev->index)
		tmp = tmp->next;
	if (tmp == NULL)
		return (ORDERED);
	return (NOT_ORDERED);
}
