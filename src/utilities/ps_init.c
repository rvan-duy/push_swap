/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:58:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 13:24:49 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include "utilities.h"
#include <stdio.h>

// Assigns index value to sorted list
static void	index_assign(t_node **sorted)
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

/**
 * Reads the index value from the sorted lists,
 * which is then assigned to the corresponding node in stack_a
 */
static void	index_read(t_node **sorted, t_node **stack_a)
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

/**
 * Checks if str is a valid string as input for the program
 * Errors the program if it is not
 * If it is, it splits the string on spaces and returns a array of strings
 */
static char	**string_split_checks(char *str)
{
	char	**numbers;
	int32_t	digit_found;
	int32_t	i;

	if (str[0] == '\0')
		ps_error();
	i = 0;
	digit_found = 0;
	while (str[i] && digit_found == 0)
	{
		if (ft_isdigit(str[i]))
			digit_found = 1;
		i++;
	}
	if (digit_found == 0)
		ps_error();
	numbers = ft_split(str, ' ');
	if (!numbers)
		ps_error();
	return (numbers);
}

/**
 * Initializes the main data structure based on the argv input
 * The values are stored inside the main stack_a
 * But also in a sorted stack, which is then used to assign an index
 * to the stack_a values
 */
static void	ps_stack_ab_init(t_data *data, int32_t argc, char **argv)
{
	int32_t	number;
	size_t	i;
	char	**numbers;

	while (argc > 1)
	{
		numbers = string_split_checks(argc[argv - 1]);
		i = 0;
		while (numbers[i] != NULL)
			i++;
		while (i > 0)
		{
			number = ps_atoi(numbers[i - 1]);
			if (data->stack_a)
				ps_stack_dup_check(number, &data->stack_a);
			ps_node_front_add(&data->stack_a, ps_node_new(number));
			ps_node_sortedstack_add(&data->sorted, ps_node_new(number));
			i--;
		}
		argc--;
	}
	index_assign(&data->sorted);
	index_read(&data->sorted, &data->stack_a);
}

void	ps_init(t_data *data, int argc, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	ps_stack_ab_init(data, argc, argv);
	data->total_len = ps_node_len(&data->stack_a);
}
