/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:11:04 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/20 16:30:25 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "node.h"
#include <stdio.h>

int32_t	main(int32_t argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		ps_init(&data, argc, argv);
		printf("len:%ld\n", data.total_len);
	}
	return (1);
}
