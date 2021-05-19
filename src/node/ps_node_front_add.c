/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_front_add.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:03:38 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 14:26:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

// Adds a node to the front of a list
void	ps_node_front_add(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	tmp->prev = new;
	new->next = *head;
	*head = new;
}
