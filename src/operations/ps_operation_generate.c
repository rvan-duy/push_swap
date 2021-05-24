/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_generate.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 13:07:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 17:15:09 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "calculations.h"
#include "libft.h"

void	ps_operation_generate(t_data *data)
{
	// not correct yet, what if 1 2
	if (data->total_len == 2)
		ps_calculate_extra_small(&data->stack_a);
	else if (data->total_len == 3)
		ps_calculate_small(&data->stack_a);
}
