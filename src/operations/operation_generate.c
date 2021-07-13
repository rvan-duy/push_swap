/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operation_generate.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 13:07:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 19:34:49 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solve.h"
#include <stdbool.h>

static bool	check_if_index_is_ordered(t_node **stack_a)
{
	t_node	*tmp;

	tmp = (*stack_a)->next;
	while (tmp != NULL && tmp->index > tmp->prev->index)
		tmp = tmp->next;
	if (tmp->index != 0)
		return (false);
	tmp = tmp->next;
	while (tmp != NULL && tmp->index > tmp->prev->index)
		tmp = tmp->next;
	if (tmp == NULL)
		return (true);
	return (false);
}

void	operation_generate(t_data *data)
{
	if (check_if_index_is_ordered(&data->stack_a) == true)
		rotate_a_to_index(&data->stack_a, 0, data->stack_a_len);
	else if (data->total_len == 2)
		solve_extra_small(&data->stack_a);
	else if (data->total_len == 3)
		solve_small(&data->stack_a);
	else if (data->total_len >= 4 && data->total_len <= 499)
		solve_medium(data);
	else if (data->total_len >= 500)
		solve_huge(data);
}
