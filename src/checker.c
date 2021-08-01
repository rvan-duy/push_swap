/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:07:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/08/01 15:46:08 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "structs.h"
#include "utilities.h"
#include "node.h"
#include "libft.h"

static void	operation_exec(char *line, t_data *data)
{
	if (!ft_strncmp(line, "sa", 3))
		operation_swap(&data->stack_a, NULL);
	else if (!ft_strncmp(line, "sb", 3))
		operation_swap(&data->stack_b, NULL);
	else if (!ft_strncmp(line, "ss", 3))
		operation_swap_both(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(line, "pa", 3))
		operation_push(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(line, "pb", 3))
		operation_push(&data->stack_b, &data->stack_a, NULL);
	else if (!ft_strncmp(line, "ra", 3))
		operation_rotate(&data->stack_a, NULL);
	else if (!ft_strncmp(line, "rb", 3))
		operation_rotate(&data->stack_b, NULL);
	else if (!ft_strncmp(line, "rr", 3))
		operation_rotate_both(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(line, "rra", 4))
		operation_rev_rotate(&data->stack_a, NULL);
	else if (!ft_strncmp(line, "rrb", 4))
		operation_rev_rotate(&data->stack_b, NULL);
	else if (!ft_strncmp(line, "rrr", 4))
		operation_rev_rotate_both(&data->stack_a, &data->stack_b, NULL);
	else if (ft_strncmp(line, "\0", 2))
		error();
}

#include <stdio.h>

int32_t	main(int32_t argc, char **argv)
{
	int32_t	ret;
	char	*line;
	t_data	data;

	if (argc > 1)
	{
		init(&data, argc, argv);
		ret = 1;
		while (ret > 0)
		{
			ret = get_next_line(0, &line);
			operation_exec(line, &data);
			ft_free(&line);
		}
		sorted_check(&data.stack_a, &data.stack_b);
		free_list(data.stack_a);
		putresult(OK);
	}
	return (0);
}
