/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_generate.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 13:07:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 14:20:42 by rvan-duy      ########   odam.nl         */
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
	if (data->total_len == 3)
		ps_calculate_small(&data->stack_a);
	if (data->total_len >= 4)
		ps_calculate_medium(data);
	printf("a:\n");
	ps_node_print(&data->stack_a);
	printf("b:\n");
	ps_node_print(&data->stack_b);
}
