/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_medium.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:46:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 17:38:24 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "calculations.h"
#include "operations.h"
#include "node.h"
#include "libft.h"
#include "utilities.h"
#include "structs.h"
#include <stdio.h>

static void	median_split(t_data *data)
{
	while (data->stack_a_len > data->median_index)
	{
		if (data->stack_a->index >= data->median_index)
		{
			ps_operation_push(&data->stack_b, &data->stack_a, "pb");
			data->stack_a_len--;
			data->stack_b_len++;
		}
		else
			ps_operation_rotate(&data->stack_a, "ra");
	}
}

void	ps_calculate_medium(t_data *data)
{
	median_split(data);
	return ;
}
