/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_node_inbetween_add.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/20 14:18:52 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/20 14:24:17 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

void	ps_node_inbetween_add(t_node *before, t_node *after, t_node *new)
{
	t_node	*tmp_before;
	t_node	*tmp_after;

	tmp_before = before;
	tmp_after = after;
	tmp_before->next = new;
	new->prev = tmp_before;
	tmp_after->prev = new;
	new->next = tmp_after;
}
