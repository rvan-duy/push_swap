/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_unlink.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:02:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/10 18:40:39 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <stdio.h>

t_node	*node_unlink(t_node	**head, t_node *node)
{
	if (!node->prev && node->next)
	{
		*head = node->next;
		(*head)->prev = NULL;
	}
	else if (node->prev && node->next)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else if (node->prev && !node->next)
		node->prev->next = NULL;
	else
		*head = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
