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

void	operation_generate(t_data *data)
{
	if (data->total_len == 2)
		solve_extra_small(&data->stack_a);
	else if (data->total_len == 3)
		solve_small(&data->stack_a);
	else if (check_index_order(&data->stack_a) == ORDERED)
		rotate_a_to_index(&data->stack_a, 0, data->stack_a_len);
	else if (data->total_len >= 4 && data->total_len <= 10)
		solve_medium(data);
	else if (data->total_len >= 11)
		solve_huge(data);
}
