/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_sortedstack_add.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 14:38:08 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 14:38:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

// Adds a node to the sorted list in the correct position
void	ps_node_sortedstack_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	tmp = *head;
	if (!tmp)
		ps_node_back_add(head, new);
	while (tmp)
	{
		if (tmp && tmp->next)
		{
			if (tmp->value < new->value && tmp->next->value > new->value)
			{
				ps_node_inbetween_add(tmp, tmp->next, new);
				return ;
			}
		}
		else if (tmp && !tmp->next)
		{
			if (tmp->value < new->value)
				ps_node_back_add(head, new);
			else
				ps_node_front_add(head, new);
			return ;
		}
		tmp = tmp->next;
	}
}
