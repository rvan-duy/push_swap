/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 13:58:31 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/06/30 16:04:38 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"
#include "utilities.h"
#include <stdio.h>

// eerst voorsoorteren met groepen, zodat we niet 50x hoeven te roteren
// dan kan je steeds per groep shit doen ofzo
// kleine groepen bovenaan zetten
// 500 / 49
// eerste 3 groepen vormen
// dan die groepen steeds uitsplitesen

// Assigns index value to sorted list
static void	index_assign(t_node **sorted)
{
	size_t	i;
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
	size_t	i;

	if (str[0] == '\0')
		error();
	i = 0;
	digit_found = 0;
	while (str[i] && digit_found == 0)
	{
		if (ft_isdigit(str[i]))
			digit_found = 1;
		i++;
	}
	if (digit_found == 0)
		error();
	numbers = ft_split(str, ' ');
	if (!numbers)
		error();
	return (numbers);
}

/**
 * Initializes the main data structure based on the argv input
 * The values are stored inside the main stack_a
 * But also in a sorted stack, which is then used to assign an index
 * to the stack_a values
 */
static void	stack_ab_init(t_data *data, int32_t argc, char **argv)
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
			number = atoi(numbers[i - 1]);
			if (data->stack_a)
				stack_dup_check(number, &data->stack_a);
			node_front_add(&data->stack_a, node_new(number));
			node_sortedstack_add(&data->sorted, node_new(number));
			i--;
		}
		ft_array_free((void **)numbers, ft_array_len((void **)numbers));
		argc--;
	}
	index_assign(&data->sorted);
	index_read(&data->sorted, &data->stack_a);
}

void	init(t_data *data, int argc, char **argv)
{
	ft_bzero(data, sizeof(t_data));
	stack_ab_init(data, argc, argv);
	data->total_len = node_len(&data->stack_a);
	data->max_index = data->total_len - 1;
	data->stack_a_len = data->total_len;
	data->stack_b_len = 0;
}
