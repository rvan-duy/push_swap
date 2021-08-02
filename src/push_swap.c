/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:11:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/01 19:47:02 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "utilities.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		init(&data, argc, argv);
		if (data.stack_a_len > 1)
			operation_generate(&data);
		free_list(data.stack_a);
		free_list(data.sorted);
	}
	return (EXIT_SUCCESS);
}
