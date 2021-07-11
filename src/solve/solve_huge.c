/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:46:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/30 13:40:50 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/**
 * My implementation of the Radix sort algorithm,
 * the implementation looks at the binary of the index of the numbers
 * this algorithm is only really efficient enough for huge stacks
 */

void	solve_huge(t_data *data)
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
				operation_rotate(&data->stack_a, "ra");
			else
				operation_push(&data->stack_b, &data->stack_a, "pb");
			j++;
		}
		while (data->stack_b != NULL)
			operation_push(&data->stack_a, &data->stack_b, "pa");
		i++;
	}
}
