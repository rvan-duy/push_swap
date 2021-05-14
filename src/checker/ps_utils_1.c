/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/14 14:04:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/14 18:44:45 by rvan-duy      ########   odam.nl         */
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

void	*ps_calloc(void *ptr, size_t size)
{
	ptr = ft_calloc(1, size);
	if (!ptr)
		ps_error();
	return (ptr);
}

void	ps_sorted_check(t_node **stack)
{
	t_node	*tmp;
	int32_t	prev;

	printf("[sorted_check]");
	tmp = *stack;
	printf("[sorted_check]\n");
	while (tmp->next != NULL)
	{
		if (!prev)
			ps_error();
		tmp = tmp->next;
	}
}
