/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_medium.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:46:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 15:26:02 by rvan-duy      ########   odam.nl         */
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
	int i = 0;
	t_node *tmp;
	tmp = data->stack_a;
	while (data->stack_a_len > data->median_index && i < 20)
	{
		printf("segfault?_2\n%ld", tmp->prev->index);
		if (data->stack_a->index >= data->median_index)
		{
			ps_operation_push(&data->stack_b, &data->stack_a, "pb");
			data->stack_a_len--;
			data->stack_b_len++;
		}
		else if (data->stack_a->prev->index >= data->median_index)
		{
			printf("segfault?\n");
			ps_operation_rev_rotate(&data->stack_a, "rra");
		}
		else
			ps_operation_rotate(&data->stack_a, "ra");
		i++;
	}
}

void	ps_calculate_medium(t_data *data)
{
	median_split(data);
	return ;
}
