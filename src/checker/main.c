/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:07:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/18 17:47:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <stdio.h>

// REDO THIS
// pa: first elem of b to top of a || nothing if b is NULL
// pb: first elem of a to top of b || nothing if a is NULL
// ra: all elems in a go 1 up, first becomes last one
// rb: all elems in b go 1 up, first becomes last one
// rr: ra and rb at the same time
// rra: all elems in a go 1 down, last becomes first one
// rrb: all elems in b go 1 down, last becomes first one
/// rrr: rra and rrb at the same time
static void	ps_operation_read(char *line, t_data *data)
{
	if (!ft_strncmp(line, "sa", 3))
		ps_operation_switch(&data->stack_a);
	else if (!ft_strncmp(line, "sb", 3))
		ps_operation_switch(&data->stack_b);
	else if (!ft_strncmp(line, "ss", 3))
		ps_operation_switch_both(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "pa", 3))
		ps_operation_push(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "pb", 3))
		ps_operation_push(&data->stack_b, &data->stack_a);
	else if (!ft_strncmp(line, "ra", 3))
		ps_operation_rotate(&data->stack_a);
	else if (!ft_strncmp(line, "rb", 3))
		ps_operation_rotate(&data->stack_b);
	else if (!ft_strncmp(line, "rr", 3))
		ps_operation_rotate_both(&data->stack_a, &data->stack_b);
	else if (!ft_strncmp(line, "rra", 4))
		ps_operation_reverse_rotate(&data->stack_a);
	else if (!ft_strncmp(line, "rrb", 4))
		ps_operation_reverse_rotate(&data->stack_b);
	else if (!ft_strncmp(line, "rrr", 4))
		printf("rrr\n");
	else if (ft_strncmp(line, "\0", 2))
		ps_error();
	printf("a:\n");
	ps_stack_print(&data->stack_a);
	printf("b:\n");
	ps_stack_print(&data->stack_b);
}

// TODO:
// count argc -> read argv into linked lists
// start loop (until EOF is reached)
//		read instruction -> check if its valid
//		if it is, execute instruction
// end loop
// check if list is sorted
//		-> return OK
//		-> else return KO
int	main(int32_t argc, char **argv)
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
			ps_operation_read(line, &data);
			free(line);
		}
		printf("a:\n");
		ps_stack_print(&data.stack_a);
		printf("b:\n");
		ps_stack_print(&data.stack_b);
		ps_sorted_check(&data.stack_a);
		ft_putendl_fd("[OK]", 1);
	}
	return (1);
}
