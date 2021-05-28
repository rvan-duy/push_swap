/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_calculate_utils_1.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/28 11:49:25 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/28 12:24:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "operations.h"
#include "node.h"

static void	apply_rotation(t_node **head, size_t solution, size_t amount)
{
	if (solution == 0)
		return ;
	else if (solution == 1)
	{
		while (amount > 0)
		{
			ps_operation_rotate(head, "ra");
			amount--;
		}
	}
	else if (solution == 2)
	{
		while (amount > 0)
		{
			ps_operation_rev_rotate(head, "rra");
			amount--;
		}
	}
}

void	ps_calculate_rotate_median(t_node **head, size_t len, size_t median)
{
	size_t	i;
	size_t	found_solution;
	t_node	*tmp_1;
	t_node	*tmp_2;

	found_solution = 0;
	i = 0;
	tmp_1 = *head;
	tmp_2 = ps_node_last_get(head);
	while (i < (len / 2) && found_solution == 0)
	{
		if (tmp_1->next->index >= median)
			found_solution = 1;
		else if (tmp_2->index >= median)
			found_solution = 2;
		tmp_1 = tmp_1->next;
		tmp_2 = tmp_2->prev;
		i++;
	}
	apply_rotation(head, found_solution, i);
}
