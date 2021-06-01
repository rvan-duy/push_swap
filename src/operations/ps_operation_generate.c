/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_generate.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 13:07:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/01 13:18:00 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "calculations.h"
#include "libft.h"
#include "node.h"
#include <stdio.h>

void	ps_operation_generate(t_data *data)
{
	if (data->total_len == 2)
		ps_calculate_extra_small(&data->stack_a);
	else if (data->total_len == 3)
		ps_calculate_small(&data->stack_a);
	// else if (data->total_len >= 4 && data->total_len <= 25)
	// 	printf("TODO\n");
	// else if (data->total_len >= 26 && data->total_len <= 100)
	// 	printf("TODO\n");
	else if (data->total_len >= 100)
		ps_calculate_huge(data);
}
