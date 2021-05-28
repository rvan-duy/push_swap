/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_medium.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:46:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/28 14:00:04 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "calculations.h"
#include "operations.h"
#include "node.h"
#include "libft.h"
#include "utilities.h"
#include "structs.h"
#include <stdio.h>

// static void	median_split(t_data *data)
// {
// 	while (data->stack_a_len > data->median_index)
// 	{
// 		if (data->stack_a->index >= data->median_index)
// 		{
// 			ps_operation_push(&data->stack_b, &data->stack_a, "pb");
// 			data->stack_a_len--;
// 			data->stack_b_len++;
// 		}
// 		else
// 			ps_calculate_rotate_median(&data->stack_a, data->stack_a_len, \
// 			data->median_index);
// 	}
// }

// void	ps_calculate_medium(t_data *data)
// {
// 	median_split(data);
// 	return ;
// }

void	ps_calculate_medium(t_data *data)
{
	size_t	max_index;
	size_t	max_bits;
	size_t	i;
	size_t	j;

	max_index = data->total_len - 1;
	max_bits = 0;
	i = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < data->total_len)
		{
			if (((data->stack_a->index >> i) & 1) == 1)
				ps_operation_rotate(&data->stack_a, "ra");
			else
				ps_operation_push(&data->stack_b, &data->stack_a, "pb");
			j++;
		}
		while (data->stack_b != NULL)
			ps_operation_push(&data->stack_a, &data->stack_b, "pa");
		i++;
	}
}
