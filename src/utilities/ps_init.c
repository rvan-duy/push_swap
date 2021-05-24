/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:58:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 14:57:20 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include <stdio.h>

// Checks if number already exits in the list, if it does it returns error
static void	ps_stack_dup_check(int32_t number, t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (number == tmp->value)
			ps_error();
		tmp = tmp->next;
	}
}

// Assigns index value to sorted list
static void	ps_stack_index_assign(t_node **sorted)
{
	int32_t	i;
	t_node	*tmp_sorted;

	tmp_sorted = *sorted;
	i = 0;
	while (tmp_sorted)
	{
		tmp_sorted->index = i;
		i++;
		tmp_sorted = tmp_sorted->next;
	}
}

/* Reads the index value from the sorted lists,
 * which is then assigned to the corresponding node in stack_a
 */
static void	ps_stack_index_read(t_node **sorted, t_node **stack_a)
{
	t_node	*tmp_sorted;
	t_node	*tmp_stack_a;

	tmp_stack_a = *stack_a;
	while (tmp_stack_a)
	{
		tmp_sorted = *sorted;
		while (tmp_sorted)
		{
			if (tmp_stack_a->value == tmp_sorted->value)
			{
				tmp_stack_a->index = tmp_sorted->index;
				tmp_sorted = NULL;
			}
			else
				tmp_sorted = tmp_sorted->next;
		}
		tmp_stack_a = tmp_stack_a->next;
	}
}

static void	ps_stack_ab_init(t_data *data, int32_t argc, char **argv)
{
	int32_t	number;

	while (argc > 1)
	{
		number = ps_atoi(argv[argc - 1]);
		if (data->stack_a)
			ps_stack_dup_check(number, &data->stack_a);
		ps_node_front_add(&data->stack_a, ps_node_new(number));
		ps_node_sortedstack_add(&data->sorted, ps_node_new(number));
		argc--;
	}
	ps_stack_index_assign(&data->sorted);
	ps_stack_index_read(&data->sorted, &data->stack_a);
	// printf("stack_a\n");
	// ps_node_print(&data->stack_a);
	// printf("sorted\n");
	// ps_node_print(&data->sorted);
}

void	ps_init(t_data *data, int argc, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	ps_stack_ab_init(data, argc, argv);
	data->total_len = ps_node_len(&data->stack_a);
}
