/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:07:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/14 18:51:47 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <stdio.h>

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
	t_data	*data;

	ps_init(data, argc, argv);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
	}
	if (data->stack_a->value)
		printf("yas\n");
	ps_sorted_check(&data->stack_a);
	return (1);
}
