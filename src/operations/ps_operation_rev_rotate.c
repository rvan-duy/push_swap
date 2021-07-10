/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_operation_rev_rotate.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/19 13:24:58 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/05/27 11:09:43 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "node.h"
#include "libft.h"

/**
 * Reverse rotates a list, 
 * the last node becomes the first one
 */
void	ps_operation_rev_rotate(t_node **head, char *msg)
{
	t_node	*tmp_1;
	t_node	*tmp_2;

	if (!*head || !(*head)->next)
		return ;
	// ps_node_printf(head);
	tmp_1 = ps_node_last_get(head);
	tmp_2 = ps_node_unlink(head, tmp_1);
	ps_node_front_add(head, tmp_2);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}

/**
 * Reverse rotates two lists,
 * the last node becomes the first one
 */
void	ps_operation_rev_rotate_both(t_node **head1, t_node **head2, char *msg)
{
	ps_operation_rev_rotate(head1, NULL);
	ps_operation_rev_rotate(head2, NULL);
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
}
