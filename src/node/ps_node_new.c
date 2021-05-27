/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 14:01:32 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 10:45:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "utilities.h"

// Creates new node
t_node	*ps_node_new(int32_t number)
{
	t_node	*node;

	node = ps_calloc(sizeof(t_node));
	node->value = number;
	return (node);
}
