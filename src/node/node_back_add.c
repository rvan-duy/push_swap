/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_back_add.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:02:57 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/24 17:08:54 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

// Adds a node to the back of a list
void	node_back_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = node_last_get(head);
	tmp->next = new;
	new->prev = tmp;
}
