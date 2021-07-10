/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 13:14:10 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/02 00:15:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "utilities.h"
#include "libft.h"

/**
 * Checks if number already exits in the list
 * If it does, it errors the program
 */
void	ps_stack_dup_check(int32_t number, t_node **head)
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

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		ft_free(&tmp);
	}
}
