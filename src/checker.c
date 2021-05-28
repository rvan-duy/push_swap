/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:07:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/28 16:10:35 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "structs.h"
#include "utilities.h"
#include "node.h"
#include "libft.h"
#include <stdio.h>

/**
 * sa: swap the first 2 elements on top of stack_a
 * sb: swap the first 2 elements on top of stack_b
 * ss: sa + sb
 * pa: first elem of stack_b to top of stack_a
 * pb: first elem of stack_a to top of stack_b
 * ra: all elems in stack_a go 1 up, first becomes last one
 * rb: all elems in stack_b go 1 up, first becomes last one
 * rr: ra + rb
 * rra: all elems in a go 1 down, last becomes first one
 * rrb: all elems in b go 1 down, last becomes first one
 * rrr: rra + rrb
 */

static void	ps_operation_exec(char *line, t_data *data)
{
	if (!ft_strncmp(line, "sa", 3))
		ps_operation_swap(&data->stack_a, NULL);
	else if (!ft_strncmp(line, "sb", 3))
		ps_operation_swap(&data->stack_b, NULL);
	else if (!ft_strncmp(line, "ss", 3))
		ps_operation_swap_both(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(line, "pa", 3))
		ps_operation_push(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(line, "pb", 3))
		ps_operation_push(&data->stack_b, &data->stack_a, NULL);
	else if (!ft_strncmp(line, "ra", 3))
		ps_operation_rotate(&data->stack_a, NULL);
	else if (!ft_strncmp(line, "rb", 3))
		ps_operation_rotate(&data->stack_b, NULL);
	else if (!ft_strncmp(line, "rr", 3))
		ps_operation_rotate_both(&data->stack_a, &data->stack_b, NULL);
	else if (!ft_strncmp(line, "rra", 4))
		ps_operation_rev_rotate(&data->stack_a, NULL);
	else if (!ft_strncmp(line, "rrb", 4))
		ps_operation_rev_rotate(&data->stack_b, NULL);
	else if (!ft_strncmp(line, "rrr", 4))
		ps_operation_rev_rotate_both(&data->stack_a, &data->stack_b, NULL);
	else if (ft_strncmp(line, "\0", 2))
		ps_error();
	// printf("a:\n");
	// ps_node_print(&data->stack_a);
	// printf("b:\n");
	// ps_node_print(&data->stack_b);
}

int32_t	main(int32_t argc, char **argv)
{
	int32_t	ret;
	char	*line;
	t_data	data;

	if (argc > 1)
	{
		ps_init(&data, argc, argv);
		ret = 1;
		while (ret > 0)
		{
			ret = get_next_line(0, &line);
			ps_operation_exec(line, &data);
			free(line);
		}
		// printf("a:\n");
		// ps_node_print(&data.stack_a);
		// printf("b:\n");
		// ps_node_print(&data.stack_b);
		ps_sorted_check(&data.stack_a, &data.stack_b);
		ps_putresult(1);
	}
	return (1);
}
