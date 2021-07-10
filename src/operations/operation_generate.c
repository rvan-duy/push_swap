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

#include "calculations.h"

void	operation_generate(t_data *data)
{
	if (data->total_len == 2)
		calculate_extra_small(&data->stack_a);
	else if (data->total_len == 3)
		calculate_small(&data->stack_a);
	else if (data->total_len >= 4 && data->total_len <= 499)
		calculate_medium(data);
	else if (data->total_len >= 500)
		calculate_huge(data);
}
