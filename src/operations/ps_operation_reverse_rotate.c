/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_reverse_rotate.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:24:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/19 14:26:14 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "node.h"

// Reverse rotates a list, 
// the last node becomes the first one
void	ps_operation_reverse_rotate(t_node **head)
{
	t_node	*tmp_1;
	t_node	*tmp_2;

	if (!*head || !(*head)->next)
		return ;
	tmp_1 = ps_node_last_get(head);
	tmp_2 = ps_node_unlink(head, tmp_1);
	ps_node_front_add(head, tmp_2);
}

// Reverse rotates two lists, 
// the last node becomes the first one
void	ps_operation_reverse_rotate_both(t_node **head1, t_node **head2)
{
	ps_operation_reverse_rotate(head1);
	ps_operation_reverse_rotate(head2);
}
