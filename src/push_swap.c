/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:11:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 10:47:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "utilities.h"

int32_t	main(int32_t argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		ps_init(&data, argc, argv);
		ps_operation_generate(&data);
	}
	return (1);
}
