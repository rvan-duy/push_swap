/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:11:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 19:03:18 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "utilities.h"
#include "node.h" // remove

int32_t	main(int32_t argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		ps_init(&data, argc, argv);
		ps_operation_generate(&data);
		free_list(data.stack_a);
		free_list(data.sorted);
	}
	return (0);
}
