/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 14:04:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 12:52:04 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <stdio.h>

void	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	*ps_calloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
		ps_error();
	return (ptr);
}

void	ps_sorted_check(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int32_t	prev_value;

	tmp = *stack_a;
	prev_value = INT32_MIN;
	while (tmp->next != NULL)
	{
		if (tmp->value < prev_value)
		{
			ft_putendl_fd("[KO]", 1);
			exit(1);
		}
		prev_value = tmp->value;
		tmp = tmp->next;
	}
	if (*stack_b)
	{
		ft_putendl_fd("[KO]", 1);
		exit(1);
	}
}

void	ps_ints_swap(int32_t *a, int32_t *b)
{
	int32_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
